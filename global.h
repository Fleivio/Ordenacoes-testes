#ifndef GLOBAL
#define GLOBAL

#define ITERATIONS 999
#define VARIATION_RANGE 10000
#define TAM 1000

void popul(int *vet);
void swap(int *p1, int *p2);
void printVet(int *vet);
void singleTest(int *vet, void (*f)(int*));
double speedTest( int *vet, void (*f)(int*) );

#endif