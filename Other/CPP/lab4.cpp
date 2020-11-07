#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <ios>
#include <time.h>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

bool validTest(const string & s);

class Time {
    private:
        int hour, minute;
    public:
        Time();
        void read(string msg);
        bool lessThan(Time notThis);
        Time subtract(Time notThis);
        void display();
};

int main() {
    Time time1, time2, duration;
    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1.lessThan(time2)) {
    duration = time2.subtract(time1);
    cout << "Starting time was ";
    time1.display();
    } else {
    duration = time1.subtract(time2);
    cout << "Starting time was ";
    time2.display();
    }
    cout << "Duration was ";
    duration.display();
    return 0;
}

bool validTest(const string & s){
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

}

void Time::read(string msg){
    string hh = "", mm = "";

    while(1){
        cout << msg << ": " << flush;
        cin >> hh >> mm;

        if (cin.good() && validTest(hh) && validTest(mm)){
            try {
                this->hour = stoi(hh);
                this->minute = stoi(mm);
            } catch(...){
            }
            if(this->hour <= 23 && this->hour >= 0 && this->minute <= 59 && this->minute >= 0){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
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
    cout << setiosflags(ios::right); cout << setfill('0') << setw(2) << this->hour;
    cout << ":" << setfill('0') << setw(2) << this->minute << endl;
}