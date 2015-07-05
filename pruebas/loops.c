#include <stdio.h>

int main()
{
	int i;
	int suma = 0, suma2 = 0;
	/* Probando la iteracion for */
	for(i=0; i<10; i++)
	{
		suma += i;
	}
	/* Probando la iteración while */
	i=15;
	
	while(i > 0)
	{
		while(i>=10)
		{
			suma2 += i--;
		}

		if (i == 5)
		{
			suma += i--;
		}
		else
		{
			i--;
		}
	}

	return suma + suma2;
}
