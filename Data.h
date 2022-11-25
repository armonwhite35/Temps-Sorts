//
// Created by armon on 5/1/2020.
//

#ifndef PROJECT_8_WHITE3_DATA_H
#define PROJECT_8_WHITE3_DATA_H

#include <string>
#include <vector>
using namespace std;
class Data {
//code borrowed from project 7
private:
    int id;
    string start;
    int stop;
    int trip;
public:
    Data(int _id=0, string s="", int st=0, int t=0);
    bool operator<(Data &rhs) const;
    bool operator>(Data &rhs) const;
    bool operator==(Data &rhs) const;
    friend ostream& operator<<(ostream& os, const Data &rhs);
};



#endif //PROJECT_8_WHITE3_DATA_H
