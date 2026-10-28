#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDin.h"

static void limpa_linha(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

static void mostra_aluno(struct aluno al)
{
    printf(
        "Matricula: %d\n"
        "Nome: %s\n"
        "Notas: %.2f %.2f %.2f\n",
        al.matricula,
        al.nome,
        al.n1,
        al.n2,
        al.n3
    );
}

static int le_aluno(struct aluno *al)
{
    printf("Matricula: ");

    if (scanf("%d", &al->matricula) != 1) {
        limpa_linha();
        return 0;
    }

    limpa_linha();

    printf("Nome: ");

    if (fgets(al->nome, sizeof(al->nome), stdin) == NULL)
        return 0;

    /*
     * Remove o '\n' armazenado pelo fgets().
     */
    size_t tamanho = strlen(al->nome);

    if (tamanho > 0 && al->nome[tamanho - 1] == '\n') {
        al->nome[tamanho - 1] = '\0';
    } else {
        /*
         * Descarta o restante da linha caso o nome
         * ultrapasse o tamanho do vetor.
         */
        limpa_linha();
    }

    printf("Notas (n1 n2 n3): ");

    if (scanf("%f %f %f", &al->n1, &al->n2, &al->n3) != 3) {
        limpa_linha();
        return 0;
    }

    limpa_linha();

    return 1;
}

int main(void)
{
    Pilha *pi = cria_Pilha();

    if (pi == NULL) {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }

    /*
     * Registros iniciais solicitados.
     */
    struct aluno a1 = {1, "Bianca", 8.5, 9.0, 7.5};
    struct aluno a2 = {2, "Andre", 7.0, 8.5, 9.0};
    struct aluno a3 = {3, "Ana", 9.0, 8.0, 9.5};
    struct aluno a4 = {4, "Ricardo", 8.0, 7.5, 8.5};

    /*
     * Insere os quatro alunos na pilha.
     */
    if (!insere_Pilha(pi, a1) ||
        !insere_Pilha(pi, a2) ||
        !insere_Pilha(pi, a3) ||
        !insere_Pilha(pi, a4)) {

        printf("Erro ao inserir os alunos iniciais.\n");

        libera_Pilha(pi);
        return 1;
    }

    printf("Quatro alunos foram inseridos inicialmente.\n");

    int op = -1;
    struct aluno al;

    do {
        printf(
            "\n=== PILHA DE ALUNOS ===\n"
            "1 - Inserir\n"
            "2 - Remover\n"
            "3 - Consultar topo\n"
            "4 - Tamanho\n"
            "5 - Pilha vazia?\n"
            "6 - Pilha cheia?\n"
            "7 - Imprimir pilha\n"
            "0 - Sair\n"
            "Opcao: "
        );

        if (scanf("%d", &op) != 1) {
            limpa_linha();
            printf("Opcao invalida.\n");
            op = -1;
            continue;
        }

        limpa_linha();

        switch (op) {

        case 1:
            if (le_aluno(&al) && insere_Pilha(pi, al)) {
                printf("Aluno inserido.\n");
            } else {
                printf("Falha ao inserir aluno.\n");
            }
            break;

        case 2:
            if (remove_Pilha(pi)) {
                printf("Elemento removido.\n");
            } else {
                printf("Pilha vazia, nada removido.\n");
            }
            break;

        case 3:
            if (acessa_topo_Pilha(pi, &al)) {
                mostra_aluno(al);
            } else {
                printf("Pilha vazia.\n");
            }
            break;

        case 4:
            printf("Tamanho: %d\n", tamanho_Pilha(pi));
            break;

        case 5:
            if (Pilha_vazia(pi)) {
                printf("Pilha vazia.\n");
            } else {
                printf("Pilha NAO esta vazia.\n");
            }
            break;

        case 6:
            if (Pilha_cheia(pi)) {
                printf("Pilha cheia.\n");
            } else {
                printf("Pilha NAO esta cheia.\n");
            }
            break;

        case 7:
            imprime_Pilha(pi);
            break;

        case 0:
            printf("Encerrando o programa.\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }

    } while (op != 0);

    libera_Pilha(pi);

    return 0;
}