#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

/* Executa o menu de gerenciamento e coordena as operacoes do estoque. */
int main()
{

    // O vetor começa vazio e sera expandido conforme novos produtos sao cadastrados.
    Produto *produtos = NULL;

    int tamanho = 0;
    int opcao;
    int idParaDeletar;
    int idParaBuscar;

    do
    {

        // Exibe as operacoes disponiveis para o usuario.
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

        if (scanf("%d", &opcao) != 1)
        {
            // Limpa a entrada invalida para permitir uma nova escolha.
            printf("Entrada invalida! Digite apenas numeros.\n");

            while (getchar() != '\n')
                ;

            opcao = -1;
        }

        switch (opcao)
        {

        case 1:
        {
            // Solicita e cadastra um novo produto no estoque.
            int resultado = cadastrarProduto(&produtos, &tamanho);

            if (resultado == 500)
            {
                printf("Nao foi possivel cadastrar o produto.\n");
            }
            break;
        }

        case 2:

            // Nao tenta remover produtos quando o estoque esta vazio.
            if (tamanho == 0)
            {
                printf("Estoque vazio! Nenhum produto para remover.\n");
                break;
            }

            printf("Digite o ID do produto que deseja deletar: ");
            scanf("%d", &idParaDeletar);

            int resultado1 = deletarProduto(produtos, &tamanho, idParaDeletar);

            // Informa ao usuario se a remocao foi realizada.
            if (resultado1 == 1)
            {
                printf("Produto deletado com sucesso!\n");
            }
            else
            {
                printf("Produto nao encontrado!\n");
            }
            break;

        case 3:

            // Mostra todos os produtos ou informa que nao existem itens cadastrados.
            if (tamanho == 0)
            {
                printf("Estoque vazio!\n");
            }
            else
            {
                printf("\n========== PRODUTOS ==========\n");
                listarProdutos(produtos, tamanho, 0);
            }
            break;

        case 4:

            // A busca so e executada quando ha produtos no vetor.
            if (tamanho == 0)
            {
                printf("Estoque vazio! Nenhum produto para buscar.\n");
                break;
            }

            printf("Digite o ID do produto que deseja buscar: ");
            scanf("%d", &idParaBuscar);

            int indiceEncontrado = buscarProdutoPorId(produtos, 0, tamanho - 1, idParaBuscar);

            // Exibe o produto encontrado ou uma mensagem de ausencia.
            if (indiceEncontrado == -1)
            {
                printf("Produto nao encontrado!\n");
            }
            else
            {
                printf("\n========== PRODUTO ENCONTRADO ==========\n");
                printf("ID: %d\n", produtos[indiceEncontrado].id_produto);
                printf("Nome: %s\n", produtos[indiceEncontrado].nome);
                printf("Preco: %.2f\n", produtos[indiceEncontrado].preco);
                printf("Quantidade: %d\n", produtos[indiceEncontrado].quantidade);
            }
            break;

        case 5:
            // Ordena e exibe uma copia dos produtos por preco.
            ordenarProdutosPreco(&produtos, tamanho);
            /*
             * Funcao de ordenar por preco sera adicionada.
             */
            break;

        case 6:
            // Calcula e exibe o valor total do estoque.
            float resultado = somaProduto(&produtos, &tamanho);
            if (resultado != -1)
            {
                printf("Valor total dos itens do estoque: %.2fR$\n\n", resultado);
            }
            break;

        case 0:

            // Finaliza o laco principal do programa.
            printf("Encerrando o programa...\n");

            break;

        default:

            // Trata opcoes que nao existem no menu.
            printf("Opcao invalida! Escolha uma opcao do menu.\n");

            break;
        }
    } while (opcao != 0);

    // Libera a memoria usada pelo vetor antes de encerrar.
    free(produtos);

    return 0;
}