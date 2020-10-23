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
	string getModelo() { return modelo; };
	istream& operator>>(istream& in);
	bool operator==(const int code);
	//friend istream& operator>>(istream& in, Coche& c);
};

//bool operator==(const int code, int cod) 
//{
//	bool equal = false;
//	if (codigo == c)
//	{
//		equal = true;
//	}
//	return equal;
//}
istream& operator>>(istream& in, Coche& c);

