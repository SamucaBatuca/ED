#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define tam 100000

void merge(int A[], int p, int q, int r){
    int n1 = q-p;
    int n2 = r-q;
    
    
    int L[n1+1], R[n2+1];
    int i, j, k;
    
    for(i = 0; i < n1;i++){
        L[i] = A[p+i];
        
    }
    
    for(j = 0; j< n2; j++){
        R[j] = A[q+j];
        
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i=j=0;
    
    for (k=p; k<r; k++){
        
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}



void mergeSort(int A[], int p, int r){
    
    if (r - p >1){
        int q = (p+r)/2;
        
        mergeSort(A,p,q);
        
        mergeSort(A,q,r);
        
        merge(A,p,q,r);
         
    }
}



int main (){

    int A[tam];
    
    mergeSort(A,0,10);
    
    for(int i=0; i<tam ;i++){
        A[i]= i;
    }

    return 0;
}