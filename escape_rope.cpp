#include "escape_rope.hpp"

rope::rope() {
    this->symbol = "R";
}

rope& rope::operator=(const rope& r) {
    this->symbol = r.symbol;
    return *this;
}

rope::rope(const rope& r) {
    this->symbol = r.symbol;
}

void rope::percept() {
    // none for escape rope
}

void rope::encounter(bool& has_gold) {
    if (has_gold) {
        cout << "You found the escape room and escaped with the gold." << endl;
        cout << "You win!" << endl;
    } else {
        cout << "You found the escape rope, but you need the gold to escape!" << endl;
    }
}

event* rope::clone() {
    return new rope(*this);
}

string rope::get_sym() const {
    return this->symbol;
}