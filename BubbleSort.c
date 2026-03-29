#include <stdio.h>
#include <stdlib.h>

#define tam  100000


void bubbleSort(int A[]){
    int i, j;
    for(i = 0; i < tam; i++){
        for(j = 0; j < (tam - i - 1); j++){
            if(A[j] > A[j+1]){
                int aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                
            }
        }

    }
}



int main (){

    int A[tam];
    
    for(int i=0; i<tam ;i++){
        A[i]= i;
    }
    
    /*for(int i=tam; i>0 ;i--){
        A[i]= i;
    }*/
    
    bubbleSort(A);
    
    

    return 0;
}