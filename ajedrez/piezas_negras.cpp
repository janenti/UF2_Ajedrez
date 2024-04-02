#include <iostream>
#define dFilas 9
#define dColumnas 9
using namespace std;

// Funcion para crear y colocar los peones negros
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