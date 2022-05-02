#include "sorters.h"
#include "global.h"

#include <stdlib.h>
#include <limits.h>

void selectionSort(int *vet, int size){
    int min;
    for(int i = 0; i < size; i++){
        min = i;
        for(int j = i+1; j < size; j++){
            if (vet[j] < vet[min])
                min = j;
        }

        if(min != i){
            swap(&vet[min],&vet[i]);
        }
    }
}

void badSelectionSort(int *vet, int size){
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            if(vet[i] > vet[j])
                swap(&vet[i],&vet[j]);
        }
    }
}


void simpleBubble(int *vet, int size){
    for(int i = size-1; i > 0; i--){
        for(int j = 0; j <= i; j++){
            if(vet[j] > vet[j+1]){
                swap(&vet[j], &vet[j+1]);
            }
        }
    }
}

void whileBubble(int *vet, int size){
    int ordened = 0;
    int i = size - 1;
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

void quickSort(int *vet, int size){
    quickAux(vet, 0, size);
}

void cocktailSort(int *vet, int size){
    int ordened = 0;
    int bottom = 0;
    int top = size - 1;
    
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

void oddEvenSort(int *vet, int size){
    int ordened = 0;
    while(!ordened){
        ordened = 1;

        for(int i = 1; i < size - 1; i += 2){
            if(vet[i] > vet[i+1]){
                swap(&vet[i],&vet[i+1]);
                ordened = 0;
            }
        }

        for(int i = 0; i < size-1; i += 2){
            if(vet[i] > vet[i+1]){
                swap(&vet[i], &vet[i+1]);
                ordened = 0;
            }
        }
    }
}

void sortingBCouting(int *vet, int size){
    int v[TAM];

    for (int i = size-1; i >= 1; i--){
        for (int j = i-1; j >= 0; j--){
            if(vet[i] < vet[j])
                v[j]++;
            else
                v[i]++;
        }
    }

    int result[size];
    for(int i = 0; i < size; i++){
        result[v[i]] = vet[i];
    }

    for(int i = 0; i < size; i++){
        vet[i] = result[i];
    }
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

void mergeSort(int *vet, int size){
    part(vet, 0, size);
}

void radixSort(int *vet, int size) {
    int maior = vet[0];
    int exp = 1;

    int *b = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        if (vet[i] > maior)
    	    maior = vet[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };

    	for (int i = 0; i < size; i++)
    	    bucket[(vet[i] / exp) % 10]++;

    	for (int i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];

    	for (int i = size - 1; i >= 0; i--)
    	    b[--bucket[(vet[i] / exp) % 10]] = vet[i];

    	for (int i = 0; i < size; i++)
    	    vet[i] = b[i];

    	exp *= 10;
    }

    free(b);
}

void heapSort(int *vet, int size){
    int i = size/2, pai, filho, t;

    while(1){
        if(i > 0){
            i--;
            t = vet[i];
        }else{
            size--;
            if(size <= 0) return;
            t = vet[size];
            vet[size] = vet[0];
        }

        pai = i;
        filho = i*2 + 1;

        while(filho < size){
            if((filho + 1 < size) && (vet[filho+1] > vet[filho]) )
                filho++;
            if(vet[filho] > t){
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }else{
                break;
            }
        }
        vet[pai] = t;
    }
}

void insertionSort(int *vet, int size){
    int armazenador, j;

    for(int i = 1; i < size; i++){
        armazenador = vet[i];
        j = i - 1;

        while(j >= 0 && vet[j] > armazenador){
            vet[j+1] = vet[j];
            j--;
        }

        vet[j + 1] = armazenador;
    }
}

void coutingInplace(int *vet, int size) {
    int largerVal = findLarger(vet);
    int smallVal = findSmaller(vet);

    int countSize = largerVal - smallVal + 1;
    int *count = (int*) calloc( countSize, sizeof(int) );

    for(int i = 0; i < size; i++)
        count[ vet[i] - smallVal ]++;

    for(int i = 0, pos = 0; i < countSize; i++){
        while(count[i] > 0){
            vet[pos] = i + smallVal;
            pos++;
            count[i]--;
        }
    }

    free(count);
}

void shellSort(int * vet, int size){
    int pulos[5] = {1,2,3,5,7};
    int numPulos = 5;

    for(int *p = pulos + (numPulos - 1); p >= pulos; p--){
        int h = *p;

        for(int i = h; i < size; i++){
            int temp = vet[i];
            int j = i;

            while( j > h - 1 && temp <= vet[j - h]){

                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = temp;
        }
    }
}