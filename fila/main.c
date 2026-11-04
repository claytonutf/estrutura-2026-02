#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDin.h"

static void limpa_linha(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

static void mostra_aluno(struct aluno al){
    printf("Matricula: %d\nNome: %s\nNotas: %.2f %.2f %.2f\n",
           al.matricula, al.nome, al.n1, al.n2, al.n3);
}

static int le_aluno(struct aluno *al){
    printf("Matricula: ");
    if(scanf("%d", &al->matricula) != 1) return 0;
    limpa_linha();
    printf("Nome: ");
    if(fgets(al->nome, sizeof(al->nome), stdin) == NULL) return 0;
    al->nome[strcspn(al->nome, "\n")] = '\0';
    printf("Notas (n1 n2 n3): ");
    if(scanf("%f %f %f", &al->n1, &al->n2, &al->n3) != 3) return 0;
    limpa_linha();
    return 1;
}

int main(void){
    Fila *fi = cria_Fila();
    if(fi == NULL){
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    int op;
    struct aluno al;
    do{
        printf("\n=== FILA DE ALUNOS ===\n"
               "1 - Inserir\n"
               "2 - Remover\n"
               "3 - Consultar inicio\n"
               "4 - Tamanho\n"
               "5 - Fila vazia?\n"
               "6 - Fila cheia?\n"
               "7 - Imprimir fila\n"
               "0 - Sair\n"
               "Opcao: ");
        if(scanf("%d", &op) != 1) break;
        limpa_linha();

        switch(op){
        case 1:
            if(le_aluno(&al) && insere_Fila(fi, al))
                printf("Aluno inserido.\n");
            else
                printf("Falha ao inserir.\n");
            break;
        case 2:
            if(remove_Fila(fi)) printf("Elemento removido.\n");
            else printf("Fila vazia, nada removido.\n");
            break;
        case 3:
            if(consulta_Fila(fi, &al)) mostra_aluno(al);
            else printf("Fila vazia.\n");
            break;
        case 4:
            printf("Tamanho: %d\n", tamanho_Fila(fi));
            break;
        case 5:
            printf(Fila_vazia(fi) ? "Fila vazia.\n" : "Fila NAO esta vazia.\n");
            break;
        case 6:
            printf(Fila_cheia(fi) ? "Fila cheia.\n" : "Fila NAO esta cheia.\n");
            break;
        case 7:
            imprime_Fila(fi);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida.\n");
        }
    }while(op != 0);

    libera_Fila(fi);
    return 0;
}
