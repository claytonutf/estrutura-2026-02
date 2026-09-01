#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUTOS 100

// Estrutura que representa um produto
struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
    bool ativo;
};

// ---------------------------------------------------------
// CADASTRAR PRODUTO
// ---------------------------------------------------------

void cadastrarProduto(struct Produto *produto, int codigo) {

    produto->codigo = codigo;

    printf("\n========== CADASTRO DE PRODUTO ==========\n");

    printf("Nome: ");
    scanf(" %49[^\n]", produto->nome);

    printf("Preco: R$ ");
    scanf("%f", &produto->preco);

    printf("Quantidade inicial: ");
    scanf("%d", &produto->quantidade);

    produto->ativo = true;

    printf("\nProduto cadastrado com sucesso!\n");
    printf("Codigo: %d\n", produto->codigo);
}


// ---------------------------------------------------------
// LISTAR PRODUTOS
// ---------------------------------------------------------

void listarProdutos(struct Produto produtos[], int total) {

    int i;

    printf("\n============== PRODUTOS ==============\n");

    if (total == 0) {

        printf("Nenhum produto cadastrado.\n");

        return;
    }

    for (i = 0; i < total; i++) {

        if (produtos[i].ativo) {

            printf("\nCodigo: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preco: R$ %.2f\n", produtos[i].preco);
            printf("Quantidade: %d\n", produtos[i].quantidade);

            if (produtos[i].quantidade <= 5) {
                printf("Situacao: ESTOQUE BAIXO\n");
            } else {
                printf("Situacao: ESTOQUE NORMAL\n");
            }
        }
    }
}


// ---------------------------------------------------------
// BUSCAR PRODUTO
// ---------------------------------------------------------

int buscarProduto(
    struct Produto produtos[],
    int total,
    int codigo
) {

    int i;

    for (i = 0; i < total; i++) {

        if (
            produtos[i].codigo == codigo &&
            produtos[i].ativo == true
        ) {

            return i;
        }
    }

    return -1;
}


// ---------------------------------------------------------
// ENTRADA DE ESTOQUE
// ---------------------------------------------------------

void entradaEstoque(struct Produto *produto) {

    int quantidade;

    printf("\nProduto: %s\n", produto->nome);

    printf("Quantidade a adicionar: ");
    scanf("%d", &quantidade);

    if (quantidade > 0) {

        produto->quantidade += quantidade;

        printf(
            "\nEstoque atualizado!\n"
            "Nova quantidade: %d\n",
            produto->quantidade
        );

    } else {

        printf("\nQuantidade invalida.\n");
    }
}


// ---------------------------------------------------------
// SAIDA DE ESTOQUE
// ---------------------------------------------------------

void saidaEstoque(struct Produto *produto) {

    int quantidade;

    printf("\nProduto: %s\n", produto->nome);
    printf("Estoque atual: %d\n", produto->quantidade);

    printf("Quantidade vendida: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {

        printf("\nQuantidade invalida.\n");

    } else if (quantidade > produto->quantidade) {

        printf("\nEstoque insuficiente!\n");

    } else {

        produto->quantidade -= quantidade;

        printf(
            "\nVenda registrada!\n"
            "Estoque restante: %d\n",
            produto->quantidade
        );
    }
}


// ---------------------------------------------------------
// CONSULTAR PRODUTO
// ---------------------------------------------------------

void consultarProduto(
    struct Produto produtos[],
    int total
) {

    int codigo;
    int indice;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    indice = buscarProduto(
        produtos,
        total,
        codigo
    );

    if (indice != -1) {

        printf("\n========== PRODUTO ==========\n");
        printf("Codigo: %d\n", produtos[indice].codigo);
        printf("Nome: %s\n", produtos[indice].nome);
        printf("Preco: R$ %.2f\n", produtos[indice].preco);
        printf("Quantidade: %d\n", produtos[indice].quantidade);

        if (produtos[indice].ativo) {
            printf("Ativo: SIM\n");
        } else {
            printf("Ativo: NAO\n");
        }

    } else {

        printf("\nProduto nao encontrado.\n");
    }
}


