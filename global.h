#ifndef GLOBAL
#define GLOBAL

#define ITERATIONS 1000
#define VARIATION_RANGE 10000
#define TAM 1000

void popul(int *vet, int size);
void swap(int *p1, int *p2);
void printVet(int *vet, int size);
void singleTest(int *vet, int size, void (*f)(int*, int));
double speedTest( int *vet, int size, void (*f)(int*, int) );

int findSmaller(int *vet);
int findLarger(int *vet);

#endif