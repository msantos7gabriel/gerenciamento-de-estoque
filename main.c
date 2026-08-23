#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main(){
    Produto *produtos = NULL;

    int tamanho = 0;
    int capacidade = 0;
    int idParaDeletar, n1, idParaBuscar, n2;
    

    cadastrarProduto(&produtos, &tamanho, &capacidade);
    cadastrarProduto(&produtos, &tamanho, &capacidade);
    cadastrarProduto(&produtos, &tamanho, &capacidade);

    printf("\n===== PRODUTOS =====\n");
    listarProdutos(produtos, tamanho, 0);


    printf("Deseja deletar algum produto?\n[1] para sim | [0] para nao\n");
    scanf("%d", &n1);

    if (n1 == 1) {
        printf("Digite o ID do produto que deseja deletar: ");
        scanf("%d", &idParaDeletar);

        int resultado1 = deletarProduto(produtos, &tamanho, idParaDeletar);

        if (resultado1 == 1) {
            printf("Produto deletado com sucesso!\n");
        }   else    {
            printf("Produto nao encontrado!\n");
        }

        printf("\n===== PRODUTOS APOS A REMOCAO =====\n");

        listarProdutos(produtos, tamanho, 0);
    }

    printf("Deseja buscar algum produto?\n[1] para sim | [0] para nao\n");
    scanf("%d", &n2);

    if (n2 == 1) {
        printf("Digite o ID do produto que deseja buscar: ");
        scanf("%d", &idParaBuscar);

        int indiceEncontrado = buscarProdutoPorId(produtos, 0, tamanho - 1, idParaBuscar);

        if(indiceEncontrado == -1) {
            printf("Produto nao encontrado!\n");
        } else {
            printf("\n");
            printf("ID: %d\n", produtos[indiceEncontrado].id_produto);
            printf("Nome: %s\n", produtos[indiceEncontrado].nome);
            printf("Preco: %.2f\n", produtos[indiceEncontrado].preco);
            printf("Quantidade: %d\n", produtos[indiceEncontrado].quantidade);
            printf("\n");
        }
        
    }

    free(produtos);

    return 0;
}