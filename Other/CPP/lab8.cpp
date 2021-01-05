// Exercise 8

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

class Person {
	public:
		Person(const char* name_ = "nobody") : name(name_){}
		virtual ~Person() = default;
		virtual void identity() const;
		virtual void interrogate();
	private:
		std::string name;
};

class Spy: public Person {
	public:
		Spy(const char* name_ = "nobody", const char* alias_ = "nobody", const int resistance_ = 0) : Person(name_), alias(alias_), resistance(resistance_){}
		void identity() const;
		void interrogate();
		void set_identity(const char *alias_);
	private:
		std::string alias;
		int resistance;
};

int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}

void Person::identity() const{
	std::cout << "My name is: " << this->name << std::endl;
}

void Person::interrogate(){

}

void Spy::identity() const{
	if(this->resistance <= 0){
		Person::identity();
		std::cout << "My alias is: " << this->alias << std::endl;
	} else {
		std::cout << "My name is: " << this->alias << std::endl;
	}
}

void Spy::interrogate(){
	this->resistance--;
}

void Spy::set_identity(const char *alias_){
	this->alias = alias_;
}