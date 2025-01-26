#include "bottomless_pit.hpp"
#include <iostream>
#include <string>
using namespace std;

pit::pit() {
    this->symbol = "P";
}

pit& pit::operator=(const pit& p) {
    this->symbol = p.symbol;
    return *this;
}

pit::pit(const pit& p) {
    this->symbol = p.symbol;
}

void pit::percept() {
    cout << endl;
    cout << "You feel a breeze." << endl;
    cout << endl;
}

void pit::encounter(bool& blife) {
    cout << "You entered a room with a bottomless pit." << endl;
    int fall = rand() % 2;
    if(fall == 1) {
        cout << "You fell in the pit and died!" << endl;
        blife = false;
    } else {
        cout << "You walked around the bottomless pit." << endl;
    }
}

event* pit::clone() {
    return new pit(*this);
}

string pit::get_sym() const {
    return this->symbol;
}


