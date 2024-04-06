#include <iostream>
#include "gameplay.h"
#include <cctype>
#define dFilas 9
#define dColumnas 9
using namespace std;

short sFilaInicial;
short sColumnaInicial;
short sFilaNueva;
short sColumnaNueva;



void fTurno(short& sActual, char cTablero[dFilas][dColumnas]) {

	if (sActual == 0)
	{ 
		cout << "\nTurno de las blancas" << endl; 
		
	}
	else
	{
		cout << "\nTurno de las negras" << endl; 
		
	}

	bool bVerificacion = false;
	while (bVerificacion == false)
	{
		cout << "Fila de la pieza a mover" << endl;
		cin >> sFilaInicial; 
		cout << "Columna de la pieza a mover" << endl;
		cin >> sColumnaInicial;
		cout << "Fila Nueva" << endl;
		cin >> sFilaNueva;
		cout << "Columna Nueva" << endl;
		cin >> sColumnaNueva;

		if (sFilaInicial > dFilas -1 || sFilaNueva > dFilas - 1 || sColumnaInicial > dColumnas -1 || sColumnaNueva > dColumnas - 1)
		{
			cout << "Movimiento no valido" << endl;
		}
		else
		{
			bVerificacion = true;
		}
	}
}


void fPeonBlanco(bool& bGameover, char cPblanco, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKnegro)
{
	if (cTablero[sFilaInicial][sColumnaInicial] == 'P')
	{
		// Validar movimiento del peón blanco
		if (sFilaNueva == sFilaInicial - 1 && sColumnaNueva == sColumnaInicial) {
			// Realizar el movimiento en el tablero
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			// Vaciar la posición anterior del peon
			cTablero[sFilaInicial][sColumnaInicial] = cVacio; 
			// Actualizar para turno de las negras
			sActual = 1;
		}
		else if (sFilaNueva == sFilaInicial - 2 && sColumnaNueva == sColumnaInicial && sFilaInicial == dFilas - 2)
		{
			// Realizar el movimiento en el tablero
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			// Vaciar la posición anterior del peon
			cTablero[sFilaInicial][sColumnaInicial] = cVacio;
			// Actualizar para turno de las negras
			sActual = 1;
		}
		// Verificar captura en diagonal izquierda
		else if (sFilaNueva == sFilaInicial - 1 && sColumnaNueva == sColumnaInicial - 1 && cTablero[sFilaNueva][sColumnaNueva] != cVacio) {
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			cTablero[sFilaInicial][sColumnaInicial] = cVacio;
			// Actualizar para turno de las negras
			sActual = 1;
			if (cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
			{
				cout << "Mate!!!" << endl;
				bGameover = false;
			}
		}
		// Verificar captura en diagonal derecha
		else if (sFilaNueva == sFilaInicial - 1 && sColumnaNueva == sColumnaInicial + 1 && cTablero[sFilaNueva][sColumnaNueva] != cVacio) {
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			cTablero[sFilaInicial][sColumnaInicial] = cVacio;
			// Actualizar para turno de las negras
			sActual = 1;
			if (cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
			{
				cout << "Mate!!!" << endl;
				bGameover = false;
			}
		}
		else {
			cout << "Movimiento invalido" << endl;
		}
	}

}

void fPeonNegro(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKblanco) {
	if (cTablero[sFilaInicial][sColumnaInicial] == 'p')
	{
		// Validar movimiento del peón blanco
		if (sFilaNueva == sFilaInicial + 1 && sColumnaNueva == sColumnaInicial) {
			// Realizar el movimiento en el tablero
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			cTablero[sFilaInicial][sColumnaInicial] = cVacio; // Vaciar la posición anterior del peón
			sActual = 1;
		}
		else if (sFilaNueva == sFilaInicial + 2 && sColumnaNueva == sColumnaInicial && sFilaInicial == dFilas - 7)
		{
			// Realizar el movimiento en el tablero
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			// Vaciar la posición anterior
			cTablero[sFilaInicial][sColumnaInicial] = cVacio;
			// Actualizar para turno de las blancas
			sActual = 0;
		}
		// Verificar captura en diagonal izquierda
		else if (sFilaNueva == sFilaInicial + 1 && sColumnaNueva == sColumnaInicial + 1 && cTablero[sFilaNueva][sColumnaNueva] != cVacio) {
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			cTablero[sFilaInicial][sColumnaInicial] = cVacio;
			// Actualizar para turno de las blancas
			sActual = 0;
			if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco)
			{
				cout << "Mate!!!" << endl;
				bGameover = false;
			}
		}
		// Verificar captura en diagonal derecha
		else if (sFilaNueva == sFilaInicial + 1 && sColumnaNueva == sColumnaInicial - 1 && cTablero[sFilaNueva][sColumnaNueva] != cVacio) {
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			cTablero[sFilaInicial][sColumnaInicial] = cVacio;
			// Actualizar para turno de las blancas
			sActual = 0;
			if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco)
			{
				cout << "Mate!!!" << endl;
				bGameover = false;
			}
		}
		else {
			cout << "Movimiento invalido" << endl;
		}
	}
}

