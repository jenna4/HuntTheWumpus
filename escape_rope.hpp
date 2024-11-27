#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP
#include <iostream>
#include "event.hpp"
#include <string>
using namespace std;

// TODO Escape rope interface (define the escape_rope class and declare its
// member functions below)
class rope : public event {
    public:

    /*********************************************************************
    ** Function: percept()
    ** Description: empty body for percept
    ** Parameters: none
    ** Pre-Conditions: rope object must exist
    ** Post-Conditions: doesnt print percept
    *********************************************************************/ 
    void percept();

    /*********************************************************************
    ** Function: encounter(bool&)
    ** Description: simulates encounter with escape rope. if player has gold, they can escape and win.
    ** if the player does not have the gold, they cannot escape 
    ** Parameters: bool&
    ** Pre-Conditions: has-gold must be a valid bool
    ** Post-Conditions: if the player has gold, they escape and print you win message, else they dont escape
    *********************************************************************/ 
    void encounter(bool&);

    /*********************************************************************
    ** Function: rope()
    ** Description: constuctor for rope class, initializes the pit symbol to "R"
    ** Parameters: none
    ** Pre-Conditions: rope object must exist
    ** Post-Conditions: the symbol for pit is set to "R"
    *********************************************************************/ 
    rope();

    /*********************************************************************
    ** Function: rope& operator=(const rope&)
    ** Description: overload the assignment operator for the rope class
    ** Parameters: const rope&
    ** Pre-Conditions: rope object must exist
    ** Post-Conditions: the current rope object has its symbol is updated to match the assigned rope object.
    *********************************************************************/
    rope& operator=(const rope&);

    /*********************************************************************
    ** Function: rope(const rope&)
    ** Description: copy constructor for the rope class
    ** Parameters: const rope&
    ** Pre-Conditions: an rope object must exist
    ** Post-Conditions: a new rope object is created with the same symbol
    *********************************************************************/ 
    rope(const rope&);

    /*********************************************************************
    ** Function: clone()
    ** Description: creates a new rope object as a copy of the current object
    ** Parameters: none
    ** Pre-Conditions: rope object must exist 
    ** Post-Conditions: returns a pointer to a new rope object
    *********************************************************************/ 
    event* clone();

    /*********************************************************************
    ** Function: get_sym() const
    ** Description: retrieves the symbol representing the rope
    ** Parameters: none
    ** Pre-Conditions:the rope object must exist
    ** Post-Conditions: returns the string symbol of the rope 
    *********************************************************************/ 
    string get_sym() const;
};


#endif
