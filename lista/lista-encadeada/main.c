#include <stdio.h>

#include "lista.h"

/*
    Compilar: gcc -Wall -Wextra -std=c11 main.c lista.c -o lista
*/


int main(void)
{
    No *lista;

    /* Cria uma lista vazia */
    lista = lista_criar();

    /* Insere elementos */
    lista_inserir(&lista, 10);
    lista_inserir(&lista, 20);
    lista_inserir(&lista, 30);

    /* Exibe a lista */
    printf("Lista: ");
    lista_listar(lista);

    /* Libera toda a memória */
    lista_destruir(&lista);

    return 0;
}