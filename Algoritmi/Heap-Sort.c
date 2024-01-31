#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20

int heap_size;

int GetParent(int i){
    return i/2;
}

int GetLeftChild(int i){
    return 2*i;
}

int GetRightChild(int i){
    return 2*i + 1;
}


// Si assicura che l'elemento i rispetti al condizione per cui A[i] >= A[GetLeftChild(i)] 
// && A[i] >= A[GetRightChild(i)] ovvero l'albero sia un max-heap

// La complessità è O(h) con altezza dell'albero
void Max_Heapify(int *array, int i){
    // Riferimento ai figli
    int leftChild = GetLeftChild(i);
    int rightChild = GetRightChild(i);
    // Ricerca dell'elemento massimo
    int max;
    if (leftChild < heap_size && array[leftChild] > array[i]){
        max = leftChild;
    } else {
        max = i;
    }
    if(rightChild < heap_size && array[rightChild] > array[max]){
        max = rightChild;
    }

    if (max != i){
        int temp = array[max];
        array[max] = array[i];
        array[max] = array[i];
        // In maniera ricorsiva controlla che il sottoalbero così modificato rispetti la condizione di max-heap
        Max_Heapify(array, max);
    }
}

// OSSERVAZIONE: Tutti gli elementi oltre l'indice array.length/2 sono foglie
// Complessità O(n)
void Build_Max_Heap(int *array, int array_length){
    heap_size = array_length;
    for(int i = array_length/2 - 1; i >= 0; i-- ){
        Max_Heapify(array, i);
    }

}


// Complessità O(n)+ O(logn)*O(n) = O(n logn)
void Heap_Sort(int * array, int array_length){
    Build_Max_Heap(array, array_length);
    for(int i = array_length - 1; i > 0; i--){
        int temp = array[1];
        array[1] = array[i];
        array[i] = temp;
        // Ogni iterazione di Max_Heapify considererà tutti quei nodi che sono effettivamente nello heap
        // vengono spostati fuori dallo heap uno per volta i nodi più alti; (Vengono ordinati dalla fine dell'array fino all'inizio)
        heap_size--;
        Max_Heapify(array, 0);
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
    Heap_Sort(array, N);
    Print_Array(array);

    return 0;
}
