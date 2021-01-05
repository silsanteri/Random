// Exercise 11 (Normal)

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


class Observer {
	public:
		virtual void HandleLimitReached() = 0;
};

class Counter {
	public:
		virtual void inc() = 0;
		virtual void dec() = 0;
		virtual operator int() = 0;
		virtual ~Counter() {};
};

class OverflowCounter : public Counter {
	public:
		OverflowCounter(int val = 0, int lim = 0) : value(val), limit(lim) {}
		
		void inc() override { 
			if(this->value < this->limit){
				this->value++;
			} else {
				this->Notify();
				this->value = 0;
			}
		};

		void dec() override { 
			if(this->value > 0) this->value--;
			else this->value = this->limit;
		};
		
		// Allows CounterUser to set limit.
		void setLimit(int num){
			if(num > 0 && num <= 99){
				this->limit = num;
			}
		}

		operator int() { return this->value; };

		void SetObserver(Observer *temp){ this->obs = temp;};
	private:
		Observer* obs;
		void Notify() { obs->HandleLimitReached(); };
		int limit;
		int value;
};

class CounterUser : public Observer {
	public:
		CounterUser(int lim = 0){ this->counter.setLimit(lim); this->counter.SetObserver(this); }

		void IncrementBy(int num){ 
			if(num < 0){
				num = num * -1;
				for(int i = 0; i < num; i++) this->counter.dec();
			} else {
				for(int i = 0; i < num; i++) this->counter.inc();
			}
		};
		void HandleLimitReached() override { std::cout << "Limit has been reached!" << std::endl; };
	private:
		OverflowCounter counter;
};

int main(){
	CounterUser cu(5);
	cu.IncrementBy(12); //OUTPUT: two times "Limit has been reached"
	CounterUser cu2(9);
	cu2.IncrementBy(9);
	std::cout << "Just passing time" << std::endl;
	cu2.IncrementBy(1); //OUTPUT: "Limit has been reached"
	return 0;
}
