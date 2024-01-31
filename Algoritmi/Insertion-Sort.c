#include <stdio.h>
#include <time.h>
#include <rand.h>

#define N 20

void Insertion_Sort(int *array){
    int key;

    // Loop che controlla tutti gli elementi dell'array tranne il primo
    for(int j = 1; i < N; j++){
        key = array[j];
        int i = j - 1;
        // Alla prima iterazione i = 0, j = 1, ossia si scambiano gli elementi 0 e 1
        // Supponendo che array = [10, 8, 5] allora durante il while [10, 10, 5]
        // Nella 2a iterazione [8,10,5] --> i = 1 --> [8,10,10] --> [8,8,10]
        while( i >= 0 && array[i] > key){
            array[i + 1] = array[i];
            // Si scorrono tutti gli elementi PRECENDENTI 
            // a quello selezionato in modo tale da non sovrascrivere alcun dato
            i--;
        }
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
    srand(time(NULL))
    int array[N];
    // Seleziono numeri da 1 a 100
    for(int i = 0; i < N; i++){
        array[i] = rand() % 100 + 1; 
    }

    Print_Array(array);
    Insertion_Sort(array);
    Print_Array(array);
}
