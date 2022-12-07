#ifndef __MATFILEHANDLER_H__
#define __MATFILEHANDLER_H__

#include<stdint.h>

typedef struct{
	uint32_t N;
	float *Data;
}MatStruct_t;

void wMat(char fPath[], MatStruct_t *M);
void rMat(char fPath[], MatStruct_t *M);

#endif
