#include <stdio.h>

int main(void)
{
    int primeiro_valor;
    int segundo_valor;

    int *ponteiro;

    /* O ponteiro recebe o endereço de primeiro_valor */
    ponteiro = &primeiro_valor;

    /* Através do ponteiro, armazenamos 10 em primeiro_valor */
    *ponteiro = 10;

    /* Agora o ponteiro recebe o endereço de segundo_valor */
    ponteiro = &segundo_valor;

    /* Através do ponteiro, armazenamos 20 em segundo_valor */
    *ponteiro = 20;

    /* Exibindo os valores */
    printf("primeiro_valor = %d\n", primeiro_valor);
    printf("segundo_valor  = %d\n", segundo_valor);

    return 0;
}