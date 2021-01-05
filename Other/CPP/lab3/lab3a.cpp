// Exercise 3A

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

int main()
{
    vector<double> numbers;
    double input = 0;

    while (1)
    {
        cout << "Enter a double: " << flush;
        cin >> input;

            if (cin.good() && input >= 0) {
                numbers.reserve(numbers.size() + 1);
                numbers.push_back(input);
            } else if (cin.good() && input < 0){
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input!" << endl;
            }
       
    }

    sort(numbers.begin(), numbers.end());
    cout.precision(3);

    for (auto x : numbers){
        cout << fixed << x << endl;
    }

    return 0;
}