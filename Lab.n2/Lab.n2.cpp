// Importamos las cabeceras de los módulos que necesitamos
#include <iostream> // entrada/salida, define las variables cin y cout (console)
#include <string> // cadenas de caracteres de la biblioteca estándar (STL)
#include <fstream> // entrada/salida de ficheros de texto

using namespace std; /* para nombrar sin cualificar con std:: */

#pragma region STRUCTS

struct Coche {
	int codigo;
	int precio; // por dia
	string modelo;
	//Coche(int c, int p, string m): codigo(c), precio(p), modelo(m) {}; **ESTA LINEA ES PUTA MIERDA** -> (el constructor está bien hecho, pero en los structs no se hace y me ha dado mazo problemas)
};

struct ListaCoches {
	Coche* cars; // array dinamico
	int tam = 0; // tamaño escalable
};

#pragma endregion

#pragma region METODOS

void mostrarListaC(ListaCoches& listaC)
{
	int i = 0;
	while (i < listaC.tam)
	{
		cout << listaC.cars[i].codigo << ' ' << listaC.cars[i].precio << ' ' << listaC.cars[i].modelo << endl;
		i++;
	}
}

bool cargarCoches(string const& fichEntrada, ListaCoches& listaC) 
{
	ifstream input;
	input.open(fichEntrada);	

	if (input.is_open()) //throw(Error(“No se encuentra el fichero”)); -> esto sobra, con el if salva la excepcion
	{
		int cont;
		input >> listaC.tam; // hay 'X' coches
		listaC.cars = new Coche[listaC.tam];
		int i = 0;
		while (!input.fail() && i < listaC.tam) 
		{
			input >> listaC.cars[i].codigo;
			input >> listaC.cars[i].precio;
			getline(input, listaC.cars[i].modelo); // asi es como se usa :)
			i++;
		}
		input.close();
		mostrarListaC(listaC);
		//delete[] listaC.cars;
		return true;
	} 
	else 
	{
		input.close();
		return false;
	}	
}

#pragma endregion

int main(int argc, char* argv[]) // Argumentos: Array de cadenas estilo C
{ 
	ListaCoches listaC;
	string file = "coches.txt";

	cargarCoches(file, listaC);
	delete[] listaC.cars;
	system("pause"); // -> módulo utilsSystem
	return 0;
}