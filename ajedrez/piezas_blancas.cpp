#include <iostream>
#define dFilas 9
#define dColumnas 9
using namespace std;

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