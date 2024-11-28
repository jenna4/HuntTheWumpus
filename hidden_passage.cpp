#include "hidden_passage.hpp"
#include <iostream>
#include <string>
using namespace std;

hidden_passage::hidden_passage() {
    this->symbol = "H";
}

hidden_passage& hidden_passage::operator=(const hidden_passage& h) {
    this->symbol = h.symbol;
    return *this;
}

hidden_passage::hidden_passage(const hidden_passage& h) {
    this->symbol = h.symbol;
}

void hidden_passage::percept() {
    cout << endl;
    cout << "You hear water dripping" << endl;
    cout << endl;
}

void hidden_passage::encounter(bool& bwarp) {
    cout << "You have discovered a secret passage!" << endl;
    bwarp = true;
}

event* hidden_passage::clone() {
    return new hidden_passage(*this);
}

string hidden_passage::get_sym() const {
    return this->symbol;
}