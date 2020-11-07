// Exercise 3B

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

using namespace std;

void backwards(vector<string> &list);

int main()
{
    vector<string> stringList;
    string input = "";

    while (1){
        cout << "Enter a string: " << flush;
        getline(cin, input);

        if (input != "stop") {
            stringList.reserve(stringList.size() + 1);
            stringList.push_back(input);
        } else {
            break;
        }
    }

    cout << "\nOriginal:" << endl;
    for(auto x : stringList){
        cout << x << endl;
    }

    backwards(stringList);

    cout << "\nBackwards:" << endl;
    for(auto x : stringList){
        cout << x << endl;
    }

    return 0;
}

void backwards(vector<string> &list){
    for(auto& x : list){
        reverse(x.begin(), x.end());
    }
    sort(list.begin(), list.end(), greater <>());
}