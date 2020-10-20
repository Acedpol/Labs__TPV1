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