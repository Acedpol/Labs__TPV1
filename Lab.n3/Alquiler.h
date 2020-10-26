#pragma once
#include <string>
#include "Date.h"
#include "Coche.h"


using namespace std; // para poder declarar string's

class Alquiler
{
private:
	int codigoCoche;
	Coche* coche;
	Date fecha;
	int dias;		//nº de dias

public:
	Alquiler() : codigoCoche(0), coche(nullptr), fecha(), dias(0) {};
	Alquiler(int cod, Coche* c, Date f, int d) : codigoCoche(cod), coche(c), fecha(f), dias(d) {};
	Date getFecha() const { return fecha; };
	int getCodeCar() const { return codigoCoche; };
	void setPointerCar(Coche* car) { coche = car; };
	void print() const;
	void mostrarAlquiler() const;
	friend istream& operator>>(istream& in, Alquiler& a);
};

istream& operator>>(istream& in, Alquiler& a);