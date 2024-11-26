#include <iostream>
#include <cstdlib>
#include <ctime>

#include "game.hpp"
#include "gold.hpp"
#include "bat_swarm.hpp"
#include "bottomless_pit.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// game implementation

game::game(int width, int height, bool debug) :
		width(width),
		height(height),
		debug(debug) {
	// TODO Create the game board: 2D vector of room objects
	board = vector<vector<Room> >(height, vector<Room>(width));
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			board[i][j] = Room();
		}
	}
	// TODO Randomly insert events (2 bat_swarms, 2 bottomless_pits,
	// 1 wumpus, 1 gold, 2 arrows, 1 escape rope) into the board
	insert();
}

void game::rand_cord(int& x, int& y) {
	x = rand() % this->width;
	y = rand() % this->height;
}

void game::insert_loco(event* e) {
	int x, y;
	//store random coords to assign
	rand_cord(x, y);
	// checks to make sure room at cords is empty
	while(!(this->board[x][y].empty_room())) {
		rand_cord(x, y);
	}
	// assgins the event pointer to new pointer
	this->board[x][y].apply_event(e);
}

void game::insert_adventurer() {
	int x, y;

	//randomcordinates
	rand_cord(x, y);

	//check if room empty at cords
	while(!this->board[x][y].empty_room()) {
		rand_cord(x, y);
	}

	// insert adventurer at the cords and set rope where adventuer is placed
	this->board[x][y].adventurer_status();
	this->board[x][y].apply_event(new rope);
}

//game inserrt function
void game::insert() {
	//inserting events
	insert_loco(new arrow);
	insert_loco(new arrow);
	insert_loco(new pit);
	insert_loco(new pit);
	insert_loco(new bats);
	insert_loco(new bats);
	insert_loco(new gold);
	insert_loco(new wumpus);
	// insert_loco(new rope);

	// inserting adventueuer at start cords
	insert_adventurer();
}



void game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;

	string row_border = "--";
	for (int i = 0; i < this->width; ++i) {
		row_border += "-----";
	}

	cout << row_border << endl;
	for (int i = 0; i < this->height; ++i) {
		cout << "||";
		for (int j = 0; j < this->width; ++j) {
			// The first char indicates whether there is a player in the room
			// at row index i, column index j. 
			if (board[i][j].get_has_adventurer()) {
				cout << "*";
			} else {
			// TODO else, print a space (" ")
				cout << " ";
			}

			// The next char indicates the event in the room.
			
			// TODO If debug mode is disabled OR the room at location <i, j>
			// does not have an event, print a space (" ")
			// For example:
			// if (!this->debug || <i, j> ROOM DOES NOT HAVE EVENT) {
			// 	cout << " ";
			// }
			// if the room does not have an event
			if (board[i][j].empty_room()) {
					cout << "  ||";
			} else {
				//if user choose debug mode
				if(this->debug) {
					//print char of certain event
					board[i][j].print_event_sym();
				} else {
					cout << " ";
				}
				cout << " ||";

			}
			//
			// TODO else, print the room's debug symbol. There are a few ways to
			// do this. You can use polymorphism, or an event could have a
			// char debug_symbol member variable and some sort of
			// get_debug_symbol() member function that you could call here
			// to get the character and print it.

		}
		cout << endl;
	cout << row_border << endl;
	}

	//example output (when finished): 
	// ----------------------
	// || P || G || P ||   ||
	// ----------------------
	// ||   || W ||   || S ||
	// ----------------------   
	// ||   ||   ||   || S ||
	// ----------------------   
	// ||*  ||   ||   ||   ||
	// ----------------------
}

void game::adv_loco(int& x, int& y) const {
	//go through rooms of vector
	for (int i = 0; i < this->width; i++) {
		for(int j = 0; j < this->height; j++) {
			// if room has adventurer
			if (this->board[i][j].get_has_adventurer()) {
				// store and return cords
				x = i;
				y = j;
				return;
			}
		}
	}
}

void game::wumpus_loco(int& x, int& y) const {
	for (int i = 0; i < this->width; i++) {
		for(int j = 0; j < this->height; j++) {
			// if room is not empty
			if (!this->board[i][j].empty_room()) {
				// if wumpus is event in room
				if(this->board[i][j].get_event_sym() == "W") {
					x = i;
					y = j;
					return;
				}
			}
		}
	}
}

