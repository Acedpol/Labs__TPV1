#include <iostream>
#include "Coche.h"

void Coche::print() const
{
	cout << codigo << ' ' << precio << modelo << endl;
}

bool Coche::operator==(const Coche& c) const
{
	bool equal = false;
	if (codigo == c.codigo)
	{
		equal = true;
	}
	return equal;
}

// *Al profesor no le mola que escriba por pantalla mientras pido datos*
istream& operator>>(istream& in, Coche& c) 
{
	cout << "Codigo: ";
	in >> c.codigo;
	cout << "Precio: ";
	in >> c.precio;
	cout << "Modelo: ";
	in >> c.modelo;
	string modAux;
	getline(cin, modAux); // por si tiene 2 palabras el modelo introducido
	c.modelo = " " + c.modelo + modAux;
	return in;
}
