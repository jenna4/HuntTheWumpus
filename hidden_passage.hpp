#ifndef HIDDEN_PASSAGE_HPP
#define HIDDEN_PASSAGE_HPP
#include "event.hpp"
#include <iostream>
using namespace std;

class hidden_passage : public event {
    public:
    void percept();

    void encounter(bool&);

    hidden_passage();

    hidden_passage& operator=(const hidden_passage&);

    hidden_passage(const hidden_passage&);

    event* clone();

    string get_sym() const;
};


#endif