#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main(){
    Produto *produtos = NULL;

    int tamanho = 0;
    int capacidade = 0;

    cadastrarProduto(&produtos, &tamanho, &capacidade);
    cadastrarProduto(&produtos, &tamanho, &capacidade);
    cadastrarProduto(&produtos, &tamanho, &capacidade);

    printf("\n===== PRODUTOS =====\n");

    listarProdutos(produtos, tamanho, 0);

    free(produtos);

    return 0;
}