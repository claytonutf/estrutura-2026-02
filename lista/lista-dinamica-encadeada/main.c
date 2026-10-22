#include <stdio.h>
#include <stdlib.h>
#include "ListDinEncad.h"


/*
Para compilar usando o terminal: 

    gcc -Wall -Wextra -std=c11 main.c ListDinEncad.c -o programa
*/

int main(void) {

    /* Cabeça da lista */
    Lista* li = cria_lista();

    if (li == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    /* Utilize as funções da lista aqui. */
    struct aluno a1 = {1, "Bianca", 8.5, 9.0, 7.5};
    struct aluno a2 = {2, "Andre", 7.0, 8.5, 9.0};
    struct aluno a3 = {3, "Ana", 9.0, 8.0, 9.5};
    struct aluno a4 = {4, "Ricardo", 8.0, 7.5, 8.5};

    insere_lista_final(li, a1);
    insere_lista_final(li, a2);
    insere_lista_final(li, a3);
    insere_lista_final(li, a4);

    printf("Alunos inseridos no final da lista!\n");
    printf("Quantidade de alunos: %d\n", tamanho_lista(li));

    
    imprime_lista(li);

    libera_lista(li);

    return 0;
}