// Exercise 2B

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <ios>
#include <time.h>
#include <limits>

using namespace std;

int main()
{
    vector<string> stringList;
    string input = "", longest = "";

    cout << "Enter strings: " << flush;

    while (1){
        getline(cin, input);

        if (input != "stop") {
            stringList.reserve(stringList.size() + 1);
            stringList.push_back(input);
        } else {
            break;
        }
    }

    cout << "\nNumber of strings: " << stringList.size() << endl;

    for(auto x : stringList){
        cout << x << endl;

        if(x.length() > longest.length()){
            longest = x;
        }
    }
    cout << "Longest string: " << longest << " (" << longest.length() << ")" << endl;
    cout << "Vector Size: " << stringList.size() << " - Vector Capacity: " << stringList.capacity() << endl;

    return 0;
}