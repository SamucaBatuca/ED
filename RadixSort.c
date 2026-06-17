#include <stdlib.h>
#include <stdio.h>

#define tam 1000000

// Função Counting Sort
void counting_sort(int *a, int n, int e) {
    int *o = (int *)malloc(n * sizeof(int));
    int c[10] = {0};
    int i = 0;


    // Agora faz o processo de ordenação baseado na casa decimal
    for (; i < n; i++) {    
        c[(a[i] / e) % 10]++;
    }

    for (i = 1; i < 10; i++) {  
        c[i] += c[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        o[c[(a[i] / e) % 10] - 1] = a[i];
        c[(a[i] / e) % 10]--;
    }

    for (i = 0; i < n; i++) {
        a[i] = o[i];
    }

    free(o);
}


void radix_sort(int *a) {
    int n = 0;
    while (a[n] != -1) n++;     // Acha o tamanho do vetor

    if (n <= 1) return;     // Se for pequeno, retorna

    int m = a[0];
    int i = 1;
    for (; i < n; i++) {
        if (a[i] > m) m = a[i];     // Acha o maior elemento
    }

    int e = 1;
    while (m / e > 0) {     // Aumenta a casa decimal
        counting_sort(a, n, e);
        e *= 10;
    }
}


int main(){
    int a[tam];
    
    for (int i = tam - 1; i >= 0; i--) {
        a[i] = i; 
    }
    a[tam - 1] = -1; 

    radix_sort(a); 


    return 0;
}