#include "Shark.h"

// constructor with 2 params
Shark::Shark(const string& name, const Location& location)
	: Animal(name, location)
{
	_speed = 5;
	move();
}

// return the first letter of the class
char Shark::getInitial() const
{
	return 'S';
}

// make a step
void Shark::step()
{
	if (!_canMove)
		return;

	// do the steps
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
}

// turn the directon of the animal vertically
void Shark::turnVertically()
{
	_direction._row *= -1;
}

// turn the directon of the animal horizontally
void Shark::turnHorizontally()
{
	_direction._column *= -1;
}

// make the Shark move again
void Shark::move()
{
	if (_canMove)
		return;

	do
	{
		_direction = Location((rand() % 3) - 1, (rand() % 3) - 1);

	} 
	// case the random direction is to not move
	while (_direction._row == 0 && _direction._column == 0);

	_canMove = true;
}