void fTorre(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKblanco, char cKnegro, char cTblanca, char cTnegra) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cTblanca || cTablero[sFilaInicial][sColumnaInicial] == cTnegra)
	{
		//Verificacion Vertical
		if (sFilaInicial < sFilaNueva)
		{
			bool bDespejado = true;
			for (short i = 0; i < sFilaNueva; i++)
			{
				if (cTablero[sFilaInicial + i][sColumnaInicial] != cVacio)
				{
					bDespejado = false;
				}
			}
			if (bDespejado = true)
			{
				// Realizar el movimiento en el tablero
				cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
				// Vaciar la posición anterior
				cTablero[sFilaInicial][sColumnaInicial] = cVacio;
				// Actualizar para turno de las blancas
				sActual = 0;
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
				{
					cout << "Mate!!!" << endl;
					bGameover = false;
				}
			}
			else
			{
				cout << "Movimiento invalido" << endl;
			}
			
		}
		else
		{
			bool bDespejado = true; 
			for (short i = 0; i < sFilaInicial; i--)
			{
				if (cTablero[sFilaInicial - i][sColumnaInicial] != cVacio)
				{
					bDespejado = false; 
				}
			}
			if (bDespejado = true)
			{
				// Realizar el movimiento en el tablero
				cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
				// Vaciar la posición anterior
				cTablero[sFilaInicial][sColumnaInicial] = cVacio;
				// Actualizar para turno de las blancas
				sActual = 0;
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
				{
					cout << "Mate!!!" << endl;
					bGameover = false;
				}
			}
			else
			{
				cout << "Movimiento invalido" << endl;
			}
		}
		// Verificacion Horizontal
		if (sColumnaInicial < sColumnaNueva)
		{
			bool bDespejado = true;
			for (short i = 0; i < sColumnaNueva; i++)
			{
				if (cTablero[sFilaInicial][sColumnaInicial + i] != cVacio)
				{
						bDespejado = false;
				}
			}
			if (bDespejado = true)
			{
				// Realizar el movimiento en el tablero
				cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
				// Vaciar la posición anterior
				cTablero[sFilaInicial][sColumnaInicial] = cVacio;
				// Actualizar para turno de las blancas
				sActual = 0;
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
				{
						cout << "Mate!!!" << endl;
						bGameover = false;
				}
			}
			else
			{
					cout << "Movimiento invalido" << endl;
			}

		}
		else
		{
			bool bDespejado = true;
			for (short i = 0; i < sColumnaInicial; i--)
			{
				if (cTablero[sFilaInicial][sColumnaInicial - i] != cVacio)
				{
						bDespejado = false;
				}
			}
			if (bDespejado = true)
			{
				// Realizar el movimiento en el tablero
				cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
				// Vaciar la posición anterior
				cTablero[sFilaInicial][sColumnaInicial] = cVacio;
				// Actualizar para turno de las blancas
				sActual = 0;
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
				{
						cout << "Mate!!!" << endl;
						bGameover = false;
				}
			}
			else
			{
					cout << "Movimiento invalido" << endl;
			}
		}
	}
	else
	{
		cout << "Movimiento invalido" << endl;
	}
}

void fCaballo(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cHblanco, char cHnegro) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cHblanco || cTablero[sFilaInicial][sColumnaInicial] == cHnegro)
	{
		// Realizar el movimiento en el tablero
		cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
		// Vaciar la posición anterior
		cTablero[sFilaInicial][sColumnaInicial] = cVacio;
		// Actualizar para turno de las blancas
		sActual = 0;
		if (cTablero[sFilaNueva][sColumnaNueva] == cHblanco && cTablero[sFilaNueva][sColumnaNueva] == cHnegro)
		{
			cout << "Mate!!!" << endl;
			bGameover = false;
		}

	}
	else
	{
		cout << "Movimiento invalido" << endl;
	}
}

// Función para verificar si el movimiento del alfil es válido
bool fMovimientoAlfilValido(char cTablero[dFilas][dColumnas]) {
	if ()
	{

	}
	
	return false;
}
void fAlfil(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cBblanco, char cBnegro) {
	if (fMovimientoAlfilValido)
	{
		// Realizar el movimiento en el tablero
		cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
		// Vaciar la posición anterior
		cTablero[sFilaInicial][sColumnaInicial] = cVacio;
		// Actualizar para turno de las blancas
		sActual = 0;
		if (cTablero[sFilaNueva][sColumnaNueva] == cBblanco && cTablero[sFilaNueva][sColumnaNueva] == cBnegro)
		{
			cout << "Mate!!!" << endl;
			bGameover = false;
		}
	}
	else
	{
		cout << "Movimiento invalido" << endl;
	}
}