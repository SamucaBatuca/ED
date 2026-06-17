#include <stdio.h>
#include <stdlib.h>
#define tam 1000000

int* counting_sort(int *a) {    // Recebe vetor original
    int n = 0;
    while (a[n] != -1) n++;

    if (n == 0) return NULL; // Se vazio, retorna null

    int m = a[0];  
    int i = 1;
    for (; i < n; i++) {
        if (a[i] > m) m = a[i];  // Pega o maior valor
    }

    int *c = (int *)calloc(m + 1, sizeof(int)); // Cria o vetor de ordenação
    for (i = 0; i < n; i++) {
        c[a[i]]++;
    }

    int *o = (int *)malloc((n + 1) * sizeof(int));  // Cria um retorno
    i = 0;
    int x = 0;
    for (; x <= m; x++) {       // Ordena
        while (c[x] > 0) {
            o[i++] = x;
            c[x]--;
        }
    }
    o[i] = -1;

    free(c);
    return o;
}

int main() {
    int a[tam];
   
    for (int i = tam - 1; i >= 0; i--) {
        a[i] = i; 
    }
    a[tam - 1] = -1; 

    //Cria o vetor ordenado
    int *sorted = counting_sort(a);   
    


    return 0;
}
