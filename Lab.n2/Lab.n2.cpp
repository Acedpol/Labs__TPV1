// Importamos las cabeceras de los módulos que necesitamos
#include <iostream> // entrada/salida, define las variables cin y cout (console)
#include <string> // cadenas de caracteres de la biblioteca estándar (STL)
#include <fstream> // entrada/salida de ficheros de texto

using namespace std; /* para nombrar sin cualificar con std:: */

struct Coche {
	int codigo;
	int precio;
	string modelo;
	Coche(int c, int p, int m) {
		codigo = c; precio = p; modelo = m;
	}
};

bool cargarCoches(string const& fichEntrada) {
	ifstream input;
	input.open(fichEntrada);
	if (!input.is_open()) {} //throw(Error(“No se encuentra el fichero”));

	else {
		string c;
		//input.getline(cin, c);
		for (int i = 0; i < 4; i++) {
			input >> c;
			/*while (!input.fail()) {
				if (c != ' ')
				input.get(c);
			}*/
			cout << c << endl;
		}
	}
	input.close();
	return true;
}

int main(int argc, char* argv[]) { // Argumentos: Array de cadenas estilo C

	cargarCoches("./coches.txt");
	system("pause"); // -> módulo utilsSystem
	return 0;


}