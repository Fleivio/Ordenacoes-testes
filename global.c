#include <stdio.h>
#include "global.h"

#include <stdlib.h>
#include <time.h>

void popul(int *vet){
    for(int i = 0; i < TAM; i++){
        vet[i] = rand()%VARIATION_RANGE;
    }
}

void swap(int *p1, int *p2){
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void printVet(int *vet){
    for(int i = 0; i < TAM; i++){
        printf("[%d]", vet[i]);
    }
    printf("\n");
}

double speedTest(int *vet, void (*f)(int*)){
    clock_t init = clock();

    for(int i = 0; i < ITERATIONS; i++){
        popul(vet);
        (*f)(vet);
    }

    return (double)(clock() - init) / (double)CLOCKS_PER_SEC;
}

void singleTest(int *vet, void (*f)(int*)){
    popul(vet);
    (*f)(vet);
    printVet(vet);
}