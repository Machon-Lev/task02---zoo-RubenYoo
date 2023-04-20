#include "Dog.h"

// constructor with 2 params
Dog::Dog(const string& name, const Location& location)
	: Animal(name, location)
{
	_speed = 3;
	move();
}

// return the first letter of the class
char Dog::getInitial() const
{
	return 'D';
}

// make a step
void Dog::step()
{
	if (!_canMove)
		return;

	// do the step(s)
	for (size_t i = 0; i < _speed; i++)
	{
		Location maxVerification = _location + _direction;
		if (maxVerification._column == COLUMNS || maxVerification._row == ROWS || maxVerification._column == -1 || maxVerification._row == -1)
		{
			turnHorizontally();
			turnVertically();
		}
		_location += _direction;
	}

	// changing the direction 
	turnHorizontally();
	turnVertically();

	// changing the speed
	if (_speed == 1)
		_speed = 3;
	else
		_speed = 1;
	
}

// turn the directon of the animal vertically
void Dog::turnVertically()
{
	_direction._row *= -1;
}

// turn the directon of the animal horizontally
void Dog::turnHorizontally()
{
	_direction._column *= -1;
}

// make the Dog move again
void Dog::move()
{
	if (_canMove)
		return;

	if (rand() % 2 == 0)
		_direction = Location(0, rand() % 2 ? -1 : 1);
	else
		_direction = Location(rand() % 2 ? -1 : 1, 0);

	_canMove = true;
}
