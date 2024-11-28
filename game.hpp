#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <iostream>
#include "room.hpp"

// game interface
class game {
private:
	// TODO declare a 2D vector of Room objects:
	vector <vector<Room> > board;

	// Suggested member variables:
	int num_arrows = 0; 	// keep track of number of arrows remaining
	int width;				// width of the game grid
	int height;				// height of the game grid
	bool debug;				// debug mode or not
	bool alive = true;		// if adventuer is alive
	bool bgold = false;		// if adventuer has gold or not
	bool confused = false;
	bool barrow = false;
	bool wumpus_alive = true; 
	bool bwarp = false;
	bool bring = false;
	int num_rings = 0;

	// TODO Feel free to add more member variables if you'd like

public:
	// Suggested functions (there are no required functions here):
	
	/*
	 * Function: Constructor
	 * Description: Constructs game object with a grid matching the given
	 * 		width and height
	 * Parameters:
	 * 		width (int): Width of the grid
	 * 		height (int): Height of the grid
	 * 		debug (bool): Whether or not debug mode should be enabled
	 */
	game(int width, int height, bool debug);

	/*
	 * Function: display_game
	 * Description: Displays the game grid in the terminal
	 */
	void display_game() const;

	/*
	 * Function: check_win
	 * Description: Determines whether the player has won the game
	 * Returns (bool): True if the player has won, false otherwise
	 */
	bool check_win() const;

	/*
	 * Function: check_lose
	 * Description: Determines whether the player has lost the game
	 * Returns (bool): True if the player has lost, false otherwise
	 */
	bool check_lose() const;

	/*
	 * Function: is_direction
	 * Description: Returns true if the given character is a valid direction
	 * 		character (w/a/s/d) and false otherwise
	 * Parameters:
	 * 		c (char): The character to check
	 * Returns (bool): Boolean indicating whether the character is a valid
	 * 		direction character (w/a/s/d)
	 */
	bool is_direction(char c);

	/*
	 * Function: to_lower
	 * Description: Converts a given character to lowercase. Used to standardize
	 * 		a user's character input.
	 * Parameters:
	 * 		direction (char): Character to convert to lowercase
	 * Returns (char): Character converted to lowercase
	 */
	char to_lower(char direction);

	/*
	 * Function: can_move_in_direction
	 * Description: Determines whether the player can move in the given
	 * 		direction, based on their current location and the size of the
	 * 		grid.
	 * Parameters:
	 * 		direction (char): Direction the player wishes to move in
	 * Returns (bool): True if the player can move in the given direction
	 * 		without moving off the grid. False otherwise.
	 */
	bool can_move_in_direction(char direction);

	/*
	 * Function: is_valid_action
	 * Description: Determines whether the given action is valid.
	 * Parameters:
	 * 		action (char): Action the player wishes to perform.
	 * Returns (bool): True if the requested action is valid. False otherwise.
	 */
	bool is_valid_action(char action);

	/*
	 * Function: print_action_error
	 * Description: Prints a clear error message associated with the user's
	 * 		provided invalid action
	 * Parameters:
	 * 		action (char): Invalid action that the user requested
	 */
	void print_action_error(char action);

	/*
	 * Function: get_player_action
	 * Description: Prompts the player for their action for the turn and
	 * 		returns it as a char (w, a, s, d, or f). If the player enters
	 * 		an invalid action, this function reprompts until a valid one is
	 * 		provided.
	 * Returns (char): The valid action provided by the player.
	 */
	char get_player_action();

	/*
	 * Function: get_arrow_fire_direction
	 * Description: Prompts the player for the direction they want to fire an
	 * 		arrow (w, a, s, or d) and returns it as a char. If the player enters
	 * 		an invalid direction, this function reprompts until a valid one is
	 * 		provided.
	 * Returns (char): The valid direction provided by the player.
	 */
	char get_arrow_fire_direction();

