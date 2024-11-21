#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP
#include "event.hpp"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

// TODO Bottomless Pit interface (define the bottomless_pit class and declare
// its member functions below)
class pit : public event {
    public: 
    void percept();
    void encounter(bool&);
    event* clone();

    // da big 3
    pit();
    pit& operator=(const pit&);
    pit(const pit&);

};



#endif
