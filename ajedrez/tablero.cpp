#include <iostream>
#define dFilas 9
#define dColumnas 9
using namespace std;

// Funcion para definir el tablero
void fTablero(char cTablero[dFilas][dColumnas]) {
	for (short i = 0; i < dFilas; i++)
	{
		for (short j = 0; j < dColumnas; j++)
		{
			cTablero[0][0] = ' ';

			if (i == 0 && j > 0)
			{
				// Convierte el número a caracter
				cTablero[i][j] = j + '0';
			}
			else if (j == 0 && i > 0)
			{
				// Convierte el número a caracter
				cTablero[i][j] = i + '0';
			}
			else if (i > 0 && j > 0)
			{
				cTablero[i][j] = '*'; 
			}
			
		}
	}
}


// Funcion para mostrar el tablero
void fMostrar_Tablero(char cTablero[dFilas][dColumnas]) {
	// Bucle para mostrar el tablero
	for (int i = 0; i < dFilas; i++)
	{
		for (int j = 0; j < dColumnas; j++)
		{
			cout << cTablero[i][j] << ' ';
		}
		cout << endl;
	}
}

