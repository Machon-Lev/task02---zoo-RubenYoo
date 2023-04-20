#pragma once
#include "Animal.h"

using std::string;

class Shark : public Animal
{
public:
	//contructor
	Shark(const string&, const Location&);

	// public methods
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
	void move() override;
};
