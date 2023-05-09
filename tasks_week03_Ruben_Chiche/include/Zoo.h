#pragma once
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Shark.h"
#include "Dog.h"

using std::vector;
using std::unique_ptr;

class Zoo
{
public:
	// public method
	void run();

private:
	// private vector of animals
	vector<unique_ptr<Animal>> animals;

	// private methods
	void stop(size_t) const;
	void move(size_t) const;
	void create(string, string);
	void del(size_t);
	void dellAll(string);
	void help() const;
	void point() const;
	void map() const;
};
