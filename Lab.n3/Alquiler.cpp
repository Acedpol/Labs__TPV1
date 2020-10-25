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

// *Al profesor no le mola que escriba por pantalla mientras pido datos*
istream& operator>>(istream& in, Alquiler& a)
{
	cout << "Codigo Coche: ";
	in >> a.codigoCoche;
	cout << "Fecha AA/MM/DD: ";
	in >> a.fecha;
	cout << "Dias: ";
	in >> a.dias;
	return in;
}
