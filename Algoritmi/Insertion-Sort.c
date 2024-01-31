#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20

void Insertion_Sort(int *array){
    int key;

    // Loop che controlla tutti gli elementi dell'array tranne il primo
    for(int j = 1; j < N; j++){
        key = array[j];
        int i = j - 1;
        // Alla prima iterazione i = 0, j = 1, ossia si scambiano gli elementi 0 e 1
        // Supponendo che array = [10, 8, 5] allora durante il while [10, 10, 5]
        // Nella 2a iterazione [8,10,5] --> i = 1 --> [8,10,10] --> [8,8,10]  [*]
        while( i >= 0 && array[i] > key){
            array[i + 1] = array[i];
            // Si scorrono tutti gli elementi PRECENDENTI 
            // a quello selezionato in modo tale da non sovrascrivere alcun dato
            i--;
        }
        // When exiting the while either j = -1 or j = &(first lower number then key)
        // (Se l'elemento è il minimo dell'array allora qui si giunge con i = -1)
        array[i + 1] = key;
        // Alla fine del while [8,10,5]
        // 2. [5,8,10]
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
    Insertion_Sort(array);
    Print_Array(array);

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