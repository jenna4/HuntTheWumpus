#ifndef LUCKY_RING_HPP
#define LUCKY_RING_HPP
#include <iostream>
#include <string>
#include "event.hpp" 

class lucky_ring : public event {
    public:
    
    /*********************************************************************
    ** Function: percept()
    ** Description: prints percept
    ** Parameters: none
    ** Pre-Conditions: ring object must exist
    ** Post-Conditions: prints percepts
    *********************************************************************/ 
    void percept();

    /*********************************************************************
    ** Function: encounter(bool&)
    ** Description: displays message that adventurer that ring was found, set the bring bool to true
    ** Parameters: bool&
    ** Pre-Conditions: ring object must exist 
    ** Post-Conditions: displays message and sets bool to true
    *********************************************************************/  
    void encounter(bool&);

    /*********************************************************************
    ** Function: lucky_ring()
    ** Description: constructor for wumpus class, sets symbol to "L"
    ** Parameters: none 
    ** Pre-Conditions: ting object must exist 
    ** Post-Conditions: sets symbol to "L"
    *********************************************************************/ 
    lucky_ring();

    /*********************************************************************
    ** Function: lucky_ring& operator=(const lucky_ring& l);
    ** Description: overload the assignment operator for the ring class
    ** Parameters: const ring&
    ** Pre-Conditions: ring object must exist
    ** Post-Conditions: the current ring object has its symbol is updated to match the assigned ring object.
    *********************************************************************/ 
    lucky_ring& operator=(const lucky_ring& l);

    /*********************************************************************
    ** Function: lucky_ring(const lucky_ring& l)
    ** Description: copy constructor for the lucky_ring class
    ** Parameters: const lucky_ring&
    ** Pre-Conditions: an ring object must exist
    ** Post-Conditions: a new ring object is created with the same symbol
    *********************************************************************/ 
    lucky_ring(const lucky_ring& l);

    /*********************************************************************
    ** Function: clone()
    ** Description: creates a new ring object as a copy of the current object
    ** Parameters: none
    ** Pre-Conditions: ring object must exist 
    ** Post-Conditions: returns a pointer to a new ring object
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