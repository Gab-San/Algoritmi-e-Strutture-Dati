#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

/*
    QuickSort is a divide et impera algorithm.
    -Base idea- Given an array A[p...r] to order it works on two steps:
                - organize the array in two subarrays A[p...q-1] and A[p...q+1] with the following requirements:
                    A[p..q-1] elements must all be minor or equal than A[q]
                    A[q+1...r] elements must all be greater or equal than A[q]
                - order the subarrays using QuickSort (recursively)
    
    This algorithm has an average complexity of O(nlog(n)) but in the worst case scenario it has a complexity of O(n^2) 

*/


/*
    Partition is the auxiliary algorithm that partitions the array in two sets.
    This is the difficult part due to the nature of the array, it's always possible that the partitions ends up being 
    at the second element of the array resulting in the worst case scenario

    - A[p...i] is the partition with the elements minor-equal to the pivot
    - A[i+1..j-1] is the partition with elements major-equal to the pivot
    - A[j...r-1] is the partition with the elements to examine
    - A[r] is the pivot

    The complexity is O(n)
*/
int Partition(int input_array[], int firstObjnum, int lastObjnum){
    int pivot = input_array[lastObjnum];
    int idx = firstObjnum - 1;
    // Cycling through the array partitioning it
    for(int j = firstObjnum; j < lastObjnum; j++){
        if(input_array[j] <= pivot){
            idx++; // Following the last element minor-equal to pivot
            int temp = input_array[idx];
            input_array[idx] = input_array[j];
            input_array[j] = temp;
        }
    }
    // At the end of the for the array has been cycled through. The last value minor-equal to the pivot is at the position idx.
    // So the pivot must follow this number.
    int temp = input_array[idx + 1];
    input_array[idx + 1] = input_array[lastObjnum];
    input_array[lastObjnum] = temp;
    // At this point idx + 1 contains the pivot and is the value of the partition
    return idx + 1;
}



/*
    This is the main algorithm that recursively orders the elements in the array
*/
void QuickSort(int input_array[], int firstObjnum, int lastObjnum){
    int middleObjnum;

    if (firstObjnum < lastObjnum){
        middleObjnum = Partition(input_array, firstObjnum, lastObjnum);
        QuickSort(input_array, firstObjnum, middleObjnum - 1);
        QuickSort(input_array, middleObjnum + 1, lastObjnum);
    }
}


/*********** MAIN **************/
/*
    Initializes an array of N with random numbers and runs the sorting algorithm
*/
int main(){

    int input_array[N];
    // Initialize random number generator
    time_t t;
    srand((unsigned) time(&t));

    // Initializing array with different number values
    for(int i = 0; i < N; i++){
        input_array[i] = rand() % 100 + 1; // Will be using numbers from 1 to 100
        printf("%d  ", input_array[i]);
    }
    printf("\n");

    QuickSort(input_array, 0, N-1);
    
    printf("\n");
    // Showing the results of the algorithm
    for(int i = 0; i < N; i++){
        printf("%d  ", input_array[i]);
    }
    printf("\n");

    return 0;
}
