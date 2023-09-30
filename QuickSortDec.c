#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

/*
    Partition is the auxiliary algorithm that partitions the array in two sets.
    This is the difficult part due to the nature of the array, it's always possible that the partitions ends up being 
    at the second element of the array resulting in the worst case scenario

    - A[p...i] is the partition with the elements major-equal to the pivot
    - A[i+1..j-1] is the partition with elements minor-equal to the pivot
    - A[j...r-1] is the partition with the elements to examine
    - A[r] is the pivot

    The complexity is O(n)
*/
int Partition(int input_array[], int firstObjidx, int lastObjidx){
    int pivot = input_array[lastObjidx];
    int idx = firstObjidx - 1;
    // Cycling through the array partitioning it
    for(int j = firstObjidx; j < lastObjidx; j++){
        if(input_array[j] >= pivot){
            idx++; // Following the last element major-equal to pivot
            int temp = input_array[idx];
            input_array[idx] = input_array[j];
            input_array[j] = temp;
            // The element in the first position will be the first one to be the major equal to pivot
            // and so on. The other element will be swapped.
        }
    }
    // At the end of the for the array has been cycled through. idx points at the last value major-equal to pivot
    // So the pivot must follow this number. Swapping again:
    int temp = input_array[idx+1];
    input_array[idx + 1] = input_array[lastObjidx];
    input_array[lastObjidx] = temp;
    // At this point idx + 1 is the position of the pivot
    return idx + 1;
}


/*
    This algorithm recursively orders the array from biggest to lowest 
    It's complexity is O(nlog(n))
*/
void QuickSortDec(int input_array[], int firstObjidx, int lastObjidx){
    int partitionidx;

    if (firstObjidx < lastObjidx){
        partitionidx = Partition(input_array, firstObjidx, lastObjidx);
        QuickSortDec(input_array, firstObjidx, partitionidx - 1);
        QuickSortDec(input_array, partitionidx + 1, lastObjidx);
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

    QuickSortDec(input_array, 0, N-1);
    
    printf("\n");
    // Showing the results of the algorithm
    for(int i = 0; i < N; i++){
        printf("%d  ", input_array[i]);
    }
    printf("\n");

    return 0;
}
