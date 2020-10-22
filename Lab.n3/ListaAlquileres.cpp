#include <iostream>
#include <fstream>
#include "ListaAlquileres.h"
bool ListaAlquileres::leerAlquileres(string const& fichEntrada, const ListaCoches& listaC) 
{
	ifstream input;
	input.open(fichEntrada);

	if (input.is_open()) //throw(Error(�No se encuentra el fichero�));
	{
		input >> tam;
		//tam += 10;
		rents = new Alquiler[tam];
		int i = 0;
		while (!input.fail() && i < tam)
		{
			int cod, dias;
			Date f;
			Coche* puntcoche;
			input >> cod;
			input >> f;
			input >> dias;

			if (!input.fail()) {
				puntcoche = listaC.buscarCoche(cod);
				rents[i] = Alquiler(cod, puntcoche, f,dias);
				i++;
				cont++;
			}
		}
		input.close();
		return true;
	}
	else
	{
		input.close();
		return false;
	}
}
bool CompAlquileres(const Alquiler A1,const Alquiler A2)
{
	// Recuerda: AA/MM/DD
	Date f1 = A1.getFecha();
	Date f2 = A2.getFecha();
	return f1 < f2;
}

void ListaAlquileres::ordenarAlquileres()
{
	sort(&rents[0], &rents[cont - 1], CompAlquileres);
}

void ListaAlquileres::print() const
{
	int i = 0;
	cout << "~ Lista Alquileres ~" << endl;
	while (i < cont)
	{
		cout << i << " -> ";
		rents[i].print();
		i++;
	}
}