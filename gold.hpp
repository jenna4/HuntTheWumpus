#ifndef GOLD_HPP
#define GOLD_HPP
#include "event.hpp"
#include <iostream>
#include <string>
using namespace std;

// TODO Gold interface (define the gold class and declare its member functions
// below)
class gold : public event {
    public:
    void percept();
    void encounter(bool&);


    // da big 3
    gold();
    gold& operator=(const gold&);
    gold(const gold&);
    event* clone();
};


#endif
