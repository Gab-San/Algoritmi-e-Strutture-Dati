#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

/*
    HeapSort is an algorithm based on the premise that an array can be seen as a binary tree 

    A[1] is the root
    A[2i] are the left children and A[2i+1] are the right children
    Each parent will be A[floor(i/2)] 

    It orders an array without the need of allocating further memory.
    In a max-heap A[Parent(i)] >= A[i] (min-heap exist too).

    The complexity of this algorithm is O(nlogn)
*/


// Heap attributes: Length (total number of elements in the array), Heap-Size (number of elements in the heap)

int heap_size;

// Left returns the left child of the selected item
int Left(int index){
    return 2*index;
}
// Right returns the right child of the seleted item
int Right(int index){
    return 2*index + 1;
}

/* 
    This is an auxiliary algorithm that checks if the sub-tree of the related index is a max-heap and 
    modifies the array so that the whole sub-tree is a max-heap

    This algorithm complexity is O(h): h the height of the tree --> O(log(n))
*/
void Max_Heapify(int input_array[], int index){
    int left_child = Left(index);
    int right_child = Right(index);
    int max; // Index in which the maximum value is stored

    // It is a strictly minor because otherwise on the iteration of the first leaf it would get the first element out of the array
    if(left_child < heap_size && input_array[left_child] > input_array[index]){
        max = left_child; // The maximum value is in the left_child and the sub-tree is not a max-heap
    } else {
        max = index;
    }

    if(right_child < heap_size && input_array[right_child] > input_array[max]){
        max = right_child; // The maximum value is in the right_child and the sub-tree is not a max-heap
    }

    if(max != index){ // The maximum is not the parent
        // Put the max value in the parent and the value of the parent in the current max between the children
        int temp = input_array[index];
        input_array[index] = input_array[max];
        input_array[max] = temp;
        // 'max' will now store a value that might not be the max in the sub-tree
        // Recursively going _down_ into the sub-trees
        Max_Heapify(input_array, max);
    }
}

/* Building the max-heap bottom-up
    14 13 15 11 16 8 7 9 10
                14
            13      15
          11  16   8  7
      9   10

    N.B. All the elements after A.length/2 are leafs

    The complexity of this algorithm is O(nlog(n)): n/2 calls to Max-Heapify (for i = array_length/2) that is O(log(n))
*/
void Build_Max_Heap(int input_array[], int array_length){
    heap_size = array_length; 
    for(int i = array_length/2 - 1; i >= 0; i--){ // Starting from the inner nodes up to the root 
        // Builds a Max-Heap from the nodes up
        Max_Heapify(input_array, i);
    }
}

/*
    After having built a max-heap, at each cycle lets put the biggest element (the first in the array since it's a max-heap)
    at the end of the array to order (consisting of the heap); furthermore the heap is decreased by 1 each iteration and
    Max-Heapify corrects the heap to a max-heap.

    The complexity of HeapSort is O(nlog(n)): Build-Max-Heap is O(nlog(n)) + Max-Heapify that costs O(log(n)) called n-1 times
*/
void HeapSort(int input_array[], int array_length){
    Build_Max_Heap(input_array, array_length);
    // Swapping the first element of the array with the last one and decreasing heap-size
    for(int i = array_length - 1; i > 0; i--){
        int temp = input_array[0];
        input_array[0] = input_array[i];
        input_array[i] = temp;
        heap_size -= 1;
        // Correct the max-heap recursively from the new root (left child of the original)
        Max_Heapify(input_array, 0);
    }
}
/*
    14 13 15 11 16 8 7 9 10
                  14
              13      15
            11  16   8  7
           9  10
    
    After Build-max-heap
                  16
              14      15
            11  13   8  7
           9  10
    After swap
    10 14 15 11 13 8 7 9 16
                  10
              14      15
            11  13   8  7
           9  16

    First iteration of max-heapify
                  15
              14      10
            11  13   8  7
           9  16

    And so forth
*/

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


    Build_Max_Heap(input_array, N);
    
    printf("\n");
    // Showing the results of the algorithm
    for(int i = 0; i < N; i++){
        printf("%d  ", input_array[i]);
    }
    printf("\n");

    return 0;
}
