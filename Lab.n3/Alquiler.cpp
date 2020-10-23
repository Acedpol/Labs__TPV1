#include <iostream>
#include "Alquiler.h"

void Alquiler::print() const
{
	cout << codigoCoche << ' ' << fecha << ' ' << dias << endl;
}

istream& Alquiler::operator>>(istream& in)
{
	cout << "Codigo Coche: ";
	in >> codigoCoche;
	cout << "Fecha AA/MM/DD: ";
	in >> fecha;
	cout << "Dias: ";
	in >> dias;
	return in;
}
