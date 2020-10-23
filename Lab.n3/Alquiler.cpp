#include <iostream>
#include "Alquiler.h"

void Alquiler::print() const
{
	cout << codigoCoche << ' ' << fecha << ' ' << dias << endl;
}

void Alquiler::mostrarAlquiler() const
{
	if (coche != nullptr)
	{
		fecha.print();
		cout << coche->getModelo() << " "
			<< dias << " dia(s) por "
			<< coche->getPrecio() * dias
			<< " euros" << endl;
	}
	else
	{
		fecha.print();
		cout << " ERROR: Modelo Inexistente"
			<< " euros" << endl;
	}
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
