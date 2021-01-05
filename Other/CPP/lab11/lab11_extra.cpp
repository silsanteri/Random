// Exercise 11 (Extra)

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

class CounterObserver;
class Counter {
	public:
		virtual void inc() = 0;
		virtual void dec() = 0;
		virtual void SetObserver(CounterObserver *) = 0;
		virtual operator int() = 0;
		virtual ~Counter() {};
};

class CounterObserver {
	public:
		virtual void HandleLimitReached(Counter *ctr) = 0;
};

class LimitedCounter : public Counter {
	public:
		LimitedCounter(int iv = 0, int ul = 0) : value(iv), limit(ul) {}
		void inc() override { 
			if(this->value < this->limit) this->value++;
			else if(this->value == this->limit) Notify();
		};

		void dec() override { if(this->value > 0) this->value--; };

		operator int() override { return this->value; };

		void SetObserver(CounterObserver *temp) override { observer.push_back(temp);};
	private:
		void Notify() { for(auto& i : observer) i->HandleLimitReached(this); };
		int limit;
		int value;
		std::vector<CounterObserver*> observer;
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

		operator int() override { return this->value; };

		void SetObserver(CounterObserver *temp) override { observer.push_back(temp); };
	private:
		void Notify() { for(auto& i : observer) i->HandleLimitReached(this); };
		int limit;
		int value;
		std::vector<CounterObserver*> observer;
};

class Observer : public CounterObserver {
	public:
		Observer(){}

		void setOC(OverflowCounter *ctr){
			this->oc = ctr;
			this->oc->SetObserver(this);
		};

		void setLC(LimitedCounter *ctr){
			this->lc = ctr;
			this->lc->SetObserver(this);
		};

		void HandleLimitReached(Counter *ctr) override { std::cout << "Limit has been reached! Current counter value: " << (*ctr) << std::endl; };
	private:
		OverflowCounter* oc;
		LimitedCounter* lc;
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
	OverflowCounter oc(0, 5);
	LimitedCounter lc2(0, 9);
	OverflowCounter oc2(0, 9);

	Observer lco;
	Observer oco;
	Observer both;

	lco.setLC(&lc);
	oco.setOC(&oc);
	both.setLC(&lc2);
	both.setOC(&oc2);

	UseCounter(oc, 6);
	UseCounter(oc, -1);
	oc.dec();
	lc.inc();
	lc.dec();
	for(int i = 0; i < 10; ++i) lc.inc();
	UseCounter(lc, -9);

	UseCounter(oc, 12); //OUTPUT: two times "Limit has been reached"
	UseCounter(oc2, 9);
	UseCounter(oc2, 1); //OUTPUT: "Limit has been reached"

	UseCounter(lc, 12); //OUTPUT: two times "Limit has been reached"
	UseCounter(lc2, 8);
	UseCounter(lc2, 1); //OUTPUT: "Limit has been reached"

	return 0;
}