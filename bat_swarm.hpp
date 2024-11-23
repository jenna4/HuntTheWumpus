#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP
#include <iostream>
#include "event.hpp"
using namespace std;
// TODO Bat Swarm interface (define the bat_swarm class and declare its member
// functions below)
class bats : public event {
    public:
    void percept();
    void encounter(bool&);

    // big3
    bats();
    bats& operator=(const bats&);
    bats(const bats&);
    event* clone();
};


#endif
