#include <stdio.h>

int boolean=1;
int main()
{
	int i;
	/* Probando la iteracion for */
	for(i=0; i<10; i++)
	{
		i--;
	}

	/* Probando la iteración while */
	i=15;
	while(boolean)
	{
		while(i>=10){
			i--;
		}

		if (i == 5)
		{
			boolean = 0;
		}
		else
		{
			i--;
		}
	}
	return 123;
}
