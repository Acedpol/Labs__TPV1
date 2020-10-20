#include <iostream>
#include "Coche.h"

void Coche::print() const
{
	cout << codigo << ' ' << precio << modelo << endl;
}

bool Coche::operator==(const int c) 
{
	bool equal = false;
	if (codigo == c)
	{
		equal = true;
	}
	return equal;
}
