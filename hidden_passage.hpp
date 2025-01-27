#ifndef HIDDEN_PASSAGE_HPP
#define HIDDEN_PASSAGE_HPP
#include "event.hpp"
#include <iostream>
using namespace std;

class hidden_passage : public event {
    public:

    /*********************************************************************
    ** Function: percept()
    ** Description: prints percept
    ** Parameters: none
    ** Pre-Conditions: passage object must exist
    ** Post-Conditions: prints percepts
    *********************************************************************/ 
    void percept();

    /*********************************************************************
    ** Function: encounter(bool&)
    ** Description: displays message that adventurer that passage was found, set the bwarp bool to true
    ** Parameters: bool&
    ** Pre-Conditions: passage object must exist 
    ** Post-Conditions: displays message and sets bool to true
    *********************************************************************/  
    void encounter(bool&);

    /*********************************************************************
    ** Function: hidden_passage()
    ** Description: constructor for wumpus class, sets symbol to "H"
    ** Parameters: none 
    ** Pre-Conditions: passage object must exist 
    ** Post-Conditions: sets symbol to "H"
    *********************************************************************/ 
    hidden_passage();

    /*********************************************************************
    ** Function: hidden_passage& operator=(const hidden_passage&);
    ** Description: overload the assignment operator for the passage class
    ** Parameters: const hidden_passage&
    ** Pre-Conditions: passage object must exist
    ** Post-Conditions: the current passage object has its symbol is updated to match the assigned passage object.
    *********************************************************************/ 
    hidden_passage& operator=(const hidden_passage&);

    /*********************************************************************
    ** Function: hidden_passage(const hidden_passage&)
    ** Description: copy constructor for the passage class
    ** Parameters: const passage&
    ** Pre-Conditions: an passage object must exist
    ** Post-Conditions: a new passage object is created with the same symbol
    *********************************************************************/ 
    hidden_passage(const hidden_passage&);

    /*********************************************************************
    ** Function: clone()
    ** Description: creates a new passage object as a copy of the current object
    ** Parameters: none
    ** Pre-Conditions: passage object must exist 
    ** Post-Conditions: returns a pointer to a new passage object
    *********************************************************************/ 
    event* clone();

    /*********************************************************************
    ** Function: get_sym() const
    ** Description: returns the symbol representing the event
    ** Parameters: none
    ** Pre-Conditions: event object must exist
    ** Post-Conditions: returns the symbol as a string 
    *********************************************************************/ 
    string get_sym() const;
};


#endif