#include <string>
#include "Coche.h"

#pragma once
class ListaCoches
{
private:
	Coche* cars;
	int tam;
	int cont;

public:
	ListaCoches() : cars(nullptr), tam(0), cont(0) {};
	void cargarCoches(string const& fichEntrada);
	Coche* buscarCoche(int code) const;
	void añadirCoche();
	void print() const;
	void del() { delete[] cars; };
};

