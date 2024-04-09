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

// Funcion para crear y colocar las piezas negras
void fPiezas_negras(char cPnegro, char cTablero[dFilas][dColumnas], char cKnegro, char cQnegra, char cTnegra, char cBnegro, char cHnegro) {
	// Peones
	short sFilaPeon = dFilas - 7;
	for (short i = 1; i < dFilas; i++)
	{
		cTablero[sFilaPeon][i] = cPnegro;
	}

	short sFila_primera = dFilas - 8;

	// Rey
	short sColumnaRey = dColumnas - 4;
	cTablero[sFila_primera][sColumnaRey] = cKnegro;

	// Reyna
	short sColumnaReyna = dColumnas - 5;
	cTablero[sFila_primera][sColumnaReyna] = cQnegra;

	// Alfiles
	short sColumnaAlfil1 = dColumnas - 3;
	short sColumnaAlfil2 = dColumnas - 6;
	cTablero[sFila_primera][sColumnaAlfil1] = cBnegro;
	cTablero[sFila_primera][sColumnaAlfil2] = cBnegro;

	//Caballos
	short sColumnaCaballo1 = dColumnas - 2;
	short sColumnaCaballo2 = dColumnas - 7;
	cTablero[sFila_primera][sColumnaCaballo1] = cHnegro;
	cTablero[sFila_primera][sColumnaCaballo2] = cHnegro;

	// Torres
	short sColumnaTorre1 = dColumnas - 1;
	short sColumnaTorre2 = dColumnas - 8;
	cTablero[sFila_primera][sColumnaTorre1] = cTnegra;
	cTablero[sFila_primera][sColumnaTorre2] = cTnegra;
}

// Funcion para crear y colocar las piezas blancas
void fPiezas_blancas(char cPblanco, char cTablero[dFilas][dColumnas], char cKblanco, char cQblanca, char cTblanca, char cBblanco, char cHblanco) {
	// Peones
	short sFilaPeon = dFilas - 2;
	for (short i = 1; i < dFilas; i++)
	{
		cTablero[sFilaPeon][i] = cPblanco;
	}

	short sFila_ultima = dFilas - 1;

	// Rey
	short sColumnaRey = dColumnas - 4;
	cTablero[sFila_ultima][sColumnaRey] = cKblanco;

	// Reyna
	short sColumnaReyna = dColumnas - 5;
	cTablero[sFila_ultima][sColumnaReyna] = cQblanca;

	// Alfiles
	short sColumnaAlfil1 = dColumnas - 3;
	short sColumnaAlfil2 = dColumnas - 6;
	cTablero[sFila_ultima][sColumnaAlfil1] = cBblanco;
	cTablero[sFila_ultima][sColumnaAlfil2] = cBblanco;

	//Caballos
	short sColumnaCaballo1 = dColumnas - 2;
	short sColumnaCaballo2 = dColumnas - 7;
	cTablero[sFila_ultima][sColumnaCaballo1] = cHblanco;
	cTablero[sFila_ultima][sColumnaCaballo2] = cHblanco;

	// Torres
	short sColumnaTorre1 = dColumnas - 1;
	short sColumnaTorre2 = dColumnas - 8;
	cTablero[sFila_ultima][sColumnaTorre1] = cTblanca;
	cTablero[sFila_ultima][sColumnaTorre2] = cTblanca;
}
