#include <iostream>
#include "tablero.h"
#include "piezas_blancas.h"
#include "piezas_negras.h"

using namespace std;
#define dFilas 9
#define dColumnas 9
char cTablero[dFilas][dColumnas];
// Piezas
char cPblanco = 'P';
char cPnegro = 'p';
char cKblanco = 'K';
char cKnegro = 'k';
char cQblanca = 'Q';
char cQnegra = 'q';
char cTblanca = 'T';
char cTnegra = 't';
char cBblanco = 'B';
char cBnegro = 'b';
char cHblanco = 'H';
char cHnegro = 'h';
char cVacio = '*';

void main() {
	fTablero(cTablero);
	// Piezas Blancas
	fPiezas_blancas(cPblanco, cTablero, cKblanco, cQblanca, cTblanca, cBblanco, cHblanco);
	// Piezas Negras
	fPiezas_negras(cPnegro, cTablero, cKnegro, cQnegra, cTnegra, cBnegro, cHnegro);
	// Mostrar Tablero
	fMostrar_Tablero(cTablero);



}