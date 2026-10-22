#ifndef LISTADINENCAD_H
#define LISTADINENCAD_H

/*
 * Lista simplesmente encadeada de alunos.
 * Arquivo: ListDinEncad.h
 */

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Lista;

/* Criação e liberação da lista */
Lista* cria_lista(void);
void libera_lista(Lista* li);

/* Inserção */
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);

/* Remoção */
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);

/* Consultas */
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
int busca_lista_mat(Lista* li, int mat, struct aluno* al);
int busca_lista_pos(Lista* li, int pos, struct aluno* al);

void imprime_lista(Lista* li);

#endif /* LISTADINENCAD_H */
