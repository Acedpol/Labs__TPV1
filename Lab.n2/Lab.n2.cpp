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
	//Fecha(string date) : 
	//	ano((date[0] + date[1])),		//ano(stoi(date.substr(0, 2))), 
	//	mes((date[3] + date[4])),	//mes(stoi(date.substr(3, 2))), 
	//	dia((date[6] + date[7]))	//dia(stoi(date.substr(6, 2)))
	//{};
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
	//Coche(int c, int p, string m): codigo(c), precio(p), modelo(m) {}; **ESTA LINEA ES PUTA MIERDA** -> (el constructor está bien hecho, pero en los structs no se hace y me ha dado mazo problemas)
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
		input >> listaC.tam; // hay 'X' coches, Sumar 10?
		listaC.tam += 10;
		listaC.cars = new Coche[listaC.tam];
		int i = 0;
		while (!input.fail() && i < listaC.tam) 
		{
			input >> listaC.cars[i].codigo;
			input >> listaC.cars[i].precio;
			//char c; // ignora espacio vacios (Ignorado es los metodos de mostrado)
			//input >> c;
			getline(input, listaC.cars[i].modelo); // asi es como se usa :) (se recoge con un espacio al inicio)
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
			char c; // ignora las '/'
			input >> listaA.rents[i].f.ano;
			input >> c;
			input >> listaA.rents[i].f.mes;
			input >> c;
			input >> listaA.rents[i].f.dia;
			/*string date;
			input >> date;
			listaA.rents[i].f = new Fecha(date);*/
			/*getline(input, listaA.rents[i].f.ano, '/');
			getline(input, listaA.rents[i].f.mes, '/');
			getline(input, listaA.rents[i].f.dia, ' ');*/
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
}*/

// true si f1 es más pequeño / más antiguo. Por tanto f2 es más reciente.
bool Comparador(const Fecha f1,const Fecha f2) 
{
	// Recuerda: AA/MM/DD
	return (f1.ano < f2.ano ||
	       (f1.ano == f2.ano && f1.mes < f2.mes ||
		   (f1.mes == f2.mes && f1.dia < f2.dia)));
}
//
//void ordenarAlquileres(ListaAlquileres& listaA)
//{
//	sort(&listaA.rents[0].f, &listaA.rents[listaA.cont].f, Comparador);
//	mostrarListaA(listaA);
//}

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

	/*Fecha f;
	string fecha = "13/3/17";
	f.ano = stoi(fecha.substr(0,2));
	f.mes = stoi(fecha.substr(3,2));
	f.dia = stoi(fecha.substr(5,2));
	cout << f.ano << '/' << f.mes << '/' << f.dia << endl;*/

	cargarCoches(file, listaC);
	leerAlquileres(file2, listaA, listaC);
	ordenarSinSort(listaA);
	mostrarAlquileres(listaA);
	//ordenarAlquileres(listaA);
	///*cout << "punteroCoche: " << buscarCoche(1200, listaC) << endl;
	//cout << "punteroCoche2: " << buscarCoche(1325, listaC) << endl;*/
	//delete[] listaC.cars;
	//delete[] listaA.rents;

	system("pause"); // -> módulo utilsSystem
	return 0;
}