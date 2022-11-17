#include "LESolver.h"
#include <stdint.h>
#include <stdio.h>

uint8_t ScalarRow(float *M, uint8_t N, uint8_t r, float s){
        uint8_t c;
        for(c = 0; c <= N; c++){
                *(M + r*(N + 1) + c) *= s;
        }
        return c;
}

void printLE(float *M, uint8_t N){
	uint8_t r, c;
        for(r = 0; r < N; r++){
                for(c = 0; c <= N; c++){
                        printf("%3.2f\t", *(M + r*(N + 1) + c));
                }
        printf("\n");
        }
}

uint8_t Upper(float *M, uint8_t N){
        float a, d;
	uint8_t k, r, c;
        for(k = 0; k < (N - 1); k++){
                a = *(M + k*(N + 1) + k);
                for(r = (k + 1); r < N; r++){
                        d = *(M + r*(N + 1) + k);
                        for(c = 0; c <= N; c++){
                                *(M + r*(N + 1) + c) -= *(M + k*(N + 1) + c)*d/a;
                        }
                }
        }
	return k;
}

float matDiag(float *M, uint8_t N){
	float d = 1.0f;
	uint8_t var;
	for(var = 0; var < N; var++){
		d *= *(M + var*(N + 1) + var);
	}
	return d;
}
