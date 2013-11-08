#include <iostream>
#include <string>

#include "SmartPointer.h"

using namespace std;

class Person
{
public:
	static SmartPtr<Person> getInstance(const string &name);

	Person(const string name=""): name(name) 
	{
		cout << name << "'s constructor is invoked" << endl;
	}

	void print()
	{
		cout << "My name is " << name << endl;
	}

	~Person()
	{
		cout << name << "'s deconstructor is invoked" << endl;
	}

private:
	string name;
};

SmartPtr<Person> Person::getInstance(const string &name)
{
	return SmartPtr<Person>(new Person(name));
}

int main()
{
	SmartPtr<Person> sp1 = Person::getInstance("Jack");
	SmartPtr<Person> sp2 = Person::getInstance("Tom");
	
	cout << "***Test auto releasing***" << endl;
	{
		SmartPtr<Person> newSptr = sp1;
		(*newSptr).print();
	}
	sp1->print();

	cout << "***Test assignment***" << endl;
	sp1 = sp2;
	sp1->print();
	return 0;
}
