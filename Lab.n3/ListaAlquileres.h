#pragma once

#include <string>
#include "Alquiler.h"

class ListaAlquileres
{
private:
	Alquiler* rents;
	int tam;
	int cont;

public:
	ListaAlquileres() : rents(nullptr), tam(0), cont(0) {};
	bool leerAlquileres(string const& fichEntrada) {};
	void ordenarAlquileres() {};
	void a�adirAlquiler();
	void print() const;
	void del() { delete[] rents; };
};

