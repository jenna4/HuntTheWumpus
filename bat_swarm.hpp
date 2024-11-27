#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP
#include <iostream>
#include "event.hpp"
using namespace std;
// TODO Bat Swarm interface (define the bat_swarm class and declare its member
// functions below)
class bats : public event {
    public:

    /*********************************************************************
    ** Function: percept()
    ** Description: displays a percept message, letting the user know bats are near by
    ** Parameters: none
    ** Pre-Conditions: bats object must exist
    ** Post-Conditions: prints a message to the terminal 
    *********************************************************************/ 
    void percept();

    /*********************************************************************
    ** Function: encounter(bool&)
    ** Description: displays a message and sets the confused state to true
    ** Parameters: bool&
    ** Pre-Conditions: bats object must exist
    ** Post-Conditions: displays an encounter message to the terminal and sets confused bool to true
    *********************************************************************/ 
    void encounter(bool&);

    /*********************************************************************
    ** Function: bats()
    ** Description: constuctor for bats class, initializes the bat's symbol to "B"
    ** Parameters: none
    ** Pre-Conditions: bat object must exist
    ** Post-Conditions: the symbol for bats is set to "B"
    *********************************************************************/ 
    bats();

    /*********************************************************************
    ** Function: operator=(const bats&)
    ** Description: assignement operator for bats class, copies the symbol of one bat object to another 
    ** Parameters: const bats&
    ** Pre-Conditions: bat object must exist
    ** Post-Conditions: the symbol of the current object is set to be the same 
    *********************************************************************/ 
    bats& operator=(const bats&);

    /*********************************************************************
    ** Function: bats(const bats&)
    ** Description: copy constructor for bat class, initializes a new bat object as a copy
    ** Parameters: const bats&
    ** Pre-Conditions: bat object must exist 
    ** Post-Conditions: the current object is initialized with the same symbol as the bats object
    *********************************************************************/ 
    bats(const bats&);

    /*********************************************************************
    ** Function: clone()
    ** Description: creates a new bats object as a copy of the current object
    ** Parameters: none
    ** Pre-Conditions: bats object must exist 
    ** Post-Conditions: returns a pointer to a new bats object
    *********************************************************************/ 
    event* clone();

    /*********************************************************************
    ** Function: get_sym()
    ** Description: retrieves the symbol representing the bats
    ** Parameters: none
    ** Pre-Conditions:the bats object must exist
    ** Post-Conditions: returns the string symbol of the bats 
    *********************************************************************/ 
    string get_sym() const;
};


#endif
