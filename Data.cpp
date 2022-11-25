//
// Created by armon on 5/1/2020.
//
#include <iostream>
#include "Data.h"

//code borrowed from project 7

Data::Data(int _id, string s, int st, int t) {
    id = _id;
    start = s;
    stop = st;
    trip = t;
}

bool Data::operator<(Data &rhs) const {
    if (trip < rhs.trip) {
        return true;
    } else {
        return false;
    }
}

bool Data::operator>(Data &rhs) const {
    if (trip > rhs.trip) {
        return true;
    } else {
        return false;
    }
}

bool Data::operator==(Data &rhs) const {
    if (trip == rhs.trip) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream &os, const Data &rhs) {
    os << rhs.id << ", " << rhs.start << ", " << rhs.stop << ", " << rhs.trip << endl;
    return os;
}