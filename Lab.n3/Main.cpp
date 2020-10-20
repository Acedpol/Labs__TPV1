// Importamos las cabeceras de los módulos que necesitamos
#include <iostream> // entrada/salida, define las variables cin y cout (console)
#include <string> // cadenas de caracteres de la biblioteca estándar (STL)

// Clases anidadas:
#include "Date.h"

using namespace std; /* para nombrar sin cualificar con std:: */

#pragma region METODOS

int main(int argc, char* argv[]) // Argumentos: Array de cadenas estilo C
{
	//ListaCoches listaC;
	//ListaAlquileres listaA;
	string file = "coches.txt";
	string file2 = "rent.txt";

	// MENU PRINCIPAL:
	cout << "~ MENU PRINCIPAL ~" << endl << endl
		<< "Escoge una opcion: " << endl
		<< " 1 -> Mostrar Coches " << endl
		<< " 2 -> Mostrar Alquileres " << endl
		<< " 3 -> Agregar Coche " << endl
		<< " 4 -> Agregar Alquiler " << endl
		<< " 5 -> Salir del Programa " << endl << endl;

	int opt;
	cout << "Entrada usuario: ";
	cin >> opt;
	--opt; // ¿es igual que opt--?
	switch (opt)
	{
	case 0:
		cout << "Mostrar Coches" << endl;
		break;
	case 1:
		cout << "Mostrar Alquileres" << endl;
		break;
	case 2:
		cout << "Agregar Coche" << endl;
		break;
	case 3:
		cout << "Agregar Alquiler" << endl;
		break;
	case 4:
		cout << "Salir del Programa" << endl;
		break;
	default:
		break;
	}

	//cargarCoches(file, listaC);
	//leerAlquileres(file2, listaA, listaC);
	//ordenarSinSort(listaA);
	//ordenarAlquileres(listaA);
	//mostrarAlquileres(listaA);

	//delete[] listaC.cars;
	//delete[] listaA.rents;

	system("pause"); // -> módulo utilsSystem
	return 0;
}

#pragma endregion