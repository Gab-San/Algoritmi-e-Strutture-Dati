#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100


/*

    This algorithm divides the array into subarrays recursively and it order the smaller subarrays.
    At the last recursive call each subarray will than be merged back into the first array.
    There's no real merging, but in the merge method requires the memory allocation of other arrays.
    
    The complexity of this algorithm is O(nlogn) 

*/


void Merge(int *arrayToOrder, int firstObjnum, int midObjnum, int lastObjnum){

    int firstArraylength = midObjnum - firstObjnum + 1; // 10 - 1 + 1
    int secondArraylenght = lastObjnum - midObjnum; // 20 - 10

    // Allocating the two temporary arrays
    int *left = (int*) malloc(sizeof(int) * (firstArraylength + 1) );
    int *right = (int*) malloc(sizeof(int) * (secondArraylenght + 1) );
    // Filling the two temporary arrays
    int counter;
    for(counter = 0; counter < firstArraylength; counter++){
        left[counter] = arrayToOrder[firstObjnum + counter - 1]; // LAST CALL: Filled with [0 ..... 9]
        if(counter== 0){ left[firstArraylength] = left[counter] + 1; }
        else if(left[counter] > left[firstArraylength]){
            left[firstArraylength] = left[counter] + 1;
        }
    }
    right[secondArraylenght] = left[firstArraylength];

    for(counter = 0; counter < secondArraylenght; counter++){
        right[counter] = arrayToOrder[midObjnum + counter]; // LAST CALL: [10..... 19]
        if(right[counter] > right[secondArraylenght]){
            right[secondArraylenght] = right[counter] + 1;
        }
    }
    if(right[secondArraylenght]>left[firstArraylength]) left[firstArraylength]=right[secondArraylenght];
    for(int i=0, j=0, k=firstObjnum; k <= lastObjnum; k++){ // k = {1,2,.....,20}
        if(left[i] < right[j]){
            arrayToOrder[k - 1] = left[i];
            i++;
        } else {
            arrayToOrder[k-1] = right[j];
            j++;
        }
    }

    free(left);
    free(right);

}


// Even though the first element in the array is 0 the firstObjnum in an array is 1 as it is the #1 obj in that array
void MergeSort(int *arrayToOrder, int firstObjnum, int lastObjnum){
    if(!(firstObjnum < lastObjnum)) return;

    int arrayMiddle = (firstObjnum + lastObjnum)/2;
    MergeSort(arrayToOrder, firstObjnum, arrayMiddle);
    MergeSort(arrayToOrder, arrayMiddle + 1, lastObjnum);
    printf("Entering Merge with %d %d %d\n", firstObjnum, arrayMiddle, lastObjnum);
    Merge(arrayToOrder, firstObjnum, arrayMiddle, lastObjnum); 
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

    MergeSort(input_array, 1, N);
    
    printf("\n");
    // Showing the results of the algorithm
    for(int i = 0; i < N; i++){
        printf("%d  ", input_array[i]);
    }
    printf("\n");

    return 0;
}