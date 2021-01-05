// Exercise 6 - Day.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <ios>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "Time.h"
#include "Day.h"

Day::Day(int dd, std::string mm) : day(dd), month(mm){
}

bool Day::from_str(const std::string &s){
    *this = Day();
    std::string trash;
    bool valid = false;
    Time time;

    std::stringstream ss(s);
    if(ss >> this->day >> this->month){
        while(ss){
            if(ss >> time){
                this->list.push_back(time);
                sort(this->list.begin(), this->list.end());
                valid = true;
            } else {
                ss.clear();
                ss >> trash;
            }
        }
    }
    return valid;
}

std::string Day::to_str(){
    std::string final;
    final = std::to_string(this->day) + " " + this->month;
    for(auto &l : this->list){
        final.append(" " + l.getString());
    }
    return final;
}

void Day::dst(int offset){
    Time migos(offset, 0);
    for(auto &x : this->list){
        x = x + migos;
    }
    sort(this->list.begin(), this->list.end());
}