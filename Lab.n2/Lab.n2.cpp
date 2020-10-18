// Importamos las cabeceras de los módulos que necesitamos
#include <iostream> // entrada/salida, define las variables cin y cout (console)
#include <string> // cadenas de caracteres de la biblioteca estándar (STL)
#include <fstream> // entrada/salida de ficheros de texto
#include <algorithm> // para el sort

using namespace std; /* para nombrar sin cualificar con std:: */

#pragma region STRUCTS
struct fecha
{
	string ano;
	string mes;
	string dia;
};

struct Coche {
	int codigo;
	int precio; // por dia
	string modelo;
	//Coche(int c, int p, string m): codigo(c), precio(p), modelo(m) {}; **ESTA LINEA ES PUTA MIERDA** -> (el constructor está bien hecho, pero en los structs no se hace y me ha dado mazo problemas)
};

struct ListaCoches {
	Coche* cars; // array dinamico
	int tam = 0; // tamaño escalable
	int cont = 0; // Numero real de elementos
};

struct Alquiler {
	int codigo;
	fecha f;
	int numDias;
	Coche* puntCoche; //puntero al coche al que hace referencia
};

struct ListaAlquileres {
	Alquiler* rents; // array dinamico
	int tam = 0; // tamaño escalable
	int cont = 0; // Numero real de elementos
};


#pragma endregion

#pragma region METODOS

void mostrarListaC(const ListaCoches& listaC)
{
	int i = 0;
	cout << "~ Lista Coches ~" << endl;
	while (i < listaC.cont - 1)
	{
		cout << i << " -> " << listaC.cars[i].codigo << ' ' << listaC.cars[i].precio << ' ' << listaC.cars[i].modelo << endl;
		i++;
	}
}

void mostrarListaA(const ListaAlquileres& listaA)
{
	int i = 0;
	cout << "~ Lista Alquileres ~" << endl;
	while (i < listaA.cont - 1)
	{
		cout << i << " -> " << listaA.rents[i].codigo << ' ' << listaA.rents[i].f.ano << '-' << listaA.rents[i].f.mes << '-' << listaA.rents[i].f.dia << ' ' << listaA.rents[i].numDias << endl;
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
		input >> listaC.tam; // hay 'X' coches, Sumar 10?
		listaC.tam += 10;
		listaC.cars = new Coche[listaC.tam];
		int i = 0;
		while (!input.fail() && i < listaC.tam) 
		{
			input >> listaC.cars[i].codigo;
			input >> listaC.cars[i].precio;
			getline(input, listaC.cars[i].modelo); // asi es como se usa :)
			i++;
			listaC.cont++;
		}
		mostrarListaC(listaC);
		input.close();
		return true;
	} 
	else 
	{
		input.close();
		return false;
	}	
}

Coche* buscarCoche(int code, ListaCoches& listaC)
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

bool leerAlquileres(string const& fichEntrada, ListaAlquileres& listaA, ListaCoches& const listaC)
{
	ifstream input;
	input.open(fichEntrada);	

	if (input.is_open()) //throw(Error(“No se encuentra el fichero”)); -> esto sobra, con el if salva la excepcion
	{
		input >> listaA.tam; // hay 'X' coches
		listaA.tam += 10;
		listaA.rents = new Alquiler[listaA.tam];
		int i = 0;
		while (!input.fail() && i < listaA.tam)
		{
			input >> listaA.rents[i].codigo;
			//input >> listaA.rents[i].fechaString;
			getline(input, listaA.rents[i].f.ano, '/');
			getline(input, listaA.rents[i].f.mes, '/');
			getline(input, listaA.rents[i].f.dia, ' ');
			input >> listaA.rents[i].numDias;
			listaA.rents[i].puntCoche = buscarCoche(listaA.rents[i].codigo, listaC);
			i++;
			listaA.cont++;			
		}
		mostrarListaA(listaA);
		input.close();
		return true;
	} 
	else 
	{
		input.close();
		return false;
	}	
}


//bool Comparador(const fecha& f1,const fecha& f2) {
//	//aqui
//	int f1Ano, f1Mes, f1Dia, f2Ano, f2Mes, f2Dia;
//	f1Ano = stoi(f1.ano);
//	f1Mes = stoi(f1.mes);
//	f1Dia = stoi(f1.dia);
//	f2Ano = stoi(f2.ano);
//	f2Mes = stoi(f2.mes);
//	f2Dia = stoi(f2.dia);
//	return (f1Ano < f2Ano ||
//	       (f1Ano == f2Ano && f1Mes < f2Mes || 
//		   (f1Mes == f2Mes && f1Dia < f2Dia)));
//}
/*
bool Comparador(const Alquiler f1, const Alquiler f2) {
	//aqui
	int f1Ano, f1Mes, f1Dia, f2Ano, f2Mes, f2Dia;
	f1Ano = stoi(f1.f.ano);
	f1Mes = stoi(f1.f.mes);
	f1Dia = stoi(f1.f.dia);
	f2Ano = stoi(f2.f.ano);
	f2Mes = stoi(f2.f.mes);
	f2Dia = stoi(f2.f.dia);
	return (f1Ano < f2Ano ||
	       (f1Ano == f2Ano && f1Mes < f2Mes || 
		   (f1Mes == f2Mes && f1Dia < f2Dia)));
}

void ordenarAlquileres(ListaAlquileres& listaA)
{
	sort(&listaA.rents[0], &listaA.rents[listaA.cont], Comparador);
	mostrarListaA(listaA);
}*/

#pragma endregion

int main(int argc, char* argv[]) // Argumentos: Array de cadenas estilo C
{ 
	ListaCoches listaC;
	ListaAlquileres listaA;
	string file = "coches.txt";
	string file2 = "rent.txt";

	cargarCoches(file, listaC);
	leerAlquileres(file2, listaA, listaC);
	//ordenarAlquileres(listaA);
	/*cout << "punteroCoche: " << buscarCoche(1200, listaC) << endl;
	cout << "punteroCoche2: " << buscarCoche(1325, listaC) << endl;*/
	delete[] listaC.cars;
	delete[] listaA.rents;

	system("pause"); // -> módulo utilsSystem
	return 0;
}