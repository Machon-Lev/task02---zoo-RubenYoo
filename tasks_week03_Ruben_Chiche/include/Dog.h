#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	// constructor
	Dog(const string&, const Location&);
	
	// public methods
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
	void move() override;
};
