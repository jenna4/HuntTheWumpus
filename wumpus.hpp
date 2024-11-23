#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include "event.hpp"
#include <iostream>
using namespace std;

// TODO Wumpus interface (define the wumpus class and declare its member
// functions below)
class wumpus : public event {
    public:
    void percept();
    void encounter(bool&);

    // da big 3
    wumpus();
    wumpus& operator=(const wumpus&);
    wumpus(const wumpus&);
    event* clone();
};

#endif
