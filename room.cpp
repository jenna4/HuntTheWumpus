#include "room.hpp"

Room::Room() {
    this->e = nullptr;
    this->has_adventurer = false;
    this->has_rope = false;
}

// asignemnet op
Room& Room::operator=(const Room& r) {
    if (this != &r) {
        // clean existing event
        delete this->e;

        // copy 
        this->has_adventurer = r.has_adventurer;
        this->has_rope = r.has_rope;

        // deep copy event if exist
        if (r.e != nullptr) {
            this->e = r.e->clone();
        } else {
            this->e = nullptr;
        }
    }
    return *this;
}

Room::Room(const Room& r) {
    this->has_adventurer = r.has_adventurer;
    this->has_rope = r.has_rope;

    //deep copy
    if (r.e != nullptr) {
        this->e = r.e->clone();
    } else {
        this->e = nullptr;
    }
}

Room::~Room() {
    if (this->e != nullptr) {
        delete this->e;
        this->e = nullptr;
    }
}

bool Room::get_has_adventurer() const {
    return this->has_adventurer;
}

bool Room::get_has_rope() const {
    return this->has_rope;
}

void Room::set_has_rope(const bool hr) {
    this->has_rope = hr;
}

bool Room::empty_room() const {
    if (this->e != nullptr) {
        return false;
    }
    // else is empty so return true
    return true;
}

bool Room::adventurer_status() {
    //if room has adventuer, switch to false
    if (this->has_adventurer) {
        this->has_adventurer = false;
    } else {
        // switch to true
        this->has_adventurer = true;
    }
}

event* Room::get_event() const {
    return this->e;
}

void Room::apply_event(event* eve) {
    //assigns new event to event pointer 
    delete this->e;
    this->e = eve;
}

string Room::get_event_sym() const {
    return this->e->get_sym();
}

void Room::print_event_sym() const {
    this->e->print_sym();
}

void Room::percept() {
    this->e->percept();
}

void Room::encounter(bool& blife, bool& bgold, bool& confused, bool& barrow, bool& bwarp, bool& bring) {
    string sevent = e->get_sym();

    // if event is gold
    if (sevent == "G") {
        cout << endl;
        cout << "------------------------------------" << endl;
        e->encounter(bgold);
        cout << "------------------------------------" << endl;
    } // else if event is arrow
    else if (sevent == "A") {
        cout << endl;
        cout << "------------------------------------" << endl;
        e->encounter(barrow);
        cout << "------------------------------------" << endl;
    } // else if event is bottomless pit
    else if (sevent == "P") {
        cout << endl;
        cout << "------------------------------------" << endl;
        e->encounter(blife);
        cout << "------------------------------------" << endl;
    } // else if event is bat swarm
    else if (sevent == "B") {
        cout << endl;
        cout << "------------------------------------" << endl;
        e->encounter(confused);
        cout << "------------------------------------" << endl;
    } //else if event is wumpus
    else if (sevent == "W") {
        cout << endl;
        cout << "------------------------------------" << endl;
        e->encounter(blife);
        cout << "------------------------------------" << endl;
    } // else if event is escape rope
    else if (sevent == "H") {
        cout << endl;
        cout << "------------------------------------" << endl;
        e->encounter(bwarp);
        cout << "------------------------------------" << endl;
    }
    else if (sevent == "L") {
        cout << endl;
        cout << "------------------------------------" << endl;
        e->encounter(bring);
        cout << "------------------------------------" << endl;
    }
    else {
        cout << endl;
        cout << "------------------------------------" << endl;
        e->encounter(bgold);
        cout << "------------------------------------" << endl;
    }
}

