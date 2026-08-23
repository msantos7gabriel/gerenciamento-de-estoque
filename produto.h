#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct
{
    int id_produto;
    char nome[100];
    float preco;
    int quantidade;
} Produto;

int cadastrarProduto(Produto **produtos, int *tamanho, int *capacidade);
void listarProdutos(Produto *Produtos, int tamanho, int indice);
int deletarProduto(Produto *produtos, int *tamanho, int id);
int buscarProdutoPorId(Produto *produtos, int inicio, int fim, int id);
float somaProduto(Produto **produtos, int *tamanho);
void ordenarProdutosPreco(Produto **produtos, int tamanho);
#endif