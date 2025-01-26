#ifndef ARROW_HPP
#define ARROW_HPP
#include "event.hpp"
#include <iostream>
#include <string>
using namespace std;

class arrow : public event {
    public:

    /*********************************************************************
    ** Function: percept()
    ** Description: placeholder for percept, arrow has none so empty body
    ** Parameters: none
    ** Pre-Conditions: base class must exist
    ** Post-Conditions: doesnt print any percept for arrows
    *********************************************************************/ 
    void percept();

    /*********************************************************************
    ** Function: encounter()
    ** Description: handles encounter event for arrow, updates the has_arrow bool to true
    ** Parameters: bool& has_arrow
    ** Pre-Conditions: the player enters a room containing an arrow 
    ** Post-Conditions: the has_arrow bool is set to true, and a message is print out 
    *********************************************************************/ 
    void encounter(bool& has_arrow);

    /*********************************************************************
    ** Function: arrow()
    ** Description: constructor for the arrow class. Initializes the arrow object with "A" symbol
    ** Parameters: none
    ** Pre-Conditions: an object needs to exist 
    ** Post-Conditions: The symbol of the arrow is set to "A"
    *********************************************************************/ 
    arrow();

    /*********************************************************************
    ** Function: arrow& operator=(const arrow&)
    ** Description: overload the assignment operator for the arrow class
    ** Parameters: const arrow&
    ** Pre-Conditions: arrow object must exist
    ** Post-Conditions: the current arrow object has its symbol is updated to match the assigned arrow object.
    *********************************************************************/ 
    arrow& operator=(const arrow&);

    /*********************************************************************
    ** Function: arrow(const arrow&)
    ** Description: copy constructor for the arrow class
    ** Parameters: const arrow&
    ** Pre-Conditions: an arrow object must exist
    ** Post-Conditions: a new arrow object is created with the same symbol
    *********************************************************************/ 
    arrow(const arrow&);

    /*********************************************************************
    ** Function: clone()
    ** Description: creates and returns a dynamically allocated copy of the arrow object
    ** Parameters: none
    ** Pre-Conditions: arrow object must exist
    ** Post-Conditions: returns a pointer to a new arrow object
    *********************************************************************/ 
    event* clone();

    /*********************************************************************
    ** Function: get_sym()
    ** Description: retrieves the symbol representing the arrow
    ** Parameters: none
    ** Pre-Conditions:the arrow object must exist
    ** Post-Conditions: returns the string symbol of the arrow 
    *********************************************************************/ 
    string get_sym() const;
};


#endif
