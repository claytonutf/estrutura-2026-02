#include <stdio.h>

int main(void)
{
    int primeiro_valor = 5;
    int segundo_valor = 15;

    int *p1;
    int *p2;

    /* p1 recebe o endereco de primeiro_valor */
    p1 = &primeiro_valor;

    /* p2 recebe o endereco de segundo_valor */
    p2 = &segundo_valor;

    /* Altera primeiro_valor atraves de p1 */
    *p1 = 10;

    /* Copia o valor apontado por p1 para o local apontado por p2 */
    *p2 = *p1;

    /* p1 passa a apontar para o mesmo local que p2 */
    p1 = p2;

    /* Agora p1 e p2 apontam para segundo_valor */
    *p1 = 20;

    printf("primeiro_valor = %d\n", primeiro_valor);
    printf("segundo_valor  = %d\n", segundo_valor);

    return 0;
}