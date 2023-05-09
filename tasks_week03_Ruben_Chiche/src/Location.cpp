#include "Location.h"

// constructor
Location::Location()
{
	_row = 0;
	_column = 0;
}

// constructor with 2 params
Location::Location(int row, int column)
{
	_row = row;
	_column = column;
}

// overloading the << operator
ostream& operator<<(ostream& out, const Location& other)
{
	out << "(" << other._row << "," << other._column << ")";
	return out;
}

// operator +
Location operator+(const Location& lhs, const Location& rhs)
{
	return Location(lhs._row + rhs._row, lhs._column + rhs._column);
}

// operator ==
bool Location::operator==(const Location& other) const
{
	return _row == other._row && _column == other._column;
}

// operator !=
bool Location::operator!=(const Location& other) const
{
	return !(_row == other._row && _column == other._column);
}

// operator +=
void Location::operator+=(const Location& other)
{
	_row += other._row;
	_column += other._column;
}

//operator =
void Location::operator=(const Location& other)
{
	_row = other._row;
	_column = other._column;
}
