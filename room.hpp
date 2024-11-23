#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"

// Room interface
class Room {
private: 
	// TODO private members
	event* e;
	bool has_adventurer;
	bool has_rope;

public:
	// TODO public members
	bool get_has_adventurer() const;
	bool get_has_rope() const;

	void set_has_rope(const bool);
	bool empty_room() const;
	bool adventurer_status();
	void apply_event(event*);
	string get_event_sym() const;
	void print_event_sym() const;

	void percept();
	void encounter(bool&, bool&, bool&, bool&);

	Room();
	Room& operator=(const Room&);
	Room(const Room&);
	~Room();
};

#endif