bool game::check_win() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has won the game. Return false otherwise.
 if (alive) {
	if (this->bgold) {
		int x, y;

		// func to find adventurer
		adv_loco(x, y);

		// if adventuer in a room with the rope, adventuer escapes and wins
		if(!board[x][y].empty_room() && board[x][y].get_event_sym() == "R") {
			cout << "You escaped with the gold! You win!" << endl;
			return true;
		}
	}
	if (!this->wumpus_alive) {
		cout << "You win!" << endl;
		return true;
	}

 }
 return false;
}

bool game::check_lose() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has lost the game. Return false otherwise.
	if (!alive) {
		cout << "You died. Game over." << endl;
		return true;
	} 
	return false; // adventuer is still alive
}

bool game::is_direction(char c) {
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

bool game::can_move_in_direction(char direction) {
	// TODO Delete the below placeholder code. Return true if the player can
	// move in the given direction ('w' for up, 'a' for left, 's' for down,
	// 'd' for right). Return false otherwise. The player can move in the
	// given direction so long as it wouldn't cause them to move off the
	// grid.
	
	int x, y;
	//get adventuer cords
	adv_loco(x, y); 

	int up_x = x;
	int up_y = y;

	//calcualte new position
	if (direction == 'w') {
		up_x -= 1;
	} else if(direction == 'a') {
		up_y -= 1;
	} else if(direction == 's') {
		up_x += 1;
	} else if(direction == 'd') {
		up_y += 1;
	}
	// check if position is within bounds
	return up_x >= 0 && up_x < height && up_y >= 0 && up_y < width; 
}

bool game::is_valid_action(char action) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction);
	} else if (action == 'f') {
		return this->num_arrows > 0;
	}
	return false;
}

void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		cout << "You can't move in that direction!" << endl <<
			endl;
	} else if (action == 'f') {
		cout << "You're out of arrows!" << endl << endl;
	} else {
		cout << endl << "That's an invalid input!" << endl
			<< endl;
	}
}

char game::get_player_action() {
	char action;
	bool first = true;
	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		cout << endl << endl << "What would you like to do?" <<
			endl << endl;
		cout << "w: move up" << endl;
		cout << "a: move left" << endl;
		cout << "s: move down" << endl;
		cout << "d: move right" << endl;
		cout << "f: fire an arrow" << endl;

		cin >> action;
		action = this->to_lower(action);
	} while (!this->is_valid_action(action));

	return action;
}

char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			cout << endl << "That's an invalid input!" <<
				endl << endl;
		}
		first = false;

		cout << endl << endl <<
			"What direction would you like to fire the arrow?" << endl <<
			endl;
		cout << "w: up" << endl;
		cout << "a: left" << endl;
		cout << "s: down" << endl;
		cout << "d: right" << endl;

		cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

void game::move_up() {
	// TODO Delete the below placeholder code. Move the player up one
	// space in the grid, however you choose to do that.
	int x, y;
	// get adventurer location
	adv_loco(x, y);

	// check if can move without going out of bounds
	if (can_move_in_direction('w')) {
		// update adventurer cords
		board[x][y].adventurer_status();
		board[x - 1][y].adventurer_status();
	} else {
		cout << "You cannot move up" << endl;
	}
}

void game::move_down() {
	// TODO Delete the below placeholder code. Move the player down one
	// space in the grid, however you choose to do that.
	int x, y;
	adv_loco(x, y);

	if (can_move_in_direction('s')) {
		board[x][y].adventurer_status();
		board[x + 1][y].adventurer_status();
	} else {
		cout << "You cannot move down" << endl;
	}
}

void game::move_left() {
	// TODO Delete the below placeholder code. Move the player left one
	// space in the grid, however you choose to do that.
	int x, y;
	adv_loco(x, y);

	if (can_move_in_direction('a')) {
		board[x][y].adventurer_status();
		board[x][y - 1].adventurer_status();
	} else {
		cout << "You cannot move left" << endl;
	}

}

void game::move_right() {
	// TODO Delete the below placeholder code. Move the player right one
	// space in the grid, however you choose to do that.
	int x, y;
	adv_loco(x, y);

	if (can_move_in_direction('d')) {
		board[x][y].adventurer_status();
		board[x][y + 1].adventurer_status();
	} else {
		cout << "You cannot move right" << endl;
	}
}

// make an array

