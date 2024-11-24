#ifndef ARROW_HPP
#define ARROW_HPP
#include "event.hpp"
#include <iostream>
#include <string>
using namespace std;
// TODO Arrow interface (define the arrow class and declare its member functions
// below)
class arrow : public event {
    public:
    void percept();
    void encounter(bool& has_arrow);

    arrow();
    arrow& operator=(const arrow&);
    arrow(const arrow&);
    event* clone();
    string get_sym() const;
};


#endif
