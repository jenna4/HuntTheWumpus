#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
#include <string>
using namespace std;

// Event interface
class event {
protected:
	string symbol;
public:
	/*********************************************************************
    ** Function: get_sym() const
    ** Description: returns the symbol representing the event
    ** Parameters: none
    ** Pre-Conditions: event object must exist
    ** Post-Conditions: returns the symbol as a string 
    *********************************************************************/ 
	string get_sym() const;

    /*********************************************************************
    ** Function: print_sym()
    ** Description: prints the symbol representing the event
    ** Parameters: none 
    ** Pre-Conditions: event object must exist
    ** Post-Conditions: prints the symbol
    *********************************************************************/ 
	void print_sym();

    /*********************************************************************
    ** Function: percept()
    ** Description: placeholder for percept for child classes
    ** Parameters: none
    ** Pre-Conditions: event object object must exist
    ** Post-Conditions: placeholder
    *********************************************************************/ 
	virtual void percept() = 0;

    /*********************************************************************
    ** Function: encounter(bool&)
    ** Description: placeholder for encounter for child classes
    ** Parameters: bool&
    ** Pre-Conditions: event object must exist
    ** Post-Conditions: placeholder
    *********************************************************************/ 
	virtual void encounter(bool&) = 0;

    /*********************************************************************
    ** Function: clone()
    ** Description: placeholder for clone func in child classes
    ** Parameters: none 
    ** Pre-Conditions: event object must exist
    ** Post-Conditions: placeholder 
    *********************************************************************/ 
	virtual event* clone() = 0;
};

#endif
