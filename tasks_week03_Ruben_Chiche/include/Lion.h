#pragma once
#include "Animal.h"

class Lion : public Animal
{
public:
	// constructor
	Lion(const string&, const Location&);

	// public methods
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
	void move() override;
};
