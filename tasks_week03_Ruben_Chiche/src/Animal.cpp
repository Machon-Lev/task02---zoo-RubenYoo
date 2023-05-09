#include "Animal.h"

using std::string;
using std::cout;

// constructor with 2 params
Animal::Animal(const string& name, const Location& location)
{
	_name = name;
	_location = location;
	_canMove = false;
}

// printing the detail of an animal
void Animal::printDetails() const
{
	cout << "Name: " << _name << ", type: " << typeid(*this).name() << ", location: " << _location;
}

// return the location of an animal
Location Animal::getLocation() const
{
	return _location;
}

// stop an animal
void Animal::stop()
{
	_canMove = false;
}

