// Exercise 12

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
#include <memory>
#include <exception>

class UniqueRNG {
private:
    std::vector<int> numbers;
    int min, max;
public:
    UniqueRNG(int small = 1, int big = 10) : min(small), max(big), numbers() {
        // Should probably make checks to make sure max is always bigger than min,
        // but I don't think it's necessary for this kind of program.
        srand(time(NULL));
    }

    bool compSize(int count){
        int size = this->max - this->min + 1;
        if (size >= count){
            return true;
        } else {
            std::string throwString =   "Exception: Unable to produce unique random numbers\nTried to generate "
                                        + std::to_string(count) + " random numbers, but the limit amount is "
                                        + std::to_string(size);

            throw std::runtime_error(throwString);
            return false;
        }
    }

    void clearNumbers(){
        numbers.clear();
    }

    int operator()(){
        int number;
        do {
            number = rand() % (this->max - this->min + 1) + this->min;
        } while(find(this->numbers.begin(), this->numbers.end(), number) != this->numbers.end());
        this->numbers.push_back(number);
        return number;
    };
};

void test_generator(UniqueRNG ur, int count){
    std::cout << "Generating numbers:" << std::endl;
    std::vector<int> numbers(count);

    try {
        if(ur.compSize(count)){
            std::generate(numbers.begin(), numbers.end(), ur);
            for(auto& i : numbers) std::cout << i << std::endl;
        }
    } catch (std::runtime_error& error){
        std::cout << error.what() << std::endl;
    }

    ur.clearNumbers();
    std::cout << "End of generator" << std::endl;
}


int main(void) {
    UniqueRNG randGen(5, 13);
    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRNG randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);

    return 0;
}