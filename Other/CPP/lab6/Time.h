// Exercise 6 - Time.h

#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>
#include <string>

class Time {
    private:
        int hour;
        int minute;
    public:
        Time();
        Time(int hh, int mm);

        friend std::ostream &operator<<(std::ostream &out, const Time &notThis);
        friend std::istream &operator>>(std::istream &in, Time &notThis);
        bool operator<(const Time &notThis) const;
        bool operator>(const Time &notThis) const;
        bool operator==(const Time &notThis) const;
        Time operator+(const Time &notThis) const;
        Time operator-(const Time &notThis) const;
        Time& operator++();
        Time operator++(int);

        void read(std::string msg);
        bool lessThan(Time notThis);
        Time subtract(Time notThis);
        void display();
        std::string getString();
};
#endif