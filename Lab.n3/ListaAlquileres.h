#pragma once

#include <string>
#include <algorithm> // sort
#include "Alquiler.h"
#include "ListaCoches.h"

class ListaAlquileres
{
private:
	Alquiler* rents;
	int tam;
	int cont;
	bool CompAlquileres(const Alquiler A1, const Alquiler A2);

public:
	ListaAlquileres() : rents(nullptr), tam(0), cont(0) {};
	bool leerAlquileres(string const& fichEntrada, const ListaCoches& listaC) ;
	void ordenarAlquileres() ;
	void a�adirAlquiler();
	void mostrarAlquileres();
	void print() const;
	void del() { delete[] rents; };
};

