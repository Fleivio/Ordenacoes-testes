#include <stdio.h>
#include "global.h"

#include <stdlib.h>
#include <time.h>


void popul(int *vet, int size){
    for(int i = 0; i < size; i++){
        vet[i] = rand() % VARIATION_RANGE;
    }
}

void swap(int *p1, int *p2){
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void printVet(int *vet, int size){
    for(int i = 0; i < size; i++){
        printf("[%d]", vet[i]);
    }
    printf("\n");
}

double speedTest(int *vet, int size, void (*f)(int*, int)){
    clock_t init = clock();

    for(int i = 0; i < ITERATIONS; i++){
        popul(vet, size);
        (*f)(vet, size);
    }

    return (double)(clock() - init) / (double)CLOCKS_PER_SEC;
}

void singleTest(int *vet, int size, void (*f)(int*, int)){
    popul(vet, size);
    (*f)(vet, size);
    printVet(vet, size);
}