#include <stdio.h>

int variable;

int test(){
	return 0;
}

int funcion(int a, int b){
	return a+b;
}

void proced(int c, int d){
	int suma;
	suma = funcion(c, d);
	return suma;
}

int main(){
	int i = 2, j = 3;
	variable = 3;
	proced(i, j);
}