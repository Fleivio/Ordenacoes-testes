#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "global.h"
#include "sorters.h"

int main(){
    srand(time(NULL));
    int vet[TAM];

    singleTest(vet, TAM, &insertionSort);
    
    // {
    // printf("\nBubble-while = %.3f secs",  speedTest(vet, TAM, &whileBubble));
    // printf("\nCocktail sort = %.3f secs", speedTest(vet, TAM, &cocktailSort));
    // printf("\nOdd-even sort = %.3f secs", speedTest(vet, TAM, &oddEvenSort));
    // printf("\nInsertion sort = %.3f secs", speedTest(vet, TAM, &insertionSort));
    // printf("\nSelection sort = %.3f secs", speedTest(vet, TAM, &selectionSort));
    // printf("\nQuick sort = %.3f secs", speedTest(vet, TAM, &quickSort));
    // printf("\nMerge sort = %.3f secs", speedTest(vet, TAM, &mergeSort));
    // printf("\nRadix sort = %.3f secs", speedTest(vet, TAM, &radixSort));
    // printf("\nHeap sort = %.3f secs", speedTest(vet, TAM, &heapSort));
    // }
    
}