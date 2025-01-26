#ifndef GOLD_HPP
#define GOLD_HPP
#include "event.hpp"
#include <iostream>
#include <string>
using namespace std;

class gold : public event {
    public:

    /*********************************************************************
    ** Function: percept()
    ** Description: displays message if adventurer is adjacent to room with gold 
    ** Parameters: none 
    ** Pre-Conditions: gold object msut exist 
    ** Post-Conditions: displays message 
    *********************************************************************/ 
    void percept();

    /*********************************************************************
    ** Function: encounter(bool&)
    ** Description: displays message that gold was picked up and set has_gold to true 
    ** Parameters: bool&
    ** Pre-Conditions: gold object must exist 
    ** Post-Conditions: displays message and sets bool to true
    *********************************************************************/ 
    void encounter(bool&);

    /*********************************************************************
    ** Function: gold()
    ** Description: constructor for gold class, sets symbol to "G"
    ** Parameters: none 
    ** Pre-Conditions: gold object must exist 
    ** Post-Conditions: sets symbol to "G"
    *********************************************************************/ 
    gold();

    /*********************************************************************
    ** Function: gold& operator=(const gold&)
    ** Description: overload the assignment operator for the gold class
    ** Parameters: const gold&
    ** Pre-Conditions: gold object must exist
    ** Post-Conditions: the current gold object has its symbol is updated to match the assigned gold object.
    *********************************************************************/ 
    gold& operator=(const gold&);

    /*********************************************************************
    ** Function: gold(const gold&)
    ** Description: copy constructor for the gold class
    ** Parameters: const gold&
    ** Pre-Conditions: an gold object must exist
    ** Post-Conditions: a new gold object is created with the same symbol
    *********************************************************************/ 
    gold(const gold&);

    /*********************************************************************
    ** Function: clone()
    ** Description: creates a new gold object as a copy of the current object
    ** Parameters: none
    ** Pre-Conditions: gold object must exist 
    ** Post-Conditions: returns a pointer to a new gold object
    *********************************************************************/ 
    event* clone();

    /*********************************************************************
    ** Function: get_sym() const
    ** Description: retrieves the symbol representing the gold
    ** Parameters: none
    ** Pre-Conditions:the gold object must exist
    ** Post-Conditions: returns the string symbol of the gold 
    *********************************************************************/ 
    string get_sym() const;
};


#endif
