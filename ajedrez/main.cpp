#include <iostream>
#include "tablero.h"
#include "gameplay.h"

using namespace std;
#define dFilas 9
#define dColumnas 9
// 0 Blancas, 1 Negras
short sActual = 0;

void main() {
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

	bool bGameover = true;
	// Creacion del tablero
	fTablero(cTablero);
	// Creacion de las Piezas Blancas
	fPiezas_blancas(cPblanco, cTablero, cKblanco, cQblanca, cTblanca, cBblanco, cHblanco);
	// Creacion de las Piezas Negras
	fPiezas_negras(cPnegro, cTablero, cKnegro, cQnegra, cTnegra, cBnegro, cHnegro);

	while (bGameover == true)
	{
		// Mostrar Tablero
		fMostrar_Tablero(cTablero);
		// Turno
		fTurno(sActual, cTablero);
		// Movimiento del peon blanco
		fPeonBlanco(bGameover, cPblanco, cTablero, cVacio, sActual, cKnegro);
		fPeonNegro(bGameover, cPnegro, cTablero, cVacio, sActual, cKblanco);
		fTorre(bGameover, cPnegro, cTablero, cVacio, sActual, cKblanco, cKnegro, cTblanca, cTnegra);
		fCaballo(bGameover, cPnegro, cTablero, cVacio, sActual, cHblanco, cHnegro);
		fAlfil(bGameover, cPnegro, cTablero, cVacio, sActual, cBblanco, cBnegro,cKblanco, cKnegro, cQblanca, cQnegra);
		fReyna(bGameover, cPnegro, cTablero, cVacio, sActual, cQblanca, cQnegra, cKblanco, cKnegro, cTblanca, cTnegra, cBblanco, cBnegro);
		fRey(bGameover, cTablero, cVacio, sActual, cKblanco, cKnegro);
	}
}