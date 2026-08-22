#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main(){
    Produto *produtos = NULL;

    int tamanho = 0;
    int capacidade = 0;
    int idParaDeletar, n;

    cadastrarProduto(&produtos, &tamanho, &capacidade);
    cadastrarProduto(&produtos, &tamanho, &capacidade);
    cadastrarProduto(&produtos, &tamanho, &capacidade);

    printf("\n===== PRODUTOS =====\n");
    listarProdutos(produtos, tamanho, 0);


    printf("Deseja deletar algum produto?\n[1] para sim | [0] para nao\n");
    scanf("%d", &n);

    if (n == 1) {
        printf("Digite o ID do produto que deseja deletar: ");
        scanf("%d", &idParaDeletar);

        int resultado = deletarProduto(produtos, &tamanho, idParaDeletar);

        if (resultado == 1) {
            printf("Produto deletado com sucesso!\n");
        }   else    {
            printf("Produto nao encontrado!\n");
        }

        printf("\n===== PRODUTOS APOS A REMOCAO =====\n");

        listarProdutos(produtos, tamanho, 0);
    }

    free(produtos);

    return 0;
}