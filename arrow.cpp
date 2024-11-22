#include "arrow.hpp"

// TODO Arrow implementation (define arrow member functions below)
arrow::arrow() {
    this->symbol = "A";
}

arrow& arrow::operator=(const arrow& a) {
    this->symbol = a.symbol;
    return *this;
}

arrow::arrow(const arrow& a) {
    this->symbol = a.symbol;
}

void arrow::percept() {
    // no percept for arrows
}

void arrow::encounter(bool& has_arrow) {
    cout << "You have picked up an arrow" << endl;
    has_arrow = true;
}