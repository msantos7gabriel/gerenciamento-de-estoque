#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main() {

    Produto *produtos = NULL;

    int tamanho = 0;
    int capacidade = 0;

    int opcao;
    int idParaDeletar;
    int idParaBuscar;

    do {

        printf("\n====================================\n");
        printf("       GERENCIAMENTO DE ESTOQUE\n");
        printf("====================================\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Remover produto\n");
        printf("3 - Listar produtos\n");
        printf("4 - Buscar produto por ID\n");
        printf("5 - Ordenar produtos por preco\n");
        printf("6 - Calcular valor total do estoque\n");
        printf("0 - Sair\n");
        printf("====================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");

            while (getchar() != '\n');

            opcao = -1;
        }

        switch (opcao) {

            case 1: {
                int resultado = cadastrarProduto( &produtos, &tamanho, &capacidade );

                if (resultado == 500) { printf("Nao foi possivel cadastrar o produto.\n"); }
                break;
            }

            case 2:

                if (tamanho == 0) {
                    printf("Estoque vazio! Nenhum produto para remover.\n");
                    break;
                }

                printf("Digite o ID do produto que deseja deletar: ");
                scanf("%d", &idParaDeletar);

                int resultado1 = deletarProduto(produtos, &tamanho, idParaDeletar);

                if (resultado1 == 1) { printf("Produto deletado com sucesso!\n");} 
                else { printf("Produto nao encontrado!\n"); }
                break;

            case 3:

                if (tamanho == 0) { printf("Estoque vazio!\n"); } 
                else {
                    printf("\n========== PRODUTOS ==========\n");
                    listarProdutos(produtos, tamanho, 0);
                }
                break;

            case 4:

                if (tamanho == 0) {
                    printf("Estoque vazio! Nenhum produto para buscar.\n");
                    break;
                }

                printf("Digite o ID do produto que deseja buscar: ");
                scanf("%d", &idParaBuscar);

                int indiceEncontrado = buscarProdutoPorId(produtos, 0,tamanho - 1,idParaBuscar);

                if (indiceEncontrado == -1) { printf("Produto nao encontrado!\n"); } 
                else {
                    printf("\n========== PRODUTO ENCONTRADO ==========\n");
                    printf("ID: %d\n", produtos[indiceEncontrado].id_produto);
                    printf("Nome: %s\n", produtos[indiceEncontrado].nome);
                    printf("Preco: %.2f\n", produtos[indiceEncontrado].preco);
                    printf("Quantidade: %d\n", produtos[indiceEncontrado].quantidade);
                }
                break;

            case 5:

                /*
                 * Funcao de ordenar por preco sera adicionada.
                 */
                break;

            case 6:

                /*
                 * Funcao de calcular o valor total do estoque sera adicionada.
                 */
                break;

            case 0:

                printf("Encerrando o programa...\n");

                break;

            default:

                printf("Opcao invalida! Escolha uma opcao do menu.\n");

                break;
        }

    } while (opcao != 0);

    free(produtos);

    return 0;
}