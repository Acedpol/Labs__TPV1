#include <string>
#include "Coche.h"

#pragma once
class ListaCoches
{
private:
	Coche** cars;
	int tam;
	int cont;

public:
	ListaCoches() : cars(nullptr), tam(0), cont(0) {};
	bool cargarCoches(string const& fichEntrada);
	Coche* buscarCoche(int code) const;
	void anadirCoche();
	void print() const;
	void del() { delete[] cars; };
};

