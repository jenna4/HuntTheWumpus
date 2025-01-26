#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"

// Room interface
class Room {
private: 
	event* e;
	bool has_adventurer;
	bool has_rope;

public:

    /*********************************************************************
    ** Function: get_has_adventurer() const
    ** Description: returns a bool indicating ig the room contains the adventurer
    ** Parameters: none 
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: returns true if room contains adventurer, false otherwise
    *********************************************************************/ 
	bool get_has_adventurer() const;

    /*********************************************************************
    ** Function: get_has_rope() const
    ** Description: returns a bool indicating if the room contains a rope
    ** Parameters: none
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: returns true if rope is in room, else returns false
    *********************************************************************/ 
	bool get_has_rope() const;

    /*********************************************************************
    ** Function: set_has_rope(const bool)
    ** Description: sets whether the room contains a rope or not
    ** Parameters: const bool
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: has_rope is set to the value of hr
    *********************************************************************/ 
	void set_has_rope(const bool);

    /*********************************************************************
    ** Function: empty_room() const
    ** Description: checks if room is empty or not by checking if there is an event in the room
    ** Parameters: none
    ** Pre-Conditions: room object exists
    ** Post-Conditions: returns true if the room is empty
    *********************************************************************/ 
	bool empty_room() const;

    /*********************************************************************
    ** Function: adventurer_status()
    ** Description: function toggles the presence of the adventurer in the room. if room already has adventurer
    ** the adventurer is removed. if the room has no adventurer, the function places one in the room
    ** Parameters: none
    ** Pre-Conditions: room object must exist
    ** Post-Conditions: the bool to see if room has adventurer is switched between true and false 
    *********************************************************************/ 
	bool adventurer_status();

    /*********************************************************************
    ** Function: apply_event(event*)
    ** Description: assigns ew event to the room's event pointer. deletes any existing event assigned to room,
    ** and then assigns the new event to the room
    ** Parameters: event*
    ** Pre-Conditions: room object needs to exist, event pointer needs to exist
    ** Post-Conditions: the room's pointer will point to a new event, and any old event if there is any will be deleted
    *********************************************************************/ 
	void apply_event(event*);
    event* get_event() const;
    /*********************************************************************
    ** Function: get_event_sym() const
    ** Description: returns the symbol associated with event in room
    ** Parameters: none
    ** Pre-Conditions: room object must exist
    ** Post-Conditions: the symbol of the event is returned as a string.
    *********************************************************************/ 
	string get_event_sym() const;

    /*********************************************************************
    ** Function: print_event_sym() const
    ** Description: prints the symbol of the event in the room.
    ** Parameters: none
    ** Pre-Conditions: room boject must exist
    ** Post-Conditions: the symbol of the event is printed to the terimal
    *********************************************************************/ 
	void print_event_sym() const;
	
    /*********************************************************************
    ** Function: perpect()
    ** Description: calls the percept on the event object assigned to the room
    ** Parameters: none
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: the percept related to the event in the room is printed to the terminal 
    *********************************************************************/ 
	void percept();

    /*********************************************************************
    ** Function: encounter(bool&, bool&, bool&, bool&)
    ** Description: handles the interaction with the event assigned to the room.
    ** Parameters: bool&, bool&, bool&, bool&
    ** Pre-Conditions: room object mjst exist and four bools must exist 
    ** Post-Conditions: the certain encounter is triggered based on event symbol
    *********************************************************************/ 
	void encounter(bool&, bool&, bool&, bool&, bool&, bool&);

    /*********************************************************************
    ** Function: Room()
    ** Description: constructor for Room class, initializes room with no event, no adventurer, and no rope
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: initialized to default
    *********************************************************************/ 
	Room();

    /*********************************************************************
    ** Function: Room& operator=(const Room&)
    ** Description: assignemnt operator for the room class. copies state of one room to another
    ** Parameters: const Room&
    ** Pre-Conditions: room object must exist 
    ** Post-Conditions: a deep copy of the event is made 
    *********************************************************************/ 
	Room& operator=(const Room&);

    /*********************************************************************
    ** Function: Room(const Room&)
    ** Description: copy constructor for the class room. initializes a new room object as a copy 
    ** Parameters: const Room&
    ** Pre-Conditions: room boject msut exist
    ** Post-Conditions: a new room is created with the same attributes as original
    *********************************************************************/ 
	Room(const Room&);

    /*********************************************************************
    ** Function: ~Room()
    ** Description: destructor for the room class. frees dynamically allocated memory for the event
    ** Parameters: none
    ** Pre-Conditions: room object must exist
    ** Post-Conditions: if the room object hold an event, the event's mem  is freed
    *********************************************************************/ 
	~Room();
};

#endif
