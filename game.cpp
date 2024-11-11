#include <iostream>

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

	// TODO Randomly insert events (2 bat_swarms, 2 bottomless_pits,
	// 1 wumpus, 1 gold, 2 arrows, 1 escape rope) into the board
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
			// at row index i, column index j. TODO If the room contains the
			// player, print an asterisk ("*")

			// TODO else, print a space (" ")

			// The next char indicates the event in the room.
			
			// TODO If debug mode is disabled OR the room at location <i, j>
			// does not have an event, print a space (" ")
			// For example:
			// if (!this->debug || <i, j> ROOM DOES NOT HAVE EVENT) {
			// 	cout << " ";
			// }
			//
			// TODO else, print the room's debug symbol. There are a few ways to
			// do this. You can use polymorphism, or an event could have a
			// char debug_symbol member variable and some sort of
			// get_debug_symbol() member function that you could call here
			// to get the character and print it.

			cout << " ||";
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

bool game::check_win() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has won the game. Return false otherwise.

	cout << "game::check_win() is not implemented..." << endl;
	return false;
}

bool game::check_lose() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has lost the game. Return false otherwise.

	cout << "game::check_lose() is not implemented..." << endl;
	return false;
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
	
	cout << "game::can_move_in_direction is not implemented..." <<
		endl;
	return true;
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

	cout << "game::move_up() is not implemented..." << endl;
}

void game::move_down() {
	// TODO Delete the below placeholder code. Move the player down one
	// space in the grid, however you choose to do that.

	cout << "game::move_down() is not implemented..." << endl;
}

void game::move_left() {
	// TODO Delete the below placeholder code. Move the player left one
	// space in the grid, however you choose to do that.

	cout << "game::move_left() is not implemented..." << endl;
}

void game::move_right() {
	// TODO Delete the below placeholder code. Move the player right one
	// space in the grid, however you choose to do that.

	cout << "game::move_right() is not implemented..." << endl;
}

void game::move(char direction) {
	if (direction == 'w') {
		this->move_up();
	} else if (direction == 'a') {
		this->move_left();
	} else if (direction == 's') {
		this->move_right();
	} else {
		this->move_down();
	}
}

void game::fire_arrow_up() {
	// TODO Delete the below placeholder code. Fire the arrow upward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	cout << "game::fire_arrow_up is not implemented..." << endl;
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
	} else if (direction == 's') {
		this->fire_arrow_right();
	} else {
		this->fire_arrow_down();
	}

	this->num_arrows--;
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

	}
}
