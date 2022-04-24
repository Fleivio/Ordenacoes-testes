#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "global.h"
#include "sorters.h"

int main(){
    srand(time(NULL));
    int vet[TAM];

    // singleTest(vet, &radixSort);

    printf("\nBubble-while = %.3f secs",  speedTest(vet, &whileBubble));
    printf("\nCocktail sort = %.3f secs", speedTest(vet, &cocktailSort));
    printf("\nOdd-even sort = %.3f secs", speedTest(vet, &oddEvenSort));
    printf("\nInsertion sort = %.3f secs", speedTest(vet, &insertionSort));
    printf("\nSelection sort = %.3f secs", speedTest(vet, &selectionSort));
    printf("\nQuick sort = %.3f secs", speedTest(vet, &quickSort));
    printf("\nMerge sort = %.3f secs", speedTest(vet, &mergeSort));
    printf("\nRadix sort = %.3f secs", speedTest(vet, &radixSort));
}
