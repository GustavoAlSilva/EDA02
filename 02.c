#include <stdio.h>
/*
Dado um vetor de n�meros inteiros v, retorne
um novo vetor de forma que cada elemento no
�ndice i seja o produto de todos os n�meros
na matriz original, com exce��o de i.
Exemplo 1: dado v = [1,2,3,4,5], a sa�da
esperada � [120,60,40,30,24]
Exemplo 2: dado v = [3,2,1], a sa�da esperada
� [2,3,6]
*/

int main() {
    int n = 5;
    int v[] = {1,2,3,4,5};
    int r[n];
    int i;

    printf("[ ");

    int produto = 1;

    for (i = 0; i < n; i++) {
        produto *= v[i];
    }

    for (i = 0; i < n; i++) {
        r[i] = produto / v[i];
        printf("%d ", r[i]);
    }

    printf("]\n");
}
