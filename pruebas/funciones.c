#include <stdio.h>

int variable1;
int array1[];
int array2[6];
int array3[][];
int array4[6][4][2][];

int test(){
	return 0;
}

int variable3;
int variable6;

int funcion(int a[], int b){
	return a+b;
}

int variable4;
int variable5;

void proced(int c, int d){
	int suma;
	int variable1;
	suma = funcion(c, d);
	return suma;
}

int main(){
	int i = 2, j = 3;
	variable = 3;
	return proced(i, j);
}
