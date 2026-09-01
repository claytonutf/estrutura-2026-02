#include <stdio.h>

int main(void)
{
    int numeros[5];
    int *p;

    /* p aponta para o primeiro elemento do vetor */
    p = numeros;

    *p = 10;

    /* Avanca para o proximo elemento */
    p++;
    *p = 20;

    /* p aponta para o terceiro elemento */
    p = &numeros[2];
    *p = 30;

    /* p aponta para o quarto elemento */
    p = numeros + 3;
    *p = 40;

    /* p aponta novamente para o primeiro elemento */
    p = numeros;

    /* Acessa o quinto elemento atraves do ponteiro */
    *(p + 4) = 50;

    /* Exibe os elementos do vetor */
    for (int n = 0; n < 5; n++)
    {
        printf("%d, ", numeros[n]);
    }

    printf("\n");

    return 0;
}