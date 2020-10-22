// Importamos las cabeceras de los módulos que necesitamos
#include <iostream> // entrada/salida, define las variables cin y cout (console)
#include <string> // cadenas de caracteres de la biblioteca estándar (STL)

// Clases anidadas:
#include "Date.h"
#include "Coche.h"
#include "ListaCoches.h"
#include "Alquiler.h"
#include "ListaAlquileres.h"

using namespace std; /* para nombrar sin cualificar con std:: */

#pragma region METODOS

int main(int argc, char* argv[]) // Argumentos: Array de cadenas estilo C
{	
	ListaCoches listaC = ListaCoches();
	//ListaAlquileres listaA;

	string file = "coches.txt";
	string file2 = "rent.txt";

	//estos métodos devuelven true o false o hay que pillar la excepción
	listaC.cargarCoches(file);
	//listaA.leerAlquileres(file2);

	// MENU PRINCIPAL:
	cout << "~ MENU PRINCIPAL ~" << endl << endl
		<< "Escoge una opcion: " << endl
		<< " 1 -> Mostrar Coches " << endl
		<< " 2 -> Mostrar Alquileres " << endl
		<< " 3 -> Agregar Coche " << endl
		<< " 4 -> Agregar Alquiler " << endl
		<< " 5 -> Salir del Programa " << endl << endl;

	

	bool exit = false;
	while (!exit)
	{
		int opt;
		cout << "Entrada usuario: ";
		cin >> opt;
		cout << endl;
		--opt; // ¿es igual que opt--?

		switch (opt)
		{
		case 0:
			//cout << "Mostrar Coches" << endl;
			listaC.print();
			break;
		case 1:
			cout << "Mostrar Alquileres" << endl;
			break;
		case 2:
			//cout << "Agregar Coche" << endl;
			listaC.añadirCoche();
			break;
		case 3:
			cout << "Agregar Alquiler" << endl;
			break;
		case 4:
			cout << "Salir del Programa" << endl;
			exit = true;
			break;
		default:
			break;
		}
		cout << endl;
	}

	listaC.del();
	//delete[] listaA.rents;

	system("pause"); // -> módulo utilsSystem
	return 0;
}

#pragma endregion