#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int heap_size;

// Left returns the left child of the selected item
int Left(int index){
    return 2*index;
}
// Right returns the right child of the seleted item
int Right(int index){
    return 2*index + 1;
}

void Min_Heapify(int input_array[], int index){
    int left_child = Left(index);
    int right_child = Right(index);
    int min;

    if(left_child < heap_size && input_array[left_child] < input_array[index]){
        min = left_child;
    } else {
        min = index;
    }

    if(right_child < heap_size && input_array[right_child] < input_array[min]){
        min = right_child;
    }

    if(min != index){ // The minimum is not the parent
        // Put the min value in the parent and the value of the parent in the current min between the children
        int temp = input_array[index];
        input_array[index] = input_array[min];
        input_array[min] = temp;
        // 'min' will now store a value that might not be the min in the sub-tree
        // Recursively going _down_ into the sub-trees
        Min_Heapify(input_array, min);
    }
}

void Build_Min_Heap(int input_array[], int array_length){
    heap_size = array_length; 
    for(int i = array_length/2 - 1; i >= 0; i--){ // Starting from the inner nodes up to the root 
        // Builds a Max-Heap from the nodes up
        Min_Heapify(input_array, i);
    }
}

void HeapSort(int input_array[], int array_length){
    Build_Min_Heap(input_array, array_length);
    // Swapping the first element of the array with the last one and decreasing heap-size
    for(int i = array_length - 1; i > 0; i--){
        int temp = input_array[0];
        input_array[0] = input_array[i];
        input_array[i] = temp;
        heap_size -= 1;
        // Correct the max-heap recursively from the new root (left child of the original)
        Min_Heapify(input_array, 0);
    }
}

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

    int array_length = N;

    HeapSort(input_array, array_length);
    
    printf("\n");
    // Showing the results of the algorithm
    for(int i = 0; i < N; i++){
        printf("%d  ", input_array[i]);
    }
    printf("\n");

    return 0;
}
