#ifndef PILHA_DIN_H
#define PILHA_DIN_H

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento *Pilha;

Pilha *cria_Pilha(void);
void libera_Pilha(Pilha *pi);

int acessa_topo_Pilha(const Pilha *pi, struct aluno *al);
int insere_Pilha(Pilha *pi, struct aluno al);
int remove_Pilha(Pilha *pi);

int tamanho_Pilha(const Pilha *pi);
int Pilha_vazia(const Pilha *pi);
int Pilha_cheia(const Pilha *pi);

void imprime_Pilha(const Pilha *pi);

#endif