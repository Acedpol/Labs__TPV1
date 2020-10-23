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

bool ListaAlquileres::CompAlquileres(const Alquiler A1,const Alquiler A2)
{
	// Recuerda: AA/MM/DD
	Date f1 = A1.getFecha();
	Date f2 = A2.getFecha();
	return f1 < f2;
}

void ListaAlquileres::ordenarAlquileres()
{
	//sort(&rents[0], &rents[cont - 1], CompAlquileres);
}

void ListaAlquileres::a�adirAlquiler()
{
	if (cont < tam)
	{
		Alquiler rent;
		rent >> cin;
		rents[cont] = rent;
		cont++;
	}
	else // Redimensiona la lista
	{
		//cout << "La lista est� completa. No hay hueco disponible." << endl;
		tam += 10;
		Alquiler* aux = new Alquiler[tam];
		int i = 0;
		while (i < cont)
		{
			aux[i] = rents[i];
			i++;
		}
		delete[] rents;
		rents = aux;
		a�adirAlquiler();
	}
}

void ListaAlquileres::mostrarAlquileres() 
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