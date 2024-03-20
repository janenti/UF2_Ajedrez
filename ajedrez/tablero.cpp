
#define dFilas 9
#define dColumnas 9

void fTablero(char cTablero[dFilas][dColumnas]) {
	for (short i = 0; i < dFilas; ++i)
	{
		for (short j = 0; j < dColumnas; ++j)
		{
			if (j == 0) 
			{
				for (short k = 1; k < dFilas; k++)
				{
					cTablero[i][j] = k;
				}
			}
		}
	}
}