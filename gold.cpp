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
    cout << "You stub your toe on something heavy." << endl;
}

void gold::encounter(bool& bgold) {
    cout << "You've found the gold and have picked it up" << endl;
    
    bgold = true;
}



