#ifndef LISTA_H
#define LISTA_H

/* Estrutura que representa um elemento da lista */
typedef struct No {
    int valor;
    struct No *proximo;
} No;

/* Cria uma lista vazia */
No *lista_criar(void);

/* Insere um valor no início da lista */
void lista_inserir(No **lista, int valor);

/* Exibe todos os elementos da lista */
void lista_listar(No *lista);

/* Libera toda a memória da lista */
void lista_destruir(No **lista);

#endif