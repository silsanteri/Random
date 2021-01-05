// Exercise 6 - Time.cpp

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

bool validTest(const std::string & s){
    if(s.size() != 2){
        return false;
    } else {
        for (char c : s){
            if (!isdigit(c)){
                return false;
            }
        }
        return true;
    }
}

Time::Time(){
    this->hour = 00;
    this->minute = 00;
}

Time::Time(int hh, int mm){ //This constructor doesn't check for valid times, because it's mainly used to add offset to times.
    this->hour = hh;
    this->minute = mm;
}

std::ostream &operator<<(std::ostream &out, const Time &notThis){
    out << std::setiosflags(std::ios::right); std::cout << std::setfill('0') << std::setw(2) << notThis.hour;
    out << ":" << std::setfill('0') << std::setw(2) << notThis.minute << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Time &notThis){
    char colon;
    int hh, mm;
    if(in >> hh >> colon >> mm){
        if(hh <= 23 && hh >= 0 && colon == ':' && mm <= 59 && mm >= 0){
            notThis.hour = hh;
            notThis.minute = mm;
        } else {
            in.setstate(std::ios_base::failbit);
        }
    }
    return in;
}

bool Time::operator<(const Time &notThis) const {
    if(this->hour > notThis.hour){
        return false;
    } else if (this->hour == notThis.hour && this->minute > notThis.minute){
        return false;
    } else {
        return true;
    }
}

bool Time::operator>(const Time &notThis) const {
    if(this->hour > notThis.hour){
        return true;
    } else if (this->hour == notThis.hour && this->minute > notThis.minute){
        return true;
    } else {
        return false;
    }
}

bool Time::operator==(const Time &notThis) const {
    if(this->hour == notThis.hour && this->minute == notThis.minute){
        return true;
    } else {
        return false;
    }
}

Time Time::operator+(const Time &notThis) const {
    int thisMin = (this->hour * 60) + this->minute;
    int notThisMin = (notThis.hour * 60) + notThis.minute;
    int finalMin = thisMin + notThisMin;
    Time temp;
    temp.hour = finalMin / 60;
    temp.minute = finalMin % 60;

    if(temp.minute >= 60){
        temp.minute -= 60;
        temp.hour++;
    }
    if(temp.hour >= 24){
        temp.hour -= 24;
    }

    return temp;
}

Time Time::operator-(const Time &notThis) const {
    int thisMin = (this->hour * 60) + this->minute;
    int notThisMin = (notThis.hour * 60) + notThis.minute;
    int finalMin = thisMin - notThisMin;
    Time temp;
    temp.hour = finalMin / 60;
    temp.minute = finalMin % 60;
    return temp;
}

Time& Time::operator++(){
    this->minute++;
    if(this->minute >= 60){
        this->minute -= 60;
        this->hour++;
    }
	if(this->hour >= 24){
		this->hour = 0;
	}
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    this->minute++;
    if(this->minute >= 60){
        this->minute -= 60;
        this->hour++;
    }
	if(this->hour >= 24){
		this->hour = 0;
	}
    return temp;
}

void Time::read(std::string msg){
    std::string hh = "", mm = "";

    while(1){
        std::cout << msg << ": " << std::flush;
        std::cin >> hh >> mm;

        if (std::cin.good() && validTest(hh) && validTest(mm)){
            try {
                this->hour = stoi(hh);
                this->minute = stoi(mm);
            } catch(...){
            }
            if(this->hour <= 23 && this->hour >= 0 && this->minute <= 59 && this->minute >= 0){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input!" << std::endl;
    }
}

bool Time::lessThan(Time notThis){
    if(this->hour > notThis.hour){
        return false;
    } else if (this->hour == notThis.hour && this->minute > notThis.minute){
        return false;
    } else {
        return true;
    }
}

Time Time::subtract(Time notThis){
    int thisMin = (this->hour * 60) + this->minute;
    int notThisMin = (notThis.hour * 60) + notThis.minute;
    int finalMin = thisMin - notThisMin;
    Time temp;
    temp.hour = finalMin / 60;
    temp.minute = finalMin % 60;
    return temp;
}

void Time::display(){
    std::cout << std::setiosflags(std::ios::right); std::cout << std::setfill('0') << std::setw(2) << this->hour;
    std::cout << ":" << std::setfill('0') << std::setw(2) << this->minute << std::endl;
}

std::string Time::getString(){
    std::string final;
    std::stringstream ss;
    ss << std::setiosflags(std::ios::right) << std::setfill('0') << std::setw(2) << this->hour;
    ss << ":" << std::setfill('0') << std::setw(2) << this->minute << std::endl;
    getline(ss, final);
    return final;
}