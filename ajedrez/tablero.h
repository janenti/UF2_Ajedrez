#pragma once
#define dFilas 9
#define dColumnas 9

void fTablero(char cTablero[dFilas][dColumnas]);
void fMostrar_Tablero(char cTablero[dFilas][dColumnas]);
void fPiezas_negras(char cPnegro, char cTablero[dFilas][dColumnas], char cKnegro, char cQnegra, char cTnegra, char cBnegro, char cHnegro);
void fPiezas_blancas(char cPblanco, char cTablero[dFilas][dColumnas], char cKblanco, char cQblanca, char cTblanca, char cBblanco, char cHblanco);