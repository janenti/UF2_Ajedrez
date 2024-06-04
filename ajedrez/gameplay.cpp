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
			cTablero[sFilaNueva][sColumnaNueva] = cPblanco;
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
			cTablero[sFilaNueva][sColumnaNueva] = cPblanco;
			// Actualizar para turno de las negras
			sActual = 1;
			if (cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
			{
				cout << "Mate!!!" << endl;
				bGameover = false;
			}
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
			sActual = 0;
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
			cTablero[sFilaNueva][sColumnaNueva] = cPnegro;
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
			cTablero[sFilaNueva][sColumnaNueva] = cPnegro;
			// Actualizar para turno de las blancas
			sActual = 0;
			if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco)
			{
				cout << "Mate!!!" << endl;
				bGameover = false;
			}
		}
	}
}

void fTorre(bool& bGameover, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKblanco, char cKnegro, char cTblanca, char cTnegra) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cTblanca || cTablero[sFilaInicial][sColumnaInicial] == cTnegra)
	{

		// Verificar movimiento horizontal o vertical
		if (sFilaInicial != sFilaNueva && sColumnaInicial != sColumnaNueva) {
			cout << "Movimiento invalido" << endl;
		}

		// Verificar si el camino está despejado
		bool bDespejado = true;
		if (sFilaInicial == sFilaNueva) {
			// Movimiento horizontal
			if (sColumnaNueva > sColumnaInicial) {
				for (short i = sColumnaInicial + 1; i < sColumnaNueva; ++i) {
					if (cTablero[sFilaInicial][i] != cVacio) {
						bDespejado = false;
						break;
					}
				}
			}
			else {
				for (short i = sColumnaInicial - 1; i > sColumnaNueva; --i) {
					if (cTablero[sFilaInicial][i] != cVacio) {
						bDespejado = false;
						break;
					}
				}
			}
		}
		else if (sColumnaInicial == sColumnaNueva) {
			// Movimiento vertical
			if (sFilaNueva > sFilaInicial) {
				for (short i = sFilaInicial + 1; i < sFilaNueva; ++i) {
					if (cTablero[i][sColumnaInicial] != cVacio) {
						bDespejado = false;
						break;
					}
				}
			}
			else {
				for (short i = sFilaInicial - 1; i > sFilaNueva; --i) {
					if (cTablero[i][sColumnaInicial] != cVacio) {
						bDespejado = false;
						break;
					}
				}
			}
		}

		if (!bDespejado || cTablero[sFilaInicial][sColumnaInicial] == cTablero[sFilaNueva][sColumnaNueva]) {
			cout << "El camino no está despejado" << endl;
		}
		else
		{
			// Verificar si la casilla destino contiene una pieza del mismo color
			if ((sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) ||
				(sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva]))) {
				cout << "Esa pieza es tuya!!!!" << endl;
			}
			else
			{
				// Verificar si se ha dado jaque mate
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && sActual == 1 || cTablero[sFilaNueva][sColumnaNueva] == cKnegro && sActual == 0) {
					cout << "Mate!!!" << endl;
					bGameover = true;
				}
				// Realizar el movimiento en el tablero
				cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
				// Vaciar la posición anterior
				cTablero[sFilaInicial][sColumnaInicial] = cVacio;
				// Actualizar turno
				if (sActual == 0)
				{
					sActual = 1;
				}
				else
				{
					sActual = 0;
				}
			}
		}
		
	}
}


