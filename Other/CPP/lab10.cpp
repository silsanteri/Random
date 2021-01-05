// Exercise 10

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

class Counter {
	public:
		virtual void inc() = 0;
		virtual void dec() = 0;
		virtual operator int() = 0;
		virtual ~Counter() {};
};

class LimitedCounter : public Counter {
	public:
		LimitedCounter(int iv = 0, int ul = 0) : value(iv), limit(ul) {}
		void inc() override { if(value < limit) value++; };
		void dec() override { if(value > 0) value--; };
		operator int() { return value; };
	private:
		int limit;
		int value;
};

class OverflowCounter : public Counter {
	public:
		OverflowCounter(int iv = 0, int ul = 0) : value(iv), limit(ul) {}
		
		void inc() override { 
			if(value < limit) value++;
			else value = 0;
		};

		void dec() override { 
			if(value > 0) value--;
			else value = limit;
		};
		
		operator int() { return value; };
	private:
		int limit;
		int value;
};

void UseCounter(Counter& ctr, int num){
	if(num < 0){
		num = num * -1;
		for(int i = 0; i < num; i++) ctr.dec();
	} else {
		for(int i = 0; i < num; i++) ctr.inc();
	}
}

int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	std::cout << oc << std::endl;
	UseCounter(oc, 5);
	std::cout << oc << std::endl; // should display zero
	UseCounter(oc, -1);
	std::cout << oc << std::endl; // should display 9
	oc.dec();
	std::cout << oc << std::endl; // should display 8

	std::cout << lc << std::endl;
	lc.inc();
	std::cout << lc << std::endl;
	lc.dec();
	std::cout << lc << std::endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	std::cout << lc << std::endl;
	UseCounter(lc, -9);
	std::cout << lc << std::endl;

	return 0;
}