#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20

int Max(int* array, int len){
    int max = array[0];
    for(int i = 1; i < len; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

void Merge(int* array, int startingIndex, int middleIndex, int lastIndex){

    // Calcolo della lunghezza delle partizioni
    int len_array_1 = middleIndex - startingIndex;
    int len_array_2 = lastIndex - middleIndex;
    // Costruzione di partizioni tramite array ausiliari
    int *aux_array_1 = (int*) malloc(sizeof(int) * (len_array_1 + 1));
    for(int i= 0; i < len_array_1; i++){
        aux_array_1[i] = array[startingIndex + i];
    }

    int *aux_array_2 = (int*) malloc(sizeof(int) * (len_array_2 + 1));
    // Da 10 a 19
    for(int i = 0; i < len_array_2; i++){
        aux_array_2[i] = array[middleIndex + i];
    }

    // Tali valori servono ad assicurare che non vi sia buffer overflow nel merge sottostante
    // Non incide sulla complessità a livello asintotico. Appesantisce il codice
    aux_array_1[len_array_1] = Max(aux_array_2, len_array_2) + 1;
    aux_array_2[len_array_2] = Max(aux_array_1, len_array_1) + 1;

    int i = 0;
    int j = 0;
    // Riordinamento dell'array
    // Si noti che nel caso di due elementi basta scambiare tra loro gli elementi
    for(int k = startingIndex; k < lastIndex){
        if(aux_array_1[i] <= aux_array_2[j] ){
            array[k] = aux_array_1[i];
            i++;
        } else {
            array[k] = aux_array_2[j]; 
            j++;
        }
    }

    free(aux_array_1);
    free(aux_array_2);

}


void Merge_Sort(int* array, int startingIndex, int lastIndex){
    if(startingIndex < lastIndex){
        // L'arrotondamento per difetto è già definito per le divisioni di interi
        int middleIndex = (startingIndex + lastIndex + 1) / 2;

        // Divide et Impera: divide in due l'array
        // Analisi della prima partizione dell'array
        Merge_Sort(array, startingIndex, middleIndex);
        // Analisi della seconda partizione dell'array
        Merge_Sort(array, middleIndex +1, lastIndex);
        // Rimette assieme gli array partizionati
        Merge(array, startingIndex, middleIndex, lastIndex);
    }

}




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
