#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define tam 100000

void merge(int A[], int p, int q, int r){
    int n1 = q-p;
    int n2 = r-q;
    printf("n1 = %d; n2 = %d\n", n1, n2);
    
    int L[n1+1], R[n2+1];
    int i, j, k;
    
    for(i = 0; i < n1;i++){
        L[i] = A[p+i];
        printf("L[i] = %d\n", L[i]);
    }
    
    for(j = 0; j< n2; j++){
        R[j] = A[q+j];
        printf("R[j] = %d\n", R[j]);
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i=j=0;
    
    for (k=p; k<r; k++){
        printf("L[i] = %d; R[j] = %d\n", L[i], R[j]);
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
    printf("p = %d; r = %d\n", p, r);
    if (r - p >1){
        int q = (p+r)/2;
        printf("q = %d\n", q);
        mergeSort(A,p,q);
        printf("voltei com q = %d e r = %d\n", q,r);
        mergeSort(A,q,r);
        printf("passei por MERGE com p = %d; q = %d; r = %d\n", p, q, r);
        merge(A,p,q,r);
         
    }
}



int main (){

    int A[] = {3,1,4,2,5,7,8,6,9,0};
    
    mergeSort(A,0,10);
    
    for(int i=0; i<10 ;i++){
        printf("%d\n", A[i]);
    }

    return 0;
}