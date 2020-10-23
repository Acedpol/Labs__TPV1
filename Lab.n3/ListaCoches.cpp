#include <iostream>
#include <fstream>
#include "ListaCoches.h"

using namespace std;

bool ListaCoches::cargarCoches(string const& fichEntrada)
{
	ifstream input;
	input.open(fichEntrada);

	if (input.is_open()) //throw(Error(“No se encuentra el fichero”)); 
	{
		input >> tam;
		//tam += 10;
		cars = new Coche[tam];
		int i = 0;
		while (!input.fail() && i < tam)
		{
			int c, p;
			string m;
			input >> c;
			input >> p;
			getline(input, m);
			if (!input.fail())
			{
				cars[i] = Coche(c, p, m);
				i++;
				cont++;
			}
			
			/*cars[i] >> input;
			if (!input.fail())
			{
				i++;
				cont++;
			}*/
		}
		input.close();
		return true;
	}
	else
	{
		input.close();
		cout << "¡No se ha podido cargar el fichero!" << endl;
		return false;
	}
}

Coche* ListaCoches::buscarCoche(int code) const
{
	Coche* c = nullptr;
	int i = 0;
	while (i < tam && c == nullptr)		//deberia ser un for
	{
		if (cars[i] == code)
		{
			c = &cars[i];
		}
		i++;
	}
    return c;
}

void ListaCoches::anadirCoche()
{
	if (cont >= tam) // Redimensiona la lista	 
	{
		//cout << "La lista está completa. No hay hueco disponible." << endl;
		tam *= 2;
		Coche* aux = new Coche[tam];
		int i = 0;
		while (i < cont)
		{
			aux[i] = cars[i];
			i++;
		}
		delete[] cars;
		cars = aux;
		//anadirCoche();		
	}
	Coche car;
	car >> cin;
	cars[cont] = car;
	cont++;
}

void ListaCoches::print() const
{
	int i = 0;
	cout << "~ Lista Coches ~" << endl;
	while (i < cont)
	{
		cout << i << " -> ";
		cars[i].print();
		i++;
	}
}