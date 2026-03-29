#include <stdio.h>
#include <stdlib.h>


#define tam 100000000


void insertionSort(long long int A[]){

    int i;
    int j;
    int aux;
    for (i=1; i<tam; i++){
        aux = A[i];
        
        j = i-1;
        while(j>-1 && A[j] > aux){
            A[j+1]= A[j];
            
            j--;
        }
        A[j+1]=aux;
        
    }


}


int main (){

    long long int A[tam];

    for (int aux = 0; aux<tam; aux++){
        A[aux] = aux;
    }

    insertionSort(A);

    

    /*for (int aux = 0; aux<tam; aux++){
        printf("\n%d", A[aux]);
    }*/



}

