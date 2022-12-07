#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"MatFileHandler.h"

void wMat(char fPath[], MatStruct_t *M){
	FILE *fMat = NULL;
	fMat = fopen(fPath, "wb");
	fwrite((void*)&M->N, sizeof(uint32_t), 1, fMat);
	fwrite((void*)M->Data, sizeof(float), M->N*(M->N + 1), fMat);
	fclose(fMat);
}

void rMat(char fPath[], MatStruct_t *M){
	FILE *fMat = NULL;
	fMat = fopen(fPath, "rb");
	fread((void*)&M->N, sizeof(uint32_t), 1, fMat);
	M->Data = (float*)malloc(M->N*(M->N + 1)*sizeof(float));
	fread((void*)M->Data, sizeof(float), M->N*(M->N + 1), fMat);
	fclose(fMat);
}
