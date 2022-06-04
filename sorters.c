#include "sorters.h"
#include "global.h"

#include <stdlib.h>


//SELECTION SORT
void selectionSort(int *vet, int size){
    int min;

    for(int i = 0; i < size; i++){
        min = i;
        for(int j = i; j < size; j++){
            if(vet[j] < vet[min])
                min = j;
        }

        if(min != i)
        swap(&vet[min], &vet[i]);
    }
}

//INSERTION SORT
void insertionSort(int *vet, int size){
    int tmp, j;

    for(int i = 1; i < size; i++){
        tmp = vet[i];
        j = i - 1;

        while(j >= 0 && vet[j] > tmp){
            vet[j+1] = vet[j];
            j--;
        }

        vet[j + 1] = tmp;
    }
}


//BUBBLE SORT
void bubbleSort(int *vet, int size){
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

//SORTIN BY COUNTING
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

//COCKTAIL SORT
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

//ODD EVEN SORT
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


//QUICK SORT
static void _quickSort(int *vet, int begin, int end){
    if(begin >= end) return;
    int i, j, pivo;
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

    _quickSort(vet, begin, j+1);
    _quickSort(vet, i, end);
}

void quickSort(int *vet, int size){
    _quickSort(vet, 0, size);
}


void _quickSortPointer(int *begin, int *end) { 
    if (begin >= end)
        return;

    int pivo = *(begin + ((end - begin) >> 1));
    int *l = begin;
    int *r = end;
    
    do{ 
        while(*l < pivo && l <= r)
            l++;
        while(*r > pivo && r >= l)
            r--;
            
        if(l <= r){
            swap(r, l);
            l++;
            r--;
        }

    } while(l < r);
    
    _quickSortPointer(begin, r);
    _quickSortPointer(l, end);
}

void quickSortPointer(int *vet, int size){
    _quickSortPointer(vet, vet + size - 1);
}

//MERGE SORT
static void merge(int *vet, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? vet[i++]
             : i == m      ? vet[j++]
             : vet[j] < vet[i] ? vet[j++]
             :               vet[i++];
    }
    for (i = 0; i < n; i++) {
        vet[i] = x[i];
    }
    free(x);
}

void mergeSort(int *vet, int size) {
    if (size < 2)
        return;
    int m = size / 2;
    mergeSort(vet, m);
    mergeSort(vet + m, size - m);
    merge(vet, size, m);
}

//SHELL SORT
void shellSort(int * vet, int size){
    int h, i, j, t;
    for (h = size; h /= 2;) {
        for (i = h; i < size; i++) {
            t = vet[i];
            for (j = i; j >= h && t < vet[j - h]; j -= h) {
                vet[j] = vet[j - h];
            }
            vet[j] = t;
        }
    }
}

//RADIX SORT
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

//HEAP SORT
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

//COMB SORT
void combSort(int *vet, int size) {
    int i, j, gap, swapped = 1;
    int temp;

    gap = size;

    while (gap > 1 || swapped == 1)
    {
        gap = gap * 10 / 13;
        if (gap == 9 || gap == 10) gap = 11;
        if (gap < 1) gap = 1;
        swapped = 0;

        for (i = 0, j = gap; j < size; i++, j++)
        {
            if (vet[i] > vet[j])
            {
                swap(&vet[i], &vet[j]);
                swapped = 1;
            }
        }
    }
}

//GNOME SORT
void gnomeSort(int *vet, int size)
{
    int i=1, j=2, t;

    while(i < size) {
        if (vet[i - 1] > vet[i]) {
            swap(&vet[i-1], &vet[i]);
            if (--i) continue;
        }

        i = j++;
    }
}

//PANCAKE SORT

void do_flip(int *vet, int num)
{
    for(int i = 0; i < --num ; i++){
        swap(&vet[i], &vet[num]);
    }
}

void pancakeSort(int *vet, int size){
    int i, a, max_num_pos;

    for(i = size; i > 1 ; i--){
        max_num_pos=0;
        for( a = 0; a < i ; a++){
            if(vet[a]>vet[max_num_pos])
                max_num_pos=a;
        }

        if(max_num_pos == i-1)
            continue;

        if(max_num_pos){
            do_flip(vet, max_num_pos+1);
        }

        do_flip(vet, i);
    }
}