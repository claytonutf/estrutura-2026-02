/*
 * Implementação de uma lista simplesmente encadeada de alunos.
 * Arquivo: ListDinEncad.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "ListDinEncad.h"

/* Definição interna de cada nó da lista */
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

/*
 * Cria uma lista vazia.
 * Retorna NULL se não houver memória disponível.
 */
Lista* cria_lista(void) {
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL) {
        *li = NULL;
    }

    return li;
}

/*
 * Libera todos os nós e, por fim, a estrutura que guarda
 * o ponteiro para o início da lista.
 */
void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;

        while (*li != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }

        free(li);
    }
}

/*
 * Retorna a quantidade de elementos da lista.
 * Se o ponteiro da lista for inválido, retorna 0.
 */
int tamanho_lista(Lista* li) {
    if (li == NULL) {
        return 0;
    }

    int cont = 0;
    Elem* no = *li;

    while (no != NULL) {
        cont++;
        no = no->prox;
    }

    return cont;
}

/*
 * Uma lista encadeada dinâmica não possui capacidade máxima
 * predefinida. Retorna 0 (não cheia).
 */
int lista_cheia(Lista* li) {
    /* Implementar com capacidade máxima definida na constante MAX*/
    (void) li;
    return 0;
}

/*
 * Retorna 1 se a lista estiver vazia ou se o ponteiro da lista
 * for inválido; retorna 0 caso exista ao menos um elemento.
 */
int lista_vazia(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 1;
    }

    return 0;
}

/* Insere um aluno no início da lista */
int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL) {
        return 0;
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL) {
        return 0;
    }

    no->dados = al;
    no->prox = *li;
    *li = no;

    return 1;
}

/* Insere um aluno no final da lista */
int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL) {
        return 0;
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL) {
        return 0;
    }

    no->dados = al;
    no->prox = NULL;

    if (*li == NULL) {
        *li = no;
    } else {
        Elem* aux = *li;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = no;
    }

    return 1;
}

/* Insere um aluno mantendo a lista em ordem crescente de matrícula */
int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL) {
        return 0;
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL) {
        return 0;
    }

    no->dados = al;

    if (*li == NULL) { /* lista vazia: insere início */
        no->prox = NULL;
        *li = no;
        return 1;
    } else {
        Elem* ant = NULL;
        Elem* atual = *li;

        while (atual != NULL &&
               atual->dados.matricula < al.matricula) {
            ant = atual;
            atual = atual->prox;
        }

        if (atual == *li) { /* insere início */
            no->prox = *li;
            *li = no;
        } else {
            no->prox = atual;
            ant->prox = no;
        }

        return 1;
    }
}

/* Remove um elemento do início da lista */
int remove_lista_inicio(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0;
    }

    Elem* no = *li;
    *li = no->prox;

    free(no);

    return 1;
}

/* Remove um elemento do final da lista */
int remove_lista_final(Lista* li) {
    if (li == NULL || *li == NULL) {
        return 0;
    }

    Elem* ant = NULL;
    Elem* no = *li;

    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }

    if (ant == NULL) { /* havia apenas um elemento */
        *li = NULL;
    } else {
        ant->prox = NULL;
    }

    free(no);

    return 1;
}

/* Remove um elemento específico da lista pela matrícula */
int remove_lista(Lista* li, int mat) {
    if (li == NULL || *li == NULL) {
        return 0;
    }

    Elem* ant = NULL;
    Elem* no = *li;

    while (no != NULL && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }

    if (no == NULL) { /* elemento não encontrado */
        return 0;
    }

    if (ant == NULL) { /* remover o primeiro elemento */
        *li = no->prox;
    } else {
        ant->prox = no->prox;
    }

    free(no);

    return 1;
}

/* Busca um elemento pela posição (a primeira posição é 1) */
int busca_lista_pos(Lista* li, int pos, struct aluno* al) {
    if (li == NULL || pos <= 0 || al == NULL) {
        return 0;
    }

    Elem* no = *li;
    int i = 1;

    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }

    if (no == NULL) {
        return 0;
    }

    *al = no->dados;
    return 1;
}

/* Busca um elemento pela matrícula */
int busca_lista_mat(Lista* li, int mat, struct aluno* al) {
    if (li == NULL || al == NULL) {
        return 0;
    }

    Elem* no = *li;

    while (no != NULL && no->dados.matricula != mat) {
        no = no->prox;
    }

    if (no == NULL) {
        return 0;
    }

    *al = no->dados;
    return 1;
}

/*
 * Percorre e imprime todos os alunos da lista,
 * desde o primeiro até o último elemento.
 */
void imprime_lista(Lista* li) {
    if (li == NULL || *li == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Elem* no = *li;

    while (no != NULL) {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.2f, %.2f, %.2f\n",
               no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------\n");

        no = no->prox;
    }
}