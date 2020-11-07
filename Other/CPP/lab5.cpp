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

class Time {
    private:
        int hour, minute;
    public:
        Time();
        friend ostream &operator<<(ostream &out, const Time &notThis);
        bool operator<(const Time &notThis) const;
        Time operator+(const Time &notThis) const;
        Time operator-(const Time &notThis) const;
        Time& operator++();
        Time operator++(int);
        void read(string msg);
        bool lessThan(Time notThis);
        Time subtract(Time notThis);
        void display();
};

void print(const vector<Time> &v);
bool validTest(const string & s);

int main() {
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1<time2) {
		duration = time2 - time1;
		cout << "Starting time was " << time1 << endl;
	} else {
		duration = time1 - time2;
		cout << "Starting time was " << time2 << endl;
	}
	cout << "Duration was " << duration << endl;

	vector<Time> tv(5); 
	for(auto &t : tv) {
		t.read("Enter time:");
	}

	cout << "Times: " << endl;
	print(tv);
	
	Time sum;
	for(auto t : tv) {
		sum = sum + t;
	}
	
	cout << "Sum of times: " << sum << endl;
	
	cout << "Post-increment: " << endl;
	print(tv);
	for(auto &t : tv) {
		cout << t++ << endl;
	}
	
	print(tv);

	cout << "Pre-increment: " << endl;
	for(auto &t : tv) {
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	return 0;
}

void print(const vector<Time> &v){
	for(auto &t : v) {
		cout << t << endl;
	}
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
    this->hour = 00;
    this->minute = 00;
}

ostream &operator<<(ostream &out, const Time &notThis){
    out << setiosflags(ios::right); cout << setfill('0') << setw(2) << notThis.hour;
    out << ":" << setfill('0') << setw(2) << notThis.minute << endl;
    return out;
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
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    this->minute++;
    if(this->minute >= 60){
        this->minute -= 60;
        this->hour++;
    }
    return temp;
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