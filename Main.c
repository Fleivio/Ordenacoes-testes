#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "global.h"
#include "sorters.h"

int main(){
    srand(time(NULL));
    int vet[TAM];

    // singleTest(vet, TAM, &mergeSort);
    // printVet(vet, TAM);
    
    {
        printf("\nTAMANHO DO VETOR = %d\n", TAM);
        printf("VARIACAO DAS CHAVES = %d\n", VARIATION_RANGE);
        printf("QUANTIDADE DE ITERACOES = %d\n", ITERATIONS);
    printf("\nSelection sort = %.3f secs", speedTest(vet, TAM, &selectionSort));
    printf("\nInsertion sort = %.3f secs", speedTest(vet, TAM, &insertionSort));
    printf("\nBubble sort = %.3f secs",  speedTest(vet, TAM, &bubbleSort));
    printf("\nSorting by counting = %.3f secs", speedTest(vet, TAM, &coutingInplace));

    printf("\nCocktail sort = %.3f secs", speedTest(vet, TAM, &cocktailSort));
    printf("\nOdd-even sort = %.3f secs", speedTest(vet, TAM, &oddEvenSort));

    printf("\nQuick sort = %.3f secs", speedTest(vet, TAM, &quickSort));
    printf("\nQuick sort pointer = %.3f secs", speedTest(vet, TAM, &quickSortPointer));

    printf("\nMerge sort = %.3f secs", speedTest(vet, TAM, &mergeSort));

    printf("\nShell sort = %.3f secs", speedTest(vet, TAM, &shellSort));

    printf("\nRadix sort = %.3f secs", speedTest(vet, TAM, &radixSort));

    printf("\nHeap sort = %.3f secs", speedTest(vet, TAM, &heapSort));

    }
    

    puts("");
    
}