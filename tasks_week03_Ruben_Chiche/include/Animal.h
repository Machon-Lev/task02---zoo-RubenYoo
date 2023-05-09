#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Location.h"

using std::string;

constexpr auto ROWS = 20;
constexpr auto COLUMNS = 40;


class Animal
{
public:
	// constructor
	Animal(const string&, const Location&);

	// destructor
	virtual ~Animal() = default;

	// pure virtual methods
	virtual char getInitial() const = 0;
	virtual void step() = 0;
	virtual void turnVertically() = 0;
	virtual void turnHorizontally() = 0;
	virtual void move() = 0;

	// public methods
	void printDetails() const;
	Location getLocation() const;
	void stop();
	

protected:
	// protected variables
	string _name;
	Location _location;
	Location _direction;
	bool _canMove;
	int _speed;
};
