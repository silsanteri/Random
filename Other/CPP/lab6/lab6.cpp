// Exercise 6 - Main

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "Time.h"
#include "Day.h"

using namespace std;

int main()
{
    ifstream inputFile("calendar.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<Day> cal;
    Day day;

    while (getline(inputFile, line)) {
        if (day.from_str(line)) {
            cal.push_back(day);
        }
    }
    cout << "Calendar" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    // DST shift
    for (auto& e : cal) {
        e.dst(1);
    }
    cout << "DST" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    cout << "End" << endl;

    return 0;
}