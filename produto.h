#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int id_produto;
    char nome[100];
    float preco;
    int quantidade;
} Produto;

void cadastrarProduto(Produto **produtos, int *tamanho, int *capacidade);

#endif