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
	bool operator==(const int code);
	istream& operator>>(istream& in);
	int getPrecio() { return precio; };
	string getModelo() { return modelo; };
};

