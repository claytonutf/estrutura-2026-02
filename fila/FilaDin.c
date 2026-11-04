#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os protótipos

//definição do tipo Fila
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

//definição do nó descritor da fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

// Criando uma fila
Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

// Destruindo uma fila
void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

// Consultando a fila
int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

// Inserindo um elemento na fila
int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

// Removendo um elemento da fila
int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(no);
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    fi->qtd--;
    return 1;
}

// Tamanho da fila
int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

// Retornando se a fila está vazia
int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return -1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

// Retornando se a fila está cheia
int Fila_cheia(Fila* fi){
    (void)fi; // fila dinâmica nunca fica cheia
    return 0;
}

// Imprimindo a fila, do início ao fim
void imprime_Fila(Fila* fi){
    if(fi == NULL){
        printf("Fila nao criada.\n");
        return;
    }
    if(fi->inicio == NULL){
        printf("Fila vazia.\n");
        return;
    }
    Elem* no = fi->inicio;
    int pos = 1;
    printf("--- Fila (inicio -> final) ---\n");
    while(no != NULL){
        printf("%d) Matricula: %d | Nome: %s | Notas: %.2f %.2f %.2f\n",
               pos, no->dados.matricula, no->dados.nome,
               no->dados.n1, no->dados.n2, no->dados.n3);
        no = no->prox;
        pos++;
    }
}
