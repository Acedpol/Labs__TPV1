#include <iostream>
#include <fstream>
#include "ListaAlquileres.h"
bool ListaAlquileres::leerAlquileres(string const& fichEntrada)
{
	ifstream input;
	input.open(fichEntrada);

	if (input.is_open()) //throw(Error(“No se encuentra el fichero”));
	{
		input >> tam;
		//tam += 10;
		rents = new Alquiler[tam];
		int i = 0;
		while (!input.fail() && i < tam)
		{
			int cod, dias;
			input >> cod;
			input >> cod;//fecha
			input >> dias;

			if (!input.fail()) {
				rents[i] = Alquiler(cod, nullptr, ,dias);
				i++;
				cont++;
			}

			//input >> listaA.rents[i].codigo;
			//char c; // ignora las '/'
			//input >> listaA.rents[i].f.ano;
			//input >> c;
			//input >> listaA.rents[i].f.mes;
			//input >> c;
			//input >> listaA.rents[i].f.dia;
			//input >> listaA.rents[i].numDias;
			//listaA.rents[i].puntCoche = buscarCoche(listaA.rents[i].codigo, listaC);
			//i++;
			//listaA.cont++;
		}
		//mostrarListaA(listaA);
		input.close();
		return true;
	}
	else
	{
		input.close();
		return false;
	}
}

void ListaAlquileres::ordenarAlquileres()
{

}