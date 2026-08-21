#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int proximoId = 1;

int cadastrarProduto(Produto **produtos, int *tamanho, int *capacidade) {

    if (*tamanho == *capacidade) {

        if (*capacidade == 0) *capacidade = 3;
        else *capacidade = *capacidade * 2; 

        Produto *temp = realloc(*produtos, *capacidade * sizeof(Produto));

        if (temp == NULL) {
            printf("Erro ao alocar memoria!\n");
            return 500;
        }

        *produtos = temp;
    }


    (*produtos)[*tamanho].id_produto = proximoId;
    proximoId++;

    printf("Digite o nome: ");
    scanf("%99s", (*produtos)[*tamanho].nome);

    printf("Digite o preco: ");
    scanf("%f", &(*produtos)[*tamanho].preco);

    printf("Digite a quantidade: ");
    scanf("%d", &(*produtos)[*tamanho].quantidade);

    (*tamanho)++;

    printf("Produto cadastrado com sucesso!\n");
    printf("\n");

    return 0;
}

void listarProdutos(Produto *produtos, int tamanho, int indice){
    if (indice == tamanho) return;

    printf("ID: %d\n", produtos[indice].id_produto);
    printf("Nome: %s\n", produtos[indice].nome);
    printf("Preco: %.2f\n", produtos[indice].preco);
    printf("Quantidade: %d\n", produtos[indice].quantidade);
    printf("\n");

    listarProdutos(produtos, tamanho, indice + 1);
}