void fCaballo(bool& bGameover, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cHblanco, char cHnegro, char cKblanco, char cKnegro) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cHblanco || cTablero[sFilaInicial][sColumnaInicial] == cHnegro)
	{
		if (cTablero[sFilaInicial][sColumnaInicial] == cHblanco || cTablero[sFilaInicial][sColumnaInicial] == cHnegro) {
			// Movimientos posibles del caballo
			short movimientos[8][2] = {
				{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
				{1, 2}, {1, -2}, {-1, 2}, {-1, -2}
			};

			bool bMovimientoValido = false;

			for (short i = 0; i < 8; ++i) {
				if (sFilaNueva == sFilaInicial + movimientos[i][0] && sColumnaNueva == sColumnaInicial + movimientos[i][1]) {
					bMovimientoValido = true;
					break;
				}
			}

			if (!bMovimientoValido || cTablero[sFilaInicial][sColumnaInicial] == cTablero[sFilaNueva][sColumnaNueva]) {
				cout << "Movimiento invalido" << endl;
			}

			if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;
			}
			else
			{
				if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
					cout << "Esa pieza es tuya!!!!" << endl;
				}
				else
				{
					// Verificar si se ha dado jaque mate
					if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && sActual == 1 || cTablero[sFilaNueva][sColumnaNueva] == cKnegro && sActual == 0) {
						cout << "Mate!!!" << endl;
						bGameover = true;
					}
					// Realizar el movimiento en el tablero
					cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
					// Vaciar la posición anterior
					cTablero[sFilaInicial][sColumnaInicial] = cVacio;
					// Actualizar turno
					if (sActual == 0)
					{
						sActual = 1;
					}
					else
					{
						sActual = 0;
					}
				}
			}
			
		}
	}
}



bool fAbajoDerecha(char cTablero[dFilas][dColumnas], char cVacio, short sFilaInicial, short sFilaNueva, short sColumnaInicial, short sColumnaNueva) {
	if (sFilaNueva - sFilaInicial != sColumnaNueva - sColumnaInicial) {
		return false;
	}

	for (short i = 1; i < sFilaNueva - sFilaInicial; ++i) {
		if (cTablero[sFilaInicial + i][sColumnaInicial + i] != cVacio) {
			return false;
		}
	}

	return true;
}

// Verifico si la casilla esta arriba a la derecha de la casilla inicial
bool fArribaDerecha(char cTablero[dFilas][dColumnas], char cVacio, short sFilaInicial, short sFilaNueva, short sColumnaInicial, short sColumnaNueva) {
	if (sFilaInicial - sFilaNueva != sColumnaNueva - sColumnaInicial) {
		return false;
	}

	for (short i = 1; i < sFilaInicial - sFilaNueva; ++i) {
		if (cTablero[sFilaInicial - i][sColumnaInicial + i] != cVacio) {
			return false;
		}
	}

	return true;
}


// Verifico si la casilla esta abajo a la izquierda de la casilla inicial
bool fAbajoIzquierda(char cTablero[dFilas][dColumnas], char cVacio, short sFilaInicial, short sFilaNueva, short sColumnaInicial, short sColumnaNueva) {
	if (sFilaNueva - sFilaInicial != sColumnaInicial - sColumnaNueva) {
		return false;
	}

	for (short i = 1; i < sFilaNueva - sFilaInicial; ++i) {
		if (cTablero[sFilaInicial + i][sColumnaInicial - i] != cVacio) {
			return false;
		}
	}

	return true;
}


// Verifico si la casilla esta abajo a la izquierda de la casilla inicial
bool fArribaIzquierda(char cTablero[dFilas][dColumnas], char cVacio, short sFilaInicial, short sFilaNueva, short sColumnaInicial, short sColumnaNueva) {
	if (sFilaInicial - sFilaNueva != sColumnaInicial - sColumnaNueva) {
		return false;
	}

	for (short i = 1; i < sFilaInicial - sFilaNueva; ++i) {
		if (cTablero[sFilaInicial - i][sColumnaInicial - i] != cVacio) {
			return false;
		}
	}

	return true;
}


