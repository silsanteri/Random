// Exercise 7

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator> 
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <ios>
#include <limits>
#include <iomanip>
#include <sstream>

using namespace std;

void printer(int num);

class RandGen {
private:
    vector<int> numbers;
    int min, max;
public:
    RandGen(int small = 1, int big = 10) : min(small), max(big), numbers() {srand(time(NULL));}
    int operator()();
};

int main() {
    string input = "yes";
    int idx = 0;
    vector<int> normal(7), viking(6), euro(5), temp1, temp2;
    RandGen normalNum(1, 40), vikingNum(1, 48), euroNum(1, 50);
    
    auto iprinter = [idx = 0](const int& i) mutable{ idx++; cout << "\n#" << idx << ": " << i; };

    while(input.compare("yes") == 0){
        temp1.clear();
        temp2.clear();

        generate(normal.begin(), normal.end(), normalNum);
        generate(viking.begin(), viking.end(), vikingNum);
        generate(euro.begin(), euro.end(), euroNum);

        cout << "Normal Lotto:";
        for_each(normal.begin(), normal.end(), printer);

        cout << "\nViking Lotto:";
        for_each(viking.begin(), viking.end(), printer);

        sort(normal.begin(), normal.end());
        sort(viking.begin(), viking.end());
        set_intersection(normal.begin(), normal.end(), viking.begin(), viking.end(), back_inserter(temp1));

        cout << "\nMatching numbers:";
        if(temp1.empty()){
            cout << "\nNo matching numbers.";
        } else {
            for_each(temp1.begin(), temp1.end(), iprinter);
        }

        cout << "\nEurojackpot:";
        for_each(euro.begin(), euro.end(), printer);

        sort(temp1.begin(), temp1.end());
        sort(euro.begin(), euro.end());
        set_intersection(temp1.begin(), temp1.end(), euro.begin(), euro.end(), back_inserter(temp2));

        cout << "\nMatching numbers in three sets:";
        if(temp2.empty()){
            cout << "\nNo matching numbers.";
        } else {
            for_each(temp2.begin(), temp2.end(), iprinter);
        }

        cout << "\nContinue?: ";
        getline(cin, input);
    }

    return 0;
}

void printer(int num){
    cout << ' ' << num;
}

int RandGen::operator()() {
    int number;
    do {
        number = rand() % this->max + this->min;
    } while(find(this->numbers.begin(), this->numbers.end(), number) != this->numbers.end());
    this->numbers.push_back(number);
    return number;
}