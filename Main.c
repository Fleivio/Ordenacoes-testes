#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "global.h"
#include "sorters.h"

int main(){
    srand(time(NULL));
    int vet[TAM];

    // singleTest(vet, TAM, &radixSort);

    printf("\nBubble-while = %.3f secs",  speedTest(vet, TAM, &whileBubble));
    printf("\nCocktail sort = %.3f secs", speedTest(vet, TAM, &cocktailSort));
    printf("\nOdd-even sort = %.3f secs", speedTest(vet, TAM, &oddEvenSort));
    printf("\nInsertion sort = %.3f secs", speedTest(vet, TAM, &insertionSort));
    printf("\nSelection sort = %.3f secs", speedTest(vet, TAM, &selectionSort));
    printf("\nQuick sort = %.3f secs", speedTest(vet, TAM, &quickSort));
    printf("\nMerge sort = %.3f secs", speedTest(vet, TAM, &mergeSort));
    printf("\nRadix sort = %.3f secs", speedTest(vet, TAM, &radixSort));
}
