#include <stdio.h>
#include <time.h>
#include <rand.h>

#define N = 20

void Insertion_Sort(int *array){
    int key;
    for(int j =  1; i < N; i++){
        key = array[j];
        int i = j - 1
        while( i >= 0 && array[i] > key){
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}

void Print_Array(int *array){
    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){
    int time;
    seed(time);
    int array[N];
    // Seleziono numeri da 1 a 100
    for(int i = 0; i < N; i++){
        array[i] = randi() % 100 + 1; 
    }

    Print_Array(array);
    Insertion_Sort(array);
    Print_Array(array);
}
