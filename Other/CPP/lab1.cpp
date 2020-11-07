#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <ios>
#include <time.h>
#include <limits>

using namespace std;

int mean(int* array, int n);

int main()
{
    bool validInput = false;
    int numCount = 0, average = 0;
    int* numbers;

    do
    {
        cout << "Enter an integer between 1-100: " << flush;
        cin >> numCount;

            if (cin.good() && numCount > 0 && numCount <= 100) {
                validInput = true;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input!" << endl;
            }
       
    } while (!validInput);

    numbers = new int[numCount];

    srand((unsigned)time(NULL));
    for (int i = 0; i < numCount; i++) {
        numbers[i] = rand() % 100;
        cout << "Number " << i+1 << ": " << numbers[i] << endl;
    }

    average = mean(numbers, numCount);
    cout << "Average of numbers: " << average;

    delete[] numbers;
    return 0;
}

int mean(int* array, int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += array[i];
    }

    return total / n;
}