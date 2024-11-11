#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.hpp"

using std::cout;
using std::cin;
using std::endl;

/*
 * Function: get_width
 * Description: Prompts the user for the game board width (# of columns)
 * Returns (int): Valid width supplied by user
 */
int get_width() {
	int width;
	bool first = true;
	do {
		if (!first) {
			cout << endl << "Invalid width!" << endl <<
				endl;
		}
		first = false;
		cout << "Enter the game board width between 4 and 30: ";
		cin >> width;
	} while(width < 4 || width > 30);
	return width;
}

/*
 * Function: get_height
 * Description: Prompts the user for the game board height (# of columns)
 * Returns (int): Valid height supplied by user
 */
int get_height() {
	int height;
	bool first = true;
	do {
		if (!first) {
			cout << endl << "Invalid height!" << endl <<
				endl;
		}
		first = false;
		cout << "Enter the game board height between 4 and 30: ";
		cin >> height;
	} while(height < 4 || height > 30);
	return height;
}

/*
 * Function: get_debug
 * Description: Prompts the user whether they want to play in debug mode
 * Returns (bool): True if the user wants to play in debug mode. False
 * 		otherwise.
 */
bool get_debug() {
	int debug_input;
	bool first = true;
	do {
		if (!first) {
			cout << endl << "Invalid input!" << endl <<
				endl;
		}
		first = false;
		cout << "Would you like to play in debug mode? (1-yes, 0-no): ";
		cin >> debug_input;
	} while(debug_input != 0 && debug_input != 1);
	return debug_input == 1;
}

int main()
{
	// Set the random seed
	srand(time(nullptr));
	
	// Ask user for width and height of game board
	int width = get_width();
	int height = get_height();

	// Ask user whether they want debug mode
	bool debug = get_debug();

	// Construct game object
	game g(width, height, debug);

	//Play game
	g.play_game();

	return 0;
}
