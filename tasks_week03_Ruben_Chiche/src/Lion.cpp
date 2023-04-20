#include "Lion.h"
using namespace std;

// constructor with 2 params
Lion::Lion(const string& name, const Location& location)
	: Animal(name, location)
{
	_speed = 2;
	move();
}

// return the first letter of the class
char Lion::getInitial() const
{
	return 'L';
}

// make a step
void Lion::step()
{
	if (!_canMove)
		return;

	// do the steps
	for (size_t i = 0; i < _speed; i++)
	{
		Location maxVerification = _location + _direction;
		if (maxVerification._column == COLUMNS || maxVerification._column == -1)
		{
			turnHorizontally();
		}
		_location += _direction;
	}
}

// not relevant for the Lion
void Lion::turnVertically()
{
	return;
}

// turn the directon of the animal horizontally
void Lion::turnHorizontally()
{
	_direction._column *= -1;
}

// make the Lion move again
void Lion::move()
{
	if (_canMove)
		return;

	_direction = Location(0, rand() % 2 ? -1 : 1);
	_canMove = true;
}