void fAlfil(bool& bGameover, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cAblanco, char cAnegro, char cKblanco, char cKnegro) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cAblanco || cTablero[sFilaInicial][sColumnaInicial] == cAnegro)
	{
		char alfilActual = cTablero[sFilaInicial][sColumnaInicial];

		if (alfilActual != cAblanco && alfilActual != cAnegro) {
			cout << "Movimiento invalido" << endl;
		}

		bool bMovimientoValido = false;

		if (sFilaNueva < sFilaInicial && sColumnaNueva > sColumnaInicial) {
			// Arriba derecha
			bMovimientoValido = fArribaDerecha(cTablero, cVacio, sFilaInicial, sFilaNueva, sColumnaInicial, sColumnaNueva);
		}
		else if (sFilaNueva < sFilaInicial && sColumnaNueva < sColumnaInicial) {
			// Arriba izquierda
			bMovimientoValido = fArribaIzquierda(cTablero, cVacio, sFilaInicial, sFilaNueva, sColumnaInicial, sColumnaNueva);
		}
		else if (sFilaNueva > sFilaInicial && sColumnaNueva > sColumnaInicial) {
			// Abajo derecha
			bMovimientoValido = fAbajoDerecha(cTablero, cVacio, sFilaInicial, sFilaNueva, sColumnaInicial, sColumnaNueva);
		}
		else if (sFilaNueva > sFilaInicial && sColumnaNueva < sColumnaInicial) {
			// Abajo izquierda
			bMovimientoValido = fAbajoIzquierda(cTablero, cVacio, sFilaInicial, sFilaNueva, sColumnaInicial, sColumnaNueva);
		}

		if (!bMovimientoValido || cTablero[sFilaInicial][sColumnaInicial] == cTablero[sFilaNueva][sColumnaNueva]) {
			cout << "Movimiento invalido" << endl;
		}
		else
		{
			// Verificar si la casilla destino contiene una pieza del mismo color
			if ((sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) ||
				(sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva]))) {
				cout << "Esa pieza es tuya!!!!" << endl;
			}
			else
			{
				// Verificar si se ha dado jaque mate
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && sActual == 1 || cTablero[sFilaNueva][sColumnaNueva] == cKnegro && sActual == 0) {
					cout << "Mate!!!" << endl;
					bGameover = true;
				}
				// Realizar el movimiento en el tablero
				cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
				// Vaciar la posición anterior
				cTablero[sFilaInicial][sColumnaInicial] = cVacio;
				// Actualizar turno
				if (sActual == 0)
				{
					sActual = 1;
				}
				else
				{
					sActual = 0;
				}
			}
		}
	}
}


void fReyna(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKblanco, char cKnegro, char cRblanca, char cRnegra) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cRblanca || cTablero[sFilaInicial][sColumnaInicial] == cRnegra) {
		bool bMovimientoValido = false;

		// Verificar movimiento horizontal o vertical (como torre)
		if (sFilaInicial == sFilaNueva || sColumnaInicial == sColumnaNueva) {
			bool bDespejado = true;
			if (sFilaInicial == sFilaNueva) {
				// Movimiento horizontal
				if (sColumnaNueva > sColumnaInicial) {
					for (short i = sColumnaInicial + 1; i < sColumnaNueva; ++i) {
						if (cTablero[sFilaInicial][i] != cVacio) {
							bDespejado = false;
							break;
						}
					}
				}
				else {
					for (short i = sColumnaInicial - 1; i > sColumnaNueva; --i) {
						if (cTablero[sFilaInicial][i] != cVacio) {
							bDespejado = false;
							break;
						}
					}
				}
			}
			else if (sColumnaInicial == sColumnaNueva) {
				// Movimiento vertical
				if (sFilaNueva > sFilaInicial) {
					for (short i = sFilaInicial + 1; i < sFilaNueva; ++i) {
						if (cTablero[i][sColumnaInicial] != cVacio) {
							bDespejado = false;
							break;
						}
					}
				}
				else {
					for (short i = sFilaInicial - 1; i > sFilaNueva; --i) {
						if (cTablero[i][sColumnaInicial] != cVacio) {
							bDespejado = false;
							break;
						}
					}
				}
			}
			bMovimientoValido = bDespejado;
		}

		// Verificar movimiento diagonal (como alfil)
		if (!bMovimientoValido) {
			if (sFilaNueva < sFilaInicial && sColumnaNueva > sColumnaInicial) {
				// Arriba derecha
				bMovimientoValido = fArribaDerecha(cTablero, cVacio, sFilaInicial, sFilaNueva, sColumnaInicial, sColumnaNueva);
			}
			else if (sFilaNueva < sFilaInicial && sColumnaNueva < sColumnaInicial) {
				// Arriba izquierda
				bMovimientoValido = fArribaIzquierda(cTablero, cVacio, sFilaInicial, sFilaNueva, sColumnaInicial, sColumnaNueva);
			}
			else if (sFilaNueva > sFilaInicial && sColumnaNueva > sColumnaInicial) {
				// Abajo derecha
				bMovimientoValido = fAbajoDerecha(cTablero, cVacio, sFilaInicial, sFilaNueva, sColumnaInicial, sColumnaNueva);
			}
			else if (sFilaNueva > sFilaInicial && sColumnaNueva < sColumnaInicial) {
				// Abajo izquierda
				bMovimientoValido = fAbajoIzquierda(cTablero, cVacio, sFilaInicial, sFilaNueva, sColumnaInicial, sColumnaNueva);
			}
		}

		if (!bMovimientoValido || cTablero[sFilaInicial][sColumnaInicial] == cTablero[sFilaNueva][sColumnaNueva]) {
			cout << "Movimiento invalido" << endl;
		}
		else
		{
			// Verificar si la casilla destino contiene una pieza del mismo color
			if ((sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) ||
				(sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva]))) {
				cout << "Esa pieza es tuya!!!!" << endl;
			}
			else
			{
				// Verificar si se ha dado jaque mate
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && sActual == 1 || cTablero[sFilaNueva][sColumnaNueva] == cKnegro && sActual == 0) {
					cout << "Mate!!!" << endl;
					bGameover = true;
				}
				// Realizar el movimiento en el tablero
				cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
				// Vaciar la posición anterior
				cTablero[sFilaInicial][sColumnaInicial] = cVacio;
				// Actualizar turno
				if (sActual == 0)
				{
					sActual = 1;
				}
				else
				{
					sActual = 0;
				}
			}
		}
	}
}


void fRey(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKblanco, char cKnegro) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cKblanco || cTablero[sFilaInicial][sColumnaInicial] == cKnegro) {
		// Verificar que el movimiento es de solo una casilla en cualquier dirección
		short sDiffFila = sFilaNueva - sFilaInicial;
		short sDiffColumna = sColumnaNueva - sColumnaInicial;

		if (sDiffFila < -1 || sDiffFila > 1 || sDiffColumna < -1 || sDiffColumna > 1 || cTablero[sFilaInicial][sColumnaInicial] == cTablero[sFilaNueva][sColumnaNueva]) {
			cout << "Movimiento invalido" << endl;
		}
		else
		{
			// Verificar si la casilla destino contiene una pieza del mismo color
			if ((sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) ||
				(sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva]))) {
				cout << "Esa pieza es tuya!!!!" << endl;
			}
			else
			{
				// Verificar si se ha dado jaque mate
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && sActual == 1 || cTablero[sFilaNueva][sColumnaNueva] == cKnegro && sActual == 0) {
					cout << "Mate!!!" << endl;
					bGameover = true;
				}
				// Realizar el movimiento en el tablero
				cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
				// Vaciar la posición anterior
				cTablero[sFilaInicial][sColumnaInicial] = cVacio;
				// Actualizar turno
				if (sActual == 0)
				{
					sActual = 1;
				}
				else
				{
					sActual = 0;
				}
			}
		}
	}
}