void game::move(char direction) {
	char rand_moves[4] = {'w', 'a', 's', 'd'};
	if (this->confused) {
		int rdir = rand() % 4;
		direction = rand_moves[rdir];
		this->confused = false;
	}
	if (direction == 'w') {
		this->move_up();
	} else if (direction == 'a') {
		this->move_left();
	} else if (direction == 'd') {
		this->move_right();
	} else if (direction == 's') {
		this->move_down();
	}
}

void game::move_wump() {
	int x, y;
	cout << "------------------------------------" << endl;
	cout << "The arrow awoke the Wumpus, causing it to move!" << endl;
	cout << "------------------------------------" << endl;
	// locate wumopus
	wumpus_loco(x, y);
	
	// insert wumpus at new loco
	insert_loco(new wumpus);

	// delete room wumpus was in
	this->board[x][y].apply_event(nullptr);
}

void game::fire_arrow_up() {
	// TODO Delete the below placeholder code. Fire the arrow upward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	int x, y;
	adv_loco(x, y);

	for (int i = 1; i <= 3; i++) {
		// if room is nto empty
		int next_x = x - i;
		if (next_x < 0) {
			break; // stop if arrow goes out of bound
		}
		// check if room not emopty
		if(!(this->board[next_x][y].empty_room())) {
			// check if wumpus in room
			if (this->board[next_x][y].get_event_sym() == "W") {
				// removes wumpsu from baord
				this->board[next_x][y].apply_event(nullptr);
				cout << "You hit and killed the Wumpus!" << endl;
				this->wumpus_alive = false;
				// get out the function
				return;
			}
		}
	}
	// if arrow misses
	cout << "Your arrow missed." << endl;
	// move wumpus 
	move_wump();
}

void game::fire_arrow_down() {
	// TODO Delete the below placeholder code. Fire the arrow downward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	cout << "game::fire_arrow_down is not implemented..." << endl;
}

void game::fire_arrow_left() {
	// TODO Delete the below placeholder code. Fire the arrow leftward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	cout << "game::fire_arrow_left is not implemented..." << endl;
}

void game::fire_arrow_right() {
	// TODO Delete the below placeholder code. Fire the arrow rightward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	cout << "game::fire_arrow_right is not implemented..." << endl;
}

void game::fire_arrow(char direction) {
	if (direction == 'w') {
		this->fire_arrow_up();
	} else if (direction == 'a') {
		this->fire_arrow_left();
	} else if (direction == 'd') {
		this->fire_arrow_right();
	} else {
		this->fire_arrow_down();
	}

	this->num_arrows--;
}

void game::p_percepts() {
	int x, y;
	adv_loco(x, y);

	// check if wall to north of the adventurer, makes sure row above exists
	if(x - 1 >= 0) {
		// if room not empty print evnt
		if (!board[x - 1][y].empty_room()) {
			board[x - 1][y].percept();
		}
	}

	// check if wall to the left/west
	if(y + 1 < width) {
		if (!board[x][y + 1].empty_room()) {
			board[x][y + 1].percept();
		}
	}

	// check if wall to the south 
	if (x + 1 < height) {
		if (!board[x + 1][y].empty_room()) {
			board[x + 1][y].percept();
		}
	}

	// check if wall to the right/east
	if (y - 1 >= 0) {
		if (!board[x][y - 1].empty_room()) {
			board[x][y - 1].percept();
		}
	}

}

void game::play() {
	int x, y;
	adv_loco(x, y);

	if (!board[x][y].empty_room()) {
		board[x][y].encounter(alive, bgold, confused, barrow);

		// if adventurer has arrow, delte from board
		if(barrow == true && board[x][y].get_event_sym() == "A") {
			board[x][y].apply_event(nullptr);
			this->num_arrows++;
		}
		// if adventurer picks up gold, delte form board
		if(bgold == true && !board[x][y].empty_room() && board[x][y].get_event_sym() == "G") {
			board[x][y].apply_event(nullptr);
		}
	}

}

void game::play_game(){
	while (!this->check_win() && !this->check_lose()) {
		// Print game board
		this->display_game();

		// TODO Display precepts around player's location

		// Ask player for their action
		char action = this->get_player_action();

		// Process action
		if (this->is_direction(action)) {
			// W/A/S/D = move player
			char direction = action;
			this->move(direction);
		} else {
			// F = prompt for arrow fire direction and fire arrow
			char direction = this->get_arrow_fire_direction();
			this->fire_arrow(direction);
		}
		// TODO If the user is on a space with an event, trigger its encounter
		play();
	}
}
