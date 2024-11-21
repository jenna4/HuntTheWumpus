#include "event.hpp"
#include <iostream>
using namespace std;
// Event implementation (define non-pure-virtual event member functions below,
// if relevant)

string event::get_sym() const {
    return this->symbol;
}

void event::print_sym() {
    cout << this->symbol;
}