// ---------------------------------------------------------
// CALCULAR VALOR TOTAL DO ESTOQUE
// ---------------------------------------------------------

float calcularValorEstoque(
    struct Produto produtos[],
    int total
) {

    int i;
    float totalEstoque = 0.0;

    for (i = 0; i < total; i++) {

        if (produtos[i].ativo) {

            totalEstoque +=
                produtos[i].preco *
                produtos[i].quantidade;
        }
    }

    return totalEstoque;
}


// ---------------------------------------------------------
// MOSTRAR ESTOQUE BAIXO
// ---------------------------------------------------------

void mostrarEstoqueBaixo(
    struct Produto produtos[],
    int total
) {

    int i;
    bool encontrou = false;

    printf("\n======= ESTOQUE BAIXO =======\n");

    for (i = 0; i < total; i++) {

        if (
            produtos[i].ativo &&
            produtos[i].quantidade <= 5
        ) {

            printf(
                "Codigo: %d | %s | Quantidade: %d\n",
                produtos[i].codigo,
                produtos[i].nome,
                produtos[i].quantidade
            );

            encontrou = true;
        }
    }

    if (!encontrou) {

        printf("Nenhum produto com estoque baixo.\n");
    }
}



// ---------------------------------------------------------
// FUNÇÃO PRINCIPAL
// ---------------------------------------------------------

int main() {

    // Array que armazenará os produtos
    struct Produto produtos[MAX_PRODUTOS];

    int totalProdutos = 0;
    int opcao;

    do {

        printf("\n========================================\n");
        printf("       CONTROLE DE ESTOQUE\n");
        printf("          SUPERMERCADO\n");
        printf("========================================\n");

        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Consultar produto\n");
        printf("4 - Entrada de estoque\n");
        printf("5 - Saida de estoque\n");
        printf("6 - Mostrar produtos com estoque baixo\n");
        printf("7 - Valor total do estoque\n");
        printf("0 - Sair\n");

        printf("----------------------------------------\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                if (totalProdutos < MAX_PRODUTOS) {

                    cadastrarProduto(
                        &produtos[totalProdutos],
                        totalProdutos + 1
                    );

                    totalProdutos++;

                } else {

                    printf("\nEstoque cheio! Nao e possivel cadastrar mais produtos.\n");
                }

                break;


            case 2:

                listarProdutos(produtos, totalProdutos);

                break;


            case 3:

                consultarProduto(produtos, totalProdutos);

                break;


            case 4: {

                int codigo;
                int indice;

                printf("\nDigite o codigo do produto: ");
                scanf("%d", &codigo);

                indice = buscarProduto(
                    produtos,
                    totalProdutos,
                    codigo
                );

                if (indice != -1) {

                    entradaEstoque(&produtos[indice]);

                } else {

                    printf("\nProduto nao encontrado.\n");
                }

                break;
            }


            case 5: {

                int codigo;
                int indice;

                printf("\nDigite o codigo do produto: ");
                scanf("%d", &codigo);

                indice = buscarProduto(
                    produtos,
                    totalProdutos,
                    codigo
                );

                if (indice != -1) {

                    saidaEstoque(&produtos[indice]);

                } else {

                    printf("\nProduto nao encontrado.\n");
                }

                break;
            }


            case 6:

                mostrarEstoqueBaixo(produtos, totalProdutos);

                break;


            case 7: {

                float valor;

                valor = calcularValorEstoque(
                    produtos,
                    totalProdutos
                );

                printf("\nValor total do estoque: R$ %.2f\n", valor);

                break;
            }


            case 0:

                printf("\nSistema encerrado.\n");

                break;


            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);


    return 0;
}