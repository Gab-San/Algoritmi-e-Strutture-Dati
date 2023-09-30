#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

/*
    This is the simplest algorithm that can be used for sorting it consists of swapping numbers from the second one in the array 
    to the last one, checking the previous positions.

    The complexity of this algorithm is O(n^2)
*/
void InsertionSort(int *arrayToOrder){

    int key, j; // key will be used as a temporary var to store the value to order at each step into the array

    for(int i = 1; i < N; i++){
        key = arrayToOrder[i]; // Saving the value to compare at the step i
        j = i-1; // Setting the first comparison
        while (j >= 0 && arrayToOrder[j] > key){ // Going back into the array each value higher than key will be swapped to the
                                                 // slot forward; [*]
            arrayToOrder[j+1] = arrayToOrder[j];
            j--;
        }  
        // When exiting the while either j = -1 or j = &(first lower number then key)
        arrayToOrder[j+1] = key;
    }
}

/*********** MAIN **************/
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

    InsertionSort(input_array);
    
    printf("\n");
    // Showing the results of the algorithm
    for(int i = 0; i < N; i++){
        printf("%d  ", input_array[i]);
    }
    printf("\n");

    return 0;
}




/*

    [*] Note that pushing forward objects into an array will not overwrite other objects meaning that at the end of the sorting no 
    object will be lost. This is due to the fact that by saving the last object value of the step and going back, if no errors occur,
    the first iteration will replace the stored object, therefore there will be a duplicate of the object before it.
    Each overwrite will then replace a duplicated object until the selected object ("key") is sorted.
    2 1 3 10 16 5 -> key=1; 2 2 3 10 16 5 -> key=1; 1 2 3 10 16 5
    1 2 3 10 16 5 -> key=5; 1 2 3 10 16 16 ->key=5; 1 2 3 10 10 16 -> key=5; 1 2 3 5 10 16
*/