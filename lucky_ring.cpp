#include <iostream>
#include <string>
#include "event.hpp"
#include "lucky_ring.hpp"
using namespace std;

lucky_ring::lucky_ring() {
    this->symbol = "L";
}

lucky_ring& lucky_ring::operator=(const lucky_ring& l) {
    this->symbol = l.symbol;
    return *this;
}

lucky_ring::lucky_ring(const lucky_ring& l) {
    this->symbol = l.symbol;
}

void lucky_ring::percept() {
    cout << "You feel like luck is on your side today" << endl; 
}

void lucky_ring::encounter(bool& bring) {
    if (!bring) {
        cout << "You have found the Lucky Ring, protecting you from two fatal encounters!" << endl;
        bring = true;
    }
}

event* lucky_ring::clone() {
    return new lucky_ring(*this);
}

string lucky_ring::get_sym() const {
    return this->symbol;
}
