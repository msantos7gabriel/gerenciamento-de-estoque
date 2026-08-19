#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int proximoId = 1;

void cadastrarProduto(Produto **produtos, int *tamanho, int *capacidade) {

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
}