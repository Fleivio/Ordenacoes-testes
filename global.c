#include <stdio.h>
#include "global.h"

#include <stdlib.h>
#include <time.h>

void popul(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        vet[i] = rand()%VARIATION_RANGE;
    }
}

void swap(int *p1, int *p2){
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void printVet(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        printf("[%d]", vet[i]);
    }
    printf("\n");
}

double speedTest(int *vet, int tam, void (*f)(int*, int)){
    clock_t init = clock();

    for(int i = 0; i < ITERATIONS; i++){
        popul(vet, tam);
        (*f)(vet, tam);
    }

    return (double)(clock() - init) / (double)CLOCKS_PER_SEC;
}

void singleTest(int *vet, int tam, void (*f)(int*, int)){
    popul(vet, tam);
    (*f)(vet, tam);
    printVet(vet, tam);
}