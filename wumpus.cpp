#include "wumpus.hpp"

wumpus::wumpus() {
    this->symbol = "W";
}

wumpus& wumpus::operator=(const wumpus& w) {
    this->symbol = w.symbol;
    return *this;
}

wumpus::wumpus(const wumpus& w) {
    this->symbol = w.symbol;
}

void wumpus::percept() {
    cout << endl;
    cout << "The hairs stand up on the back of your neck." << endl;
    cout << endl;
}

void wumpus::encounter(bool& blife) {
    cout << "You awoke the Wumpus and got eaten." << endl;
    blife = false;
}

event* wumpus::clone() {
    return new wumpus(*this);
}

string wumpus::get_sym() const {
    return this->symbol;
}