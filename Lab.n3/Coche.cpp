#include <iostream>
#include "Coche.h"

istream& Coche::operator>>(istream& in)
{
	cout << "Codigo: ";
	in >> codigo;
	cout << "Precio: ";
	in >> precio;
	cout << "Modelo: ";
	in >> modelo;
	string modAux;
	getline(cin, modAux); // por si tiene 2 palabras el modelo introducido
	modelo = " " + modelo + modAux;
	return in;
}

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

//istream& operator>>(istream& in, Coche& c)
//{
//	cout << "Codigo: ";
//	in >> c.codigo;
//	cout << "Precio: ";
//	in >> precio;
//	cout << "Modelo: ";
//	in >> modelo;
//	string modAux;
//	getline(cin, modAux); // por si tiene 2 palabras el modelo introducido
//	modelo = " " + modelo + modAux;
//	return in;
//}
