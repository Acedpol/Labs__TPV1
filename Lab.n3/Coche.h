#include <string>

using namespace std; // para poder declarar string's

#pragma once
class Coche
{
private:
	int codigo;
	int precio; // por dia
	string modelo;
	
public:
	Coche() : codigo(0), precio(0), modelo("No declarado") {};
	Coche(int c, int p, string m) : codigo(c), precio(p), modelo(m) {};
	void print() const;	
	int getPrecio() { return precio; };
	int getCodigo() { return codigo; };
	string getModelo() { return modelo; };
	bool operator==(const Coche& c) const;
	friend istream& operator>>(istream& in, Coche* c);
};

istream& operator>>(istream& in, Coche* c); // funcion externa friendly
//istream& operator>>(istream& in, Coche& c); // funcion externa friendly

