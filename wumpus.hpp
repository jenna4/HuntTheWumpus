#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include "event.hpp"
#include <iostream>
using namespace std;

class wumpus : public event {
    public:

    /*********************************************************************
    ** Function: percept()
    ** Description: displays message if adventurer is adjacent to room with wumpus 
    ** Parameters: none 
    ** Pre-Conditions: wumpus object must exist 
    ** Post-Conditions: displays message 
    *********************************************************************/ 
    void percept();

    /*********************************************************************
    ** Function: encounter(bool&)
    ** Description: displays message that adventurer awoke the wumpus and got eaten, set the alive bool to false
    ** Parameters: bool&
    ** Pre-Conditions: wumpus object must exist 
    ** Post-Conditions: displays message and sets bool to false
    *********************************************************************/  
    void encounter(bool&);

    /*********************************************************************
    ** Function: wumpus()
    ** Description: constructor for wumpus class, sets symbol to "W"
    ** Parameters: none 
    ** Pre-Conditions: wumpus object must exist 
    ** Post-Conditions: sets symbol to "W"
    *********************************************************************/ 
    wumpus();

    /*********************************************************************
    ** Function: wumpus& operator=(const wumpus&)
    ** Description: overload the assignment operator for the wumpus class
    ** Parameters: const wumpus&
    ** Pre-Conditions: wumpus object must exist
    ** Post-Conditions: the current wumpus object has its symbol is updated to match the assigned wumpus object.
    *********************************************************************/ 
    wumpus& operator=(const wumpus&);

    /*********************************************************************
    ** Function: wumpus(const wumpus&)
    ** Description: copy constructor for the wumpus class
    ** Parameters: const wumpus&
    ** Pre-Conditions: an wumpus object must exist
    ** Post-Conditions: a new wumpus object is created with the same symbol
    *********************************************************************/ 
    wumpus(const wumpus&);

    /*********************************************************************
    ** Function: clone()
    ** Description: creates a new wumpus object as a copy of the current object
    ** Parameters: none
    ** Pre-Conditions: wumpus object must exist 
    ** Post-Conditions: returns a pointer to a new wumpus object
    *********************************************************************/ 
    event* clone();

    /*********************************************************************
    ** Function: get_sym() const
    ** Description: retrieves the symbol representing the wumpus
    ** Parameters: none
    ** Pre-Conditions:the wumpus object must exist
    ** Post-Conditions: returns the string symbol of the wumpus 
    *********************************************************************/ 
    string get_sym() const;
};

#endif
