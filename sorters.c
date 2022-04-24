#include "sorters.h"
#include "global.h"

#include <stdlib.h>
#include <limits.h>

void selectionSort(int *vet, int tam){
    int min;
    for(int i = 0; i < tam; i++){
        min = i;
        for(int j = i+1; j < tam; j++){
            if (vet[j] < vet[min])
                min = j;
        }

        if(min != i){
            swap(&vet[min],&vet[i]);
        }
    }
}

void badSelectionSort(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = i; j < tam; j++){
            if(vet[i] > vet[j])
                swap(&vet[i],&vet[j]);
        }
    }
}

void insertionSort(int *vet, int tam){
    int eleito, j;

    for(int i = 1; i < tam; i++){
        eleito = vet[i];
        j = i-1;

        while(vet[j] > eleito && j >= 0){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j + 1] = eleito;
    }
}



void simpleBubble(int *vet, int tam){
    for(int i = tam-1; i > 0; i--){
        for(int j = 0; j <= i; j++){
            if(vet[j] > vet[j+1]){
                swap(&vet[j], &vet[j+1]);
            }
        }
    }
}

void whileBubble(int *vet, int tam){
    int ordened = 0;
    int i = tam - 1;
    while(!ordened && i > 0){
        ordened = 1;
        for(int j = 0; j < i; j++){
            if(vet[j] > vet[j+1]){
                swap(&vet[j], &vet[j+1]);
                ordened = 0;
            }
        }
        i--;
    }
}

static void quickAux(int *vet, int begin, int end){
    int i, j, pivo, aux;
    i = begin;
    j = end-1;
    pivo = vet[(int)((begin+end)/2)];

    while(i <= j){
        while(vet[i] < pivo && i < end){
            i++;
        }

        while(vet[j] > pivo && j > begin){
            j--;
        }

        if(i <= j){
            swap(&vet[i], &vet[j]);
            i++;
            j--;
        }
    }

    if(j > begin)
        quickAux(vet, begin, j+1);
    if(i < end)
        quickAux(vet, i, end);
}

void quickSort(int *vet, int tam){
    quickAux(vet, 0, tam);
}

void cocktailSort(int *vet, int tam){
    int ordened = 0;
    int bottom = 0;
    int top = tam - 1;
    
    while(ordened == 0 && bottom < top){
        ordened = 1;

        for(int i = bottom; i < top; i++){
            if(vet[i] > vet[i+1]){
                swap(&vet[i], &vet[i+1]);
                ordened = 0;
            }
        }
        top--;

        for(int i = top; i > bottom; i--){
            if(vet[i] < vet[i-1]){
                swap(&vet[i], &vet[i-1]);
                ordened = 0;
            }
        }
        bottom++;
    }
}

void oddEvenSort(int *vet, int tam){
    int ordened = 0;
    while(!ordened){
        ordened = 1;

        for(int i = 1; i < tam - 1; i += 2){
            if(vet[i] > vet[i+1]){
                swap(&vet[i],&vet[i+1]);
                ordened = 0;
            }
        }

        for(int i = 0; i < tam-1; i += 2){
            if(vet[i] > vet[i+1]){
                swap(&vet[i], &vet[i+1]);
                ordened = 0;
            }
        }
    }
}

void sortingBCouting(int *vet, int tam){
    int *v = (int*) calloc(tam, sizeof(int));

    for (int i = tam-1; i >= 1; i--){
        for (int j = i-1; j >= 0; j--){
            if(vet[i] < vet[j])
                v[j]++;
            else
                v[i]++;
        }
    }

    int result[tam];
    for(int i = 0; i < tam; i++){
        result[v[i]] = vet[i];
    }

    for(int i = 0; i < tam; i++){
        vet[i] = result[i];
    }
    free(v);
}


static void merge(int *vet, int p, int q, int r){
    int n1 = q - p;
    int n2 = r - q;
    int i, j, k;

    int * L = malloc(n1 * sizeof(int));
    int * R = malloc(n2 * sizeof(int));

    for (i=0; i<n1; i++)
        L[i] = vet[p+i];
    for (j=0; j<n2; j++)
        R[j] = vet[q+j];

    i = 0;
    j = 0;

    for(k=p;k<r;k++){
        if(j>=n2 || i<n1 && L[i]<=R[j])
            vet[k] = L[i++];
        else
            vet[k] = R[j++];
    }

    free(L);
    free(R);
}

static void part(int *vet, int p, int r){
    int q;

    if ((r - p) < 2)
        return;

    q = (p+r)/2;

    part(vet, p, q);
    part(vet, q, r);
    merge(vet, p, q, r);
}

void mergeSort(int *vet, int tam){
    part(vet, 0, tam);
}

void radixSort(int *vet, int tam) {
    int maior = vet[0];
    int exp = 1;

    int *b = (int *)calloc(tam, sizeof(int));

    for (int i = 0; i < tam; i++) {
        if (vet[i] > maior)
    	    maior = vet[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };

    	for (int i = 0; i < tam; i++)
    	    bucket[(vet[i] / exp) % 10]++;

    	for (int i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];

    	for (int i = tam - 1; i >= 0; i--)
    	    b[--bucket[(vet[i] / exp) % 10]] = vet[i];

    	for (int i = 0; i < tam; i++)
    	    vet[i] = b[i];

    	exp *= 10;
    }

    free(b);
}