#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20

/*
    QuickSort is a divide et impera algorithm.
    -Base idea- Given an array A[p...r] to order it works on two steps:
                - organize the array in two subarrays A[p...q-1] and A[p...q+1] with the following requirements:
                    A[p..q-1] elements must all be minor or equal than A[q]
                    A[q+1...r] elements must all be greater or equal than A[q]
                - order the subarrays using QuickSort (recursively)
    
    This algorithm has an average complexity of O(nlog(n)) but in the worst case scenario it has a complexity of O(n^2) 
*/


int Partition(int* array, int first_elem_idx, int last_elem_idx){
    int pivot = array[last_elem_idx]; // Definizione del pivot
    int index = first_elem_idx - 1; // Inizia a -1
    for(int j = first_elem_idx; j < last_elem_idx; j++){
        if(array[j] <= pivot){
            index++;
            int temp = array[index];
            array[index] = array[j];
            array[j] = temp;
        }
    }
    // At the end of the for the array has been cycled through. The last value minor-equal to the pivot is at the position idx.
    // So the pivot must follow this number.
    int temp = array[index + 1];
    array[index + 1] = array[last_elem_idx];
    array[last_elem_idx] = temp;
    return index + 1;
}

void Quick_Sort(int* array, int first_elem_index, int last_elem_index){
    if(first_elem_index < last_elem_index){
        int middle_index = Partition(array, first_elem_index, last_elem_index);
        Quick_Sort(array, first_elem_index, middle_index - 1);
        Quick_Sort(array, middle_index + 1, last_elem_index);
    }
}

void Print_Array(int *array){
    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){
    time_t t;
    srand((unsigned) time(&t));
    int array[N];
    // Seleziono numeri da 1 a 100
    for(int i = 0; i < N; i++){
        array[i] = rand() % 100 + 1; 
    }

    Print_Array(array);
    Quick_Sort(array, 0, N-1);
    Print_Array(array);
}
