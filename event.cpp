#include "event.hpp"
#include <iostream>
using namespace std;

string event::get_sym() const {
    return this->symbol;
}

void event::print_sym() {
    cout << this->symbol;
}