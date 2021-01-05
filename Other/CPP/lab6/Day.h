// Exercise 6 - Day.h

#pragma once
#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Time.h"

class Day {
public:
    Day(int dd = 00, std::string mm = "Month");
    bool from_str(const std::string &s);
    std::string to_str();
    void dst(int offset);
private:
    int day;
    std::string month;
    std::vector<Time> list;
};
#endif