#include<stdio.h>
#include<stdint.h>
#include"LESolver.h"

int main(void){
	float LE[2][3]={{1, 2, 3},{4, 5, 6}};
	float *M = (float*)LE;
	printLE(M, 2);
	ScalarRow(M, 2, 0, 3.0);
	printLE(M, 2);
	Upper(M, 2);
	printLE(M, 2);
	printf("Diagonal = %.2e\n", matDiag(M, 2));
	return 0;
}
