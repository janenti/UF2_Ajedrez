#pragma once

#define dFilas 9
#define dColumnas 9

void fTurno(short& pActual, char cTablero[dFilas][dColumnas]);
void fPeonBlanco(bool& bGameover, char cPblanco, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKnegro);
void fPeonNegro(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKblanco);
void fTorre(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cKblanco, char cKnegro, char cTblanca, char cTnegra);
void fCaballo(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cHblanco, char cHnegro);
void fAlfil(bool& bGameover, char cPnegro, char cTablero[dFilas][dColumnas], char cVacio, short& sActual, char cBblanco, char cBnegro);