	/*
	 * Function: move_up
	 * Description: Moves the player up one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_up();

	/*
	 * Function: move_down
	 * Description: Moves the player down one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_down();

	/*
	 * Function: move_left
	 * Description: Moves the player left one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_left();

	/*
	 * Function: move_right
	 * Description: Moves the player right one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_right();

	/*
	 * Function: move
	 * Description: Moves the player in the direction specified by the given
	 * 		character
	 * Parameters:
	 * 		direction (char): Direction in which to move the player (a for
	 * 			west, s for south, d for east, w for north).
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move(char direction);

	/*
	 * Function: fire_arrow_up
	 * Description: Fires an arrow upward
	 * Post-condition: Arrow is fired upward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_up();

	/*
	 * Function: fire_arrow_down
	 * Description: Fires an arrow downward
	 * Post-condition: Arrow is fired downward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_down();

	/*
	 * Function: fire_arrow_left
	 * Description: Fires an arrow leftward
	 * Post-condition: Arrow is fired leftward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_left();

	/*
	 * Function: fire_arrow_right
	 * Description: Fires an arrow rightward
	 * Post-condition: Arrow is fired rightward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_right();

	/*
	 * Function: fire_arrow
	 * Description: Fires an arrow in the direction specified by the given
	 * 		character
	 * Parameters:
	 * 		direction (char): Direction in which to fire arrow (a for
	 * 			west, s for south, d for east, w for north).
	 * Post-condition: Arrow is fired. Wumpus is killed if hit and moves if
	 * 		missed.
	 */
	void fire_arrow(char direction);

	/*
	 * Function: play_game
	 * Description: Runs one full iteration of the game
	 */
	void play_game();

	// TODO Add more member functions here

	/*********************************************************************
    ** Function: rand_cord(int& x, int& y)
    ** Description: generates random coordinates within bounds of board 
    ** Parameters: int& x, int& y
    ** Pre-Conditions: width and height must be initialized 
    ** Post-Conditions: the x and y variables are assigned random values within the bounds of the board
    *********************************************************************/ 
	void rand_cord(int& x, int& y);

    /*********************************************************************
    ** Function: apply_rope(event* rope)
    ** Description: 
    ** Parameters: event* rope
    ** Pre-Conditions:
    ** Post-Conditions:
    *********************************************************************/ 
	void apply_rope(event* rope);

    /*********************************************************************
    ** Function: insert_adventurer
    ** Description: randomly places the adventurer in an empty room and places the escape rope there too
    ** Parameters: none
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: adventurer is placed randomly in an empty room, the escape rope is placed in the same room
    *********************************************************************/ 
	void insert_adventurer();

    /*********************************************************************
    ** Function: insert_loco(event* e)
    ** Description: randomly places an event in an empty room on the board
    ** Parameters: event* e
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: event is placed in a randomly selected room
    *********************************************************************/ 
	void insert_loco(event* e);

	void warp_player(int&x, int& y);

    /*********************************************************************
    ** Function: insert()
    ** Description: inserts events and the adventurer into random empty rooms
    ** Parameters: none
    ** Pre-Conditions: room object must exist
    ** Post-Conditions: events and adventurer is randomly placed 
    *********************************************************************/ 
	void insert();

    /*********************************************************************
    ** Function: adv_loco(int& x, int& y) const
    ** Description: finds the current location of the adventurer on board and stores the coords
    ** Parameters: int& x, int& y
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: coords are updated with location of adventurer
    *********************************************************************/ 
	void adv_loco(int& x, int& y) const;

    /*********************************************************************
    ** Function: wumpus_loco(int& x, int& y) const
    ** Description: finds the current location of the wumpus on board and stores the coords
    ** Parameters: int& x, int& y
    ** Pre-Conditions: room objects must exist 
    ** Post-Conditions: coords are updated with location of wumpus
    *********************************************************************/ 
	void wumpus_loco(int& x, int& y) const;
	void hidden_passage_loco(int& x1, int& y1, int& x2, int& y2) const;

    /*********************************************************************
    ** Function: move_wumpus()
    ** Description: moves the wumpus to a new, rnadom locatiom on baord after it has been awakened by arrow
    ** Parameters: none
    ** Pre-Conditions: room object must exist
    ** Post-Conditions: wumpus is moved to a new random location, previous room where wumpus was is cleared
    *********************************************************************/ 
	void move_wump();
	// void extramove_wump();

    /*********************************************************************
    ** Function: play()
    ** Description: executes the current turn in the game, processing the adventurer encoutners
    ** Parameters: none
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: the adventurer encounters stuff 
    *********************************************************************/ 
	void play();

    /*********************************************************************
    ** Function: p_percepts()
    ** Description: checks the rooms adjacent to adventurer and displays percepts
    ** Parameters: none 
    ** Pre-Conditions: adventurer's location must be known
    ** Post-Conditions: the percepts of events adjacent to the adventurer are printed to terminal 
    *********************************************************************/ 
	void p_percepts();

};
#endif
