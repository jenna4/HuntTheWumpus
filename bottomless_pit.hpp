#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP
#include "event.hpp"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

class pit : public event {
    public: 

    /*********************************************************************
    ** Function: percept()
    ** Description: displays a percept message, letting the user know a bottomless pit is near by
    ** Parameters: none
    ** Pre-Conditions: pit object must exist
    ** Post-Conditions: prints a message to the terminal 
    *********************************************************************/ 
    void percept();

    /*********************************************************************
    ** Function: encounter(bool&)
    ** Description: simulates encounter with a bottomless pit, displays message to the terminal
    ** Parameters: bool&
    ** Pre-Conditions: a pit object must exist
    ** Post-Conditions: 50% chance of falling into the bit and dying, displays to the terminal what happens
    *********************************************************************/ 
    void encounter(bool&);

    /*********************************************************************
    ** Function: pit()
    ** Description: constuctor for bats class, initializes the pit symbol to "P"
    ** Parameters: none
    ** Pre-Conditions: pit object must exist
    ** Post-Conditions: the symbol for pit is set to "P"
    *********************************************************************/ 
    pit();

    /*********************************************************************
    ** Function: pit& operator=(const pit&)
    ** Description: overload the assignment operator for the pit class
    ** Parameters: const pit&
    ** Pre-Conditions: pit object must exist
    ** Post-Conditions: the current pit object has its symbol is updated to match the assigned pit object.
    *********************************************************************/
    pit& operator=(const pit&);

    /*********************************************************************
    ** Function: pit(const pit&)
    ** Description: copy constructor for the pit class
    ** Parameters: const pit&
    ** Pre-Conditions: an pit object must exist
    ** Post-Conditions: a new pit object is created with the same symbol
    *********************************************************************/ 
    pit(const pit&);

    /*********************************************************************
    ** Function: clone()
    ** Description: creates a new pit object as a copy of the current object
    ** Parameters: none
    ** Pre-Conditions: pit object must exist 
    ** Post-Conditions: returns a pointer to a new pit object
    *********************************************************************/ 
    event* clone();

    /*********************************************************************
    ** Function: get_sym() const
    ** Description: retrieves the symbol representing the pit
    ** Parameters: none
    ** Pre-Conditions:the pit object must exist
    ** Post-Conditions: returns the string symbol of the pit 
    *********************************************************************/ 
    string get_sym() const;
};



#endif
