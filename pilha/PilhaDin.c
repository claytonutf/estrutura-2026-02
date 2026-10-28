#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Pilha *cria_Pilha(void)
{
    Pilha *pi = malloc(sizeof *pi);

    if (pi != NULL)
        *pi = NULL;

    return pi;
}

void libera_Pilha(Pilha *pi)
{
    if (pi == NULL)
        return;

    Elem *no = *pi;

    while (no != NULL) {
        Elem *proximo = no->prox;
        free(no);
        no = proximo;
    }

    free(pi);
}

int tamanho_Pilha(const Pilha *pi)
{
    if (pi == NULL)
        return 0;

    int cont = 0;
    const Elem *no = *pi;

    while (no != NULL) {
        cont++;
        no = no->prox;
    }

    return cont;
}

int Pilha_cheia(const Pilha *pi)
{
    /*
     * A pilha dinâmica não possui capacidade máxima fixa.
     * A inserção pode falhar caso não haja memória disponível.
     */
    (void)pi;
    return 0;
}

int Pilha_vazia(const Pilha *pi)
{
    return pi == NULL || *pi == NULL;
}

int insere_Pilha(Pilha *pi, struct aluno al)
{
    if (pi == NULL)
        return 0;

    Elem *no = malloc(sizeof *no);

    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = *pi;
    *pi = no;

    return 1;
}

int remove_Pilha(Pilha *pi)
{
    if (pi == NULL || *pi == NULL)
        return 0;

    Elem *no = *pi;

    *pi = no->prox;

    free(no);

    return 1;
}

int acessa_topo_Pilha(const Pilha *pi, struct aluno *al)
{
    if (pi == NULL || *pi == NULL || al == NULL)
        return 0;

    *al = (*pi)->dados;

    return 1;
}

void imprime_Pilha(const Pilha *pi)
{
    if (Pilha_vazia(pi)) {
        printf("Pilha vazia.\n");
        return;
    }

    const Elem *no = *pi;

    printf("\n=== ALUNOS NA PILHA ===\n");

    while (no != NULL) {
        printf(
            "Matricula: %d\n"
            "Nome: %s\n"
            "Notas: %.2f %.2f %.2f\n"
            "-------------------------\n",
            no->dados.matricula,
            no->dados.nome,
            no->dados.n1,
            no->dados.n2,
            no->dados.n3
        );

        no = no->prox;
    }
}