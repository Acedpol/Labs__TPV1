// Importamos las cabeceras de los m�dulos que necesitamos
#include <iostream> // entrada/salida, define las variables cin y cout (console)
#include <string> // cadenas de caracteres de la biblioteca est�ndar (STL)

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
	ListaAlquileres listaA = ListaAlquileres();

	string file = "coches.txt";
	string file2 = "rent.txt";

	//estos m�todos devuelven true o false o hay que pillar la excepci�n
	if(!listaC.cargarCoches(file) || !listaA.leerAlquileres(file2, listaC))
	{
		cout << "ERROR AL LEER FICHEROS";
	}

	bool exit = false;
	while (!exit)
	{
		// MENU PRINCIPAL:
		cout << "~ MENU PRINCIPAL ~" << endl << endl
			<< "Escoge una opcion: " << endl
			<< " 1 -> Mostrar Coches " << endl
			<< " 2 -> Mostrar Alquileres " << endl
			<< " 3 -> Agregar Coche " << endl
			<< " 4 -> Agregar Alquiler " << endl
			<< " 5 -> Ordenar Alquileres" << endl
			<< " 6 -> Mostrar Lista Final de Alquileres" << endl
			<< " 7 -> Salir del Programa " << endl << endl;

		int opt;
		cout << "Entrada usuario: ";
		cin >> opt;
		cout << endl;
		--opt; // �es igual que opt--?

		system("CLS"); // limpia la pantalla

		switch (opt)
		{
		case 0:
			//cout << "Mostrar Coches" << endl;
			listaC.print();
			break;
		case 1:
			//cout << "Mostrar Alquileres" << endl;
			listaA.print();
			break;
		case 2:
			//cout << "Agregar Coche" << endl;
			listaC.anadirCoche();
			break;
		case 3:
			//cout << "Agregar Alquiler" << endl;
			listaA.anadirAlquiler(listaC);
			break;
		case 4:
			cout << "Alquileres ordenados" << endl;
			listaA.ordenarAlquileres();
			break;
		case 5:
			//cout << "Mostrar Lista Final Alquileres" << endl;
			listaA.mostrarAlquileres();
			break;
		case 6:
			cout << "Salir del Programa" << endl;
			exit = true;
			break;
		default:
			break;
		}
		cout << endl;		
	}

	listaC.del();
	listaA.del();

	system("pause"); // -> m�dulo utilsSystem
	return 0;
}

#pragma endregion