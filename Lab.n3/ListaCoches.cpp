#include <iostream>
#include <fstream>
#include "ListaCoches.h"

using namespace std;

void ListaCoches::cargarCoches(string const& fichEntrada)
{
	ifstream input;
	input.open(fichEntrada);

	if (input.is_open()) //throw(Error(“No se encuentra el fichero”)); -> esto sobra, con el if salva la excepcion
	{
		input >> tam;
		tam += 10;
		cars = new Coche[tam];
		int i = 0;
		while (!input.fail() && i < tam)
		{
			int c, p;
			string m;
			input >> c;
			input >> p;
			getline(input, m);
			cars[i] = Coche(c, p, m);
			i++;
			cont++;
		}
		input.close();
	}
	else
	{
		input.close();
		cout << "¡No se ha podido cargar el fichero!" << endl;
	}
}

Coche* ListaCoches::buscarCoche(int code, const ListaCoches& listaC)
{
	Coche* c = nullptr;
	int i = 0;
	while (i < tam)
	{
		if (cars[i] == code)
		{
			c = &cars[i];
		}
		i++;
	}
    return nullptr;
}

void ListaCoches::print() const
{
	int i = 0;
	cout << "~ Lista Coches ~" << endl;
	while (i < cont - 1)
	{
		cars[i].print();
		i++;
	}
}