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

int isSorted(int *vet, int size){
    for(int i = 0; i < size-1; i++){
        if(vet[i] > vet[i+1]){
            return 0;
        }
    }
    return 1;
}

void singleTest(int *vet, int size, void (*f)(int*, int)){
    popul(vet, size);
    (*f)(vet, size);
    
    if(isSorted(vet, size)){
        printf("Funciona");
    }else{
        printf("Nao funciona");
    }
}

int findSmaller(int *vet){
    int small = vet[0];
    for(int i = 1; i < TAM; i++){
        if(vet[i] < small)
            small = vet[i];
    }
    return small;
}

int findLarger(int *vet){
    int larger = vet[0];
    for(int i = 1; i < TAM; i++){
        if(vet[i] > larger)
            larger = vet[i];
    }
    return larger;
}