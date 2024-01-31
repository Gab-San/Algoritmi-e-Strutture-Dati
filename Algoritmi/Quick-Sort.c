#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20


void Print_Array(int *array){
    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){
    srand(time(NULL));
    int array[N];
    // Seleziono numeri da 1 a 100
    for(int i = 0; i < N; i++){
        array[i] = rand() % 100 + 1; 
    }

    Print_Array(array);
    Merge_Sort(array,0, N-1);
    Print_Array(array);
}
