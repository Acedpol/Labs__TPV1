#include <iostream>
#include "Alquiler.h"

void Alquiler::print() const
{
	cout << codigoCoche << ' ' << fecha << ' ' << dias << endl;
}