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
				// Actualizar turno
				if (sActual == 1)
				{
					sActual = 0;
				}
				else
				{
					sActual = 1;
				}
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
				{
					cout << "Mate!!!" << endl;
					bGameover = false;
				}
			}
			else if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;

			}
			else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;
			}
			else
			{
				cout << "Movimiento invalido" << endl;
			}
			
		}
		else
		{
			bool bDespejado = true; 
			for (short i = sFilaInicial; i < sFilaNueva; i--)
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
				// Actualizar turno
				if (sActual == 1)
				{
					sActual = 0;
				}
				else
				{
					sActual = 1;
				}
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
				{
					cout << "Mate!!!" << endl;
					bGameover = false;
				}
			}
			else if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;

			}
			else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;
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
			for (short i = sColumnaInicial; i < sColumnaNueva; i++)
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
				// Actualizar turno
				if (sActual == 1)
				{
					sActual = 0;
				}
				else
				{
					sActual = 1;
				}
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
				{
						cout << "Mate!!!" << endl;
						bGameover = false;
				}
			}
			else if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;

			}
			else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;
			}
			else
			{
					cout << "Movimiento invalido" << endl;
			}

		}
		else
		{
			bool bDespejado = true;
			for (short i = sColumnaInicial; i < sColumnaNueva; i--)
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
				// Actualizar turno
				if (sActual == 1)
				{
					sActual = 0;
				}
				else
				{
					sActual = 1;
				}
				if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
				{
						cout << "Mate!!!" << endl;
						bGameover = false;
				}
				
			}
			else if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;

			}
			else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
				cout << "Esa pieza es tuya!!!!" << endl;
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
		if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
			cout << "Esa pieza es tuya!!!!" << endl;;
		}
		else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
			cout << "Esa pieza es tuya!!!!" << endl;
		}
		else
		{
			// Realizar el movimiento en el tablero
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			// Vaciar la posición anterior
			cTablero[sFilaInicial][sColumnaInicial] = cVacio;
			// Actualizar turno
			if (sActual == 1)
			{
				sActual = 0;
			}
			else
			{
				sActual = 1;
			}
			if (cTablero[sFilaNueva][sColumnaNueva] == cHblanco && cTablero[sFilaNueva][sColumnaNueva] == cHnegro)
			{
				cout << "Mate!!!" << endl;
				bGameover = false;
			}
		}
	}
	else
	{
		cout << "Movimiento invalido" << endl;
	}
}

// Verifico si la casilla esta abajo a la derecha de la casilla inicial
bool fAlfilAbajoDerecha(char cTablero[dFilas][dColumnas], char cVacio, short sActual, char cBblanco, char cBnegro, char cQblanca, char cQnegra) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cBblanco || cTablero[sFilaInicial][sColumnaInicial] == cBnegro || cTablero[sFilaInicial][sColumnaInicial] == cQnegra || cTablero[sFilaInicial][sColumnaInicial] == cQblanca) {
		for (short i = sFilaInicial + 1; i < sFilaNueva; i++) {
			for (short j = sColumnaInicial + 1; j > sColumnaNueva; j++) {
				// Si pasa por encima de alguna pieza, dará falso.
				if (cTablero[i][j] != cVacio) {
					cout << "No se puede llegar hasta la casilla!!!" << endl;
					return false;
				}
				else if (cTablero[i][j] == cTablero[sFilaNueva][sColumnaNueva]) {
					// Verificación para que en la casilla seleccionada esté una pieza del color opuesto con las funciones isupper y islower que detectan si un caracter está en mayúscula o minúscula
					if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
						cout << "Esa pieza es tuya!!!!" << endl;
						return false;
					}
					else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
						cout << "Esa pieza es tuya!!!!" << endl;
						return false;
					}
					else
					{
						return true;
					}
				}
			}
		}
		return false; // Si no se cumple ninguna condición, retornar falso.
	}
}
// Verifico si la casilla esta arriba a la derecha de la casilla inicial
bool fAlfilArribaDerecha(char cTablero[dFilas][dColumnas], char cVacio, short sActual, char cBblanco, char cBnegro, char cQblanca, char cQnegra) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cBblanco || cTablero[sFilaInicial][sColumnaInicial] == cBnegro || cTablero[sFilaInicial][sColumnaInicial] == cQnegra || cTablero[sFilaInicial][sColumnaInicial] == cQblanca) {
		for (short i = sFilaInicial - 1; i < sFilaNueva; i--) {
			for (short j = sColumnaInicial + 1; j > sColumnaNueva; j++) {
				// Si pasa por encima de alguna pieza, dará falso.
				if (cTablero[i][j] != cVacio) {
					cout << "No se puede llegar hasta la casilla!!!" << endl;
					return false;
				}
				else if (cTablero[i][j] == cTablero[sFilaNueva][sColumnaNueva]) {
					// Verificación para que en la casilla seleccionada esté una pieza del color opuesto con las funciones isupper y islower que detectan si un caracter está en mayúscula o minúscula
					if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
						cout << "Esa pieza es tuya!!!!" << endl;
						return false;
					}
					else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
						cout << "Esa pieza es tuya!!!!" << endl;
						return false;
					}
					else
					{
						return true;
					}
				}
			}
		}
		return false; // Si no se cumple ninguna condición, retornar falso.
	}
}

