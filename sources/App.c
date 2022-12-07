#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"LESolver.h"
#include"MatFileHandler.h"

int main(int argN, char *argV[]){
	if(argN < 2){
		printf("uso: ./App archivo.m\n");
		return 1;
	}
	float LE[3][4]={{1, 2, 3, 7},{4, 5, 6, 8}, {7, 9, 0, 1/2.0}};
	MatStruct_t System = {3, (float*)&LE};
	wMat(argV[1], &System);

	MatStruct_t rSystem = {0, NULL};
	rMat(argV[1], &rSystem);

	printLE(rSystem.Data, rSystem.N);
	ScalarRow(rSystem.Data, rSystem.N, 0, 3.0);
	printLE(rSystem.Data, rSystem.N);
	Upper(rSystem.Data, rSystem.N);
	printLE(rSystem.Data, rSystem.N);
	printf("Diagonal = %.2e\n", matDiag(rSystem.Data, rSystem.N));

	free(rSystem.Data);
	return 0;
}
