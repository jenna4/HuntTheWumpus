#include "gold.hpp"
#include <iostream>
#include <string>
using namespace std;

// TODO Gold implementation (define gold member functions below)
gold::gold() {
    this->symbol = "G";
}

gold& gold::operator=(const gold& g) {
    this->symbol = g.symbol;
    return *this;
}

gold::gold(const gold& g) {
    this->symbol = g.symbol;
}

void gold::percept() {
    cout << endl;
    cout << "You stub your toe on something heavy." << endl;
    cout << endl;
}

void gold::encounter(bool& bgold) {
    cout << "You've found the gold and have picked it up" << endl;
    
    bgold = true;
}

event* gold::clone() {
    return new gold(*this);
}

string gold::get_sym() const {
    return this->symbol;
}
