#pragma once
#include <iostream>

using std::ostream;

struct Location
{
	// public variables
	int _row;
	int _column;

	//constructors
	Location();
	Location(int, int);

	// operators - as member
	friend ostream& operator<<(ostream&, const Location&);
	bool operator==(const Location&) const;
	bool operator!=(const Location&) const;
	void operator+=(const Location&);
	void operator=(const Location& other);

};

// operator - as non-member
Location operator+(const Location&, const Location&);
