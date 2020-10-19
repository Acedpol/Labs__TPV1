// Importamos las cabeceras de los módulos que necesitamos
#include <iostream> // entrada/salida, define las variables cin y cout (console)
#include <string> // cadenas de caracteres de la biblioteca estándar (STL)
#include <fstream> // entrada/salida de ficheros de texto
#include <algorithm> // para el sort

using namespace std; /* para nombrar sin cualificar con std:: */

#pragma region STRUCTS
struct Fecha
{
	int ano;
	int mes;
	int dia;	
	Fecha() : ano(0), mes(0), dia(0) {};
	string toString() 
	{
		string date = to_string(ano) + '/' + to_string(mes) + '/' + to_string(dia);
		return date;
	};
};

struct Coche {
	int codigo;
	int precio; // por dia
	string modelo;
	Coche(): codigo(0), precio(0) {};
};

struct ListaCoches {
	Coche* cars; // array dinamico
	int tam = 0; // tamaño escalable
	int cont = 0; // Numero real de elementos
	ListaCoches() : cars(nullptr) {};
};

struct Alquiler {
	int codigo = {};
	//string fechaString;
	Fecha f;
	int numDias = {};
	Coche* puntCoche = {}; //puntero al coche al que hace referencia
};

struct ListaAlquileres {
	Alquiler* rents; // array dinamico
	int tam = 0; // tamaño escalable
	int cont = 0; // Numero real de elementos
	ListaAlquileres() : rents(nullptr) {};
};


#pragma endregion

#pragma region METODOS

void mostrarListaC(const ListaCoches& listaC)
{
	int i = 0;
	cout << "~ Lista Coches ~" << endl;
	while (i < listaC.cont - 1)
	{
		cout << i << " -> " << listaC.cars[i].codigo << ' ' << listaC.cars[i].precio << listaC.cars[i].modelo << endl;
		i++;
	}
}

void mostrarListaA(const ListaAlquileres& listaA)
{
	int i = 0;
	cout << "~ Lista Alquileres ~" << endl;
	while (i < listaA.cont - 1)
	{
		cout << i << " -> " << listaA.rents[i].codigo << ' ' << listaA.rents[i].f.toString() << ' ' << listaA.rents[i].numDias << endl;
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
		input >> listaC.tam;
		listaC.tam += 10;
		listaC.cars = new Coche[listaC.tam];
		int i = 0;
		while (!input.fail() && i < listaC.tam) 
		{
			input >> listaC.cars[i].codigo;
			input >> listaC.cars[i].precio;
			getline(input, listaC.cars[i].modelo);
			i++;
			listaC.cont++;
		}
		//mostrarListaC(listaC);
		input.close();
		return true;
	} 
	else 
	{
		input.close();
		return false;
	}	
}

Coche* buscarCoche(int code, const ListaCoches& listaC)
{
	Coche* c = nullptr;
	int i = 0;
	while (i < listaC.tam)
	{
		if (listaC.cars[i].codigo == code)
		{
			c = &listaC.cars[i];
		}
		i++;
	}
	return c;
}

bool leerAlquileres(string const& fichEntrada, ListaAlquileres& listaA, const ListaCoches& listaC)
{
	ifstream input;
	input.open(fichEntrada);	

	if (input.is_open()) //throw(Error(“No se encuentra el fichero”)); -> esto sobra, con el if salva la excepcion
	{
		input >> listaA.tam;
		listaA.tam += 10;
		listaA.rents = new Alquiler[listaA.tam];
		int i = 0;
		while (!input.fail() && i < listaA.tam)
		{
			input >> listaA.rents[i].codigo;
			char c; // ignora las '/'
			input >> listaA.rents[i].f.ano;
			input >> c;
			input >> listaA.rents[i].f.mes;
			input >> c;
			input >> listaA.rents[i].f.dia;
			input >> listaA.rents[i].numDias;
			listaA.rents[i].puntCoche = buscarCoche(listaA.rents[i].codigo, listaC);
			i++;
			listaA.cont++;			
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

// true si f1 es más pequeño / más antiguo. Por tanto f2 es más reciente.
bool Comparador(const Fecha f1,const Fecha f2) 
{
	// Recuerda: AA/MM/DD
	return (f1.ano < f2.ano ||
	       (f1.ano == f2.ano && f1.mes < f2.mes ||
		   (f1.mes == f2.mes && f1.dia < f2.dia)));
}

// true si f1 es más pequeño / más antiguo. Por tanto f2 es más reciente.
bool CompAlquileres(const Alquiler A1,const Alquiler A2) 
{
	Fecha f1 = A1.f;
	Fecha f2 = A2.f;
	// Recuerda: AA/MM/DD
	return (f1.ano < f2.ano ||
	       (f1.ano == f2.ano && f1.mes < f2.mes ||
		   (f1.mes == f2.mes && f1.dia < f2.dia)));
}

void ordenarAlquileres(ListaAlquileres& listaA)
{
	sort(&listaA.rents[0], &listaA.rents[listaA.cont - 1], CompAlquileres);
	mostrarListaA(listaA);
}

void ordenarSinSort(ListaAlquileres& listaA)
{
	int k = 0;
	while(k < listaA.cont - 1)
	{
		int i = k + 1;
		while (i < listaA.cont - 1)
		{
			if (Comparador(listaA.rents[i].f, listaA.rents[k].f))
			{
				Alquiler aux = listaA.rents[k];
				listaA.rents[k] = listaA.rents[i];
				listaA.rents[i] = aux;
			}
			i++;
		}
		k++;
	}
	//mostrarListaA(listaA);
}

void mostrarAlquileres(const ListaAlquileres& listaA)
{
	int i = 0;
	cout << "~ Lista Final de Alquileres ~" << endl;
	while (i < listaA.cont - 1)
	{
		if (listaA.rents[i].puntCoche != nullptr) 
		{
			cout << listaA.rents[i].f.toString()
				<< listaA.rents[i].puntCoche->modelo << " "
				<< listaA.rents[i].numDias << " dia(s) por "
				<< listaA.rents[i].puntCoche->precio * listaA.rents[i].numDias
				<< " euros" << endl;
		}
		else
		{
			cout << listaA.rents[i].f.toString() << " "
				<< "ERROR: Modelo Inexistente"
				<< " euros" << endl;
		}
		i++;
	}
}

#pragma endregion

int main(int argc, char* argv[]) // Argumentos: Array de cadenas estilo C
{ 
	ListaCoches listaC;
	ListaAlquileres listaA;
	string file = "coches.txt";
	string file2 = "rent.txt";

	cargarCoches(file, listaC);
	leerAlquileres(file2, listaA, listaC);
	//ordenarSinSort(listaA);
	ordenarAlquileres(listaA);
	mostrarAlquileres(listaA);

	delete[] listaC.cars;
	delete[] listaA.rents;

	system("pause"); // -> módulo utilsSystem
	return 0;
}