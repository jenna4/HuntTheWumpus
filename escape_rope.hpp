#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP
#include <iostream>
#include "event.hpp"
#include <string>
using namespace std;

// TODO Escape rope interface (define the escape_rope class and declare its
// member functions below)
class rope : public event {
    public:
    void percept();
    void encounter(bool&);

    rope();
    rope& operator=(const rope&);
    rope(const rope&);
    event* clone();
};


#endif
