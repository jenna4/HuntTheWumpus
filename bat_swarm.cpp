#include "bat_swarm.hpp"

bats::bats() {
    this->symbol = "B";
}

bats& bats::operator=(const bats& b) {
    this->symbol = b.symbol;
    return *this;
}

bats::bats(const bats& b) {
    this->symbol = b.symbol;
}

void bats::percept() {
    cout << "You hear screeching." << endl;
}

void bats::encounter(bool& confused) {
    cout << "You've entered a room with an angry bat swarm that confuses you, causing you to move in a random direction!" << endl;
    confused = true;
}

event* bats::clone() {
    return new bats(*this);
}

string bats::get_sym() const {
    return this->symbol;
}