// Verifico si la casilla esta abajo a la izquierda de la casilla inicial
bool fAlfilAbajoIzquierda(char cTablero[dFilas][dColumnas], char cVacio, short sActual, char cBblanco, char cBnegro, char cQblanca, char cQnegra) {
	for (short i = sFilaInicial - 1; i < sFilaNueva; i--) {
		for (short j = sColumnaInicial - 1; j > sColumnaNueva; j--) {
			// Si pasa por encima de alguna pieza, dará falso.
			if (cTablero[i][j] != cVacio) {
				cout << "No se puede llegar hasta la casilla!!!" << endl;
				return false;
			}
			else if (cTablero[i][j] == cTablero[sFilaNueva][sColumnaNueva]) {
				// Verificación para que en la casilla seleccionada esté una pieza del color opuesto con las funciones isupper y islower que detectan si un caracter está en mayúscula o minúscula
				if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
					cout << "Esa pieza es tuya!!!!" << endl;
					return false;
				}
				else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
					cout << "Esa pieza es tuya!!!!" << endl;
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
	return false; // Si no se cumple ninguna condición, retornar falso.
}

// Verifico si la casilla esta abajo a la izquierda de la casilla inicial
bool fAlfilArribaIzquierda(char cTablero[dFilas][dColumnas], char cVacio, short sActual, char cBblanco, char cBnegro, char cQblanca, char cQnegra) {
	for (short i = sFilaInicial + 1; i < sFilaNueva; i++) {
		for (short j = sColumnaInicial - 1; j > sColumnaNueva; j--) {
			// Si pasa por encima de alguna pieza, dará falso.
			if (cTablero[i][j] != cVacio) {
				cout << "No se puede llegar hasta la casilla!!!" << endl;
				return false;
			}
			else if (cTablero[i][j] == cTablero[sFilaNueva][sColumnaNueva]) {
				// Verificación para que en la casilla seleccionada esté una pieza del color opuesto con las funciones isupper y islower que detectan si un caracter está en mayúscula o minúscula
				if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
					cout << "Esa pieza es tuya!!!!" << endl;
					return false;
				}
				else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
					cout << "Esa pieza es tuya!!!!" << endl;
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
	return false; // Si no se cumple ninguna condición, retornar falso.
}

void fAlfil(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cBblanco, char cBnegro, char cKblanco, char cKnegro, char cQblanca, char cQnegra) {
	if (cTablero[sFilaInicial][sColumnaInicial] == cQblanca || cTablero[sFilaInicial][sColumnaInicial] == cQnegra) {
		if (fAlfilAbajoDerecha(cTablero, cVacio, sActual, cBblanco, cBnegro, cQblanca, cQnegra) == true || fAlfilArribaDerecha(cTablero, cVacio, sActual, cBblanco, cBnegro, cQblanca, cQnegra) == true
			|| fAlfilAbajoIzquierda(cTablero, cVacio, sActual, cBblanco, cBnegro, cQblanca, cQnegra) == true || fAlfilArribaIzquierda(cTablero, cVacio, sActual, cBblanco, cBnegro, cQblanca, cQnegra) == true)
		{
			// Realizar el movimiento en el tablero
			cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
			// Vaciar la posición anterior
			cTablero[sFilaInicial][sColumnaInicial] = cVacio;
			// Actualizar turno
			if (sActual == 1)
			{
				sActual = 0;
			}
			else
			{
				sActual = 1;
			}
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

void fReyna(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cQblanca, char cQnegra, char cKblanco, char cKnegro, char cTblanca, char cTnegra, char cBblanco, char cBnegro) {
	// Para verificar como se va a mover, 1 = Se mueve como una torre, 0 = Se mueve como un alfil
	short sForma;
	if (cTablero[sFilaInicial][sColumnaInicial] == cQblanca || cTablero[sFilaInicial][sColumnaInicial] == cQnegra) {
		if (sFilaInicial == sFilaNueva || sColumnaInicial == sColumnaNueva)
		{
			sForma = 1;
		}
		else 
		{
			sForma = 0;
		}
		if (sForma == 1)
		{
			fTorre(bGameover, cPnegro, cTablero, cVacio, sActual, cKblanco, cKnegro, cTblanca, cTnegra);
		}
		else
		{
			fAlfil(bGameover, cPnegro, cTablero, cVacio, sActual, cBblanco, cBnegro, cKblanco, cKnegro, cQblanca, cQnegra);
		}
	}
}

void fRey(bool& bGameover, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKblanco, char cKnegro) {

	bool bVertical = ((sFilaInicial - sFilaNueva == 1 || sFilaNueva - sFilaInicial == 1) && sColumnaInicial == sColumnaNueva);
	bool bHorizontal = ((sColumnaInicial - sColumnaNueva == 1 || sColumnaNueva - sColumnaInicial == 1) && sFilaInicial == sFilaNueva); 
	bool bDiagonal = ((sFilaInicial - sFilaNueva == 1 || sFilaNueva - sFilaInicial == 1) && (sColumnaInicial - sColumnaNueva == 1 || sColumnaNueva - sColumnaInicial == 1));

	if (bVertical == true || bHorizontal == true || bDiagonal == true)
	{
		// Realizar el movimiento en el tablero
		cTablero[sFilaNueva][sColumnaNueva] = cTablero[sFilaInicial][sColumnaInicial];
		// Vaciar la posición anterior
		cTablero[sFilaInicial][sColumnaInicial] = cVacio;
		if (cTablero[sFilaNueva][sColumnaNueva] == cKblanco && cTablero[sFilaNueva][sColumnaNueva] == cKnegro)
		{
			cout << "Mate!!!" << endl;
			bGameover = false;
		}
		if (sActual == 0 && isupper(cTablero[sFilaNueva][sColumnaNueva])) {
			cout << "Esa pieza es tuya!!!!" << endl;
		}
		else if (sActual == 1 && islower(cTablero[sFilaNueva][sColumnaNueva])) {
			cout << "Esa pieza es tuya!!!!" << endl;
		}
		// Actualizar turno
		if (sActual == 1)
		{
			sActual = 0;
		}
		else
		{
			sActual = 1;
		}
	}
	else
	{
		cout << "Movimiento invalido" << endl;
	}
}