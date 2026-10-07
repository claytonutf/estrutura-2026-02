#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/*
 * Cria uma lista vazia.
 *
 * NULL representa uma lista sem elementos.
 */
No *lista_criar(void)
{
    return NULL;
}

/*
 * Insere um novo elemento no início da lista.
 */
void lista_inserir(No **lista, int valor)
{
    /* Cria um novo nó na memória */
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return;
    }

    /* Armazena o valor */
    novo->valor = valor;

    /*
     * O próximo elemento será o atual primeiro
     * elemento da lista.
     */
    novo->proximo = *lista;

    /*
     * O novo elemento passa a ser o primeiro
     * elemento da lista.
     */
    *lista = novo;
}

/*
 * Percorre e exibe todos os elementos.
 */
void lista_listar(No *lista)
{
    No *atual = lista;

    while (atual != NULL) {
        printf("%d -> ", atual->valor);

        atual = atual->proximo;
    }

    printf("NULL\n");
}

/*
 * Libera todos os nós da lista.
 */
void lista_destruir(No **lista)
{
    No *atual = *lista;
    No *proximo;

    while (atual != NULL) {

        /*
         * Guarda o endereço do próximo nó
         * antes de liberar o atual.
         */
        proximo = atual->proximo;

        free(atual);

        atual = proximo;
    }

    /*
     * Depois de destruir a lista, o ponteiro
     * volta a representar uma lista vazia.
     */
    *lista = NULL;
}