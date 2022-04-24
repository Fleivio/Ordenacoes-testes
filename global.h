#ifndef GLOBAL
#define GLOBAL

#define ITERATIONS 999
#define VARIATION_RANGE 10000
#define TAM 1000

void popul(int *vet, int tam);
void swap(int *p1, int *p2);
void printVet(int *vet, int tam);
void singleTest(int *vet, int tam, void (*f)(int*, int));
double speedTest( int *vet, int tam, void (*f)(int*, int) );

#endif