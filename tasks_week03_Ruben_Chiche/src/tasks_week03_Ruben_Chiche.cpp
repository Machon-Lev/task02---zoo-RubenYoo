#include <iostream>
#include "Animal.h"
#include "Lion.h"
#include "Zoo.h"

int main()
{
	// seed for rand
	srand(time(0));

	Zoo myZoo;
	myZoo.run();

	return 0;
}
