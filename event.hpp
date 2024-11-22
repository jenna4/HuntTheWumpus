#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
#include <string>
using namespace std;

// Event interface
class event {
private:
	// TODO private members, if relevant
protected:
	// TODO protected members, if relevant
	string symbol;
public:
	// TODO public members
	string get_sym() const;
	void print_sym();
	virtual void percept() = 0;
	virtual void encounter(bool&) = 0;

};

#endif
