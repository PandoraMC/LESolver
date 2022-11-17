#ifndef __LESOLVER_H__
#define __LESOLVER_H__

#include <stdint.h>

void printLE(float *M, uint8_t N);
uint8_t ScalarRow(float *M, uint8_t N, uint8_t r, float s);
uint8_t Upper(float *M, uint8_t N);
float matDiag(float *M, uint8_t N);

#endif
