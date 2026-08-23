#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct
{
    int id_produto;
    char nome[100];
    float preco;
    int quantidade;
} Produto;

/* Cadastra um produto no vetor e atualiza a quantidade de itens. */
int cadastrarProduto(Produto **produtos, int *tamanho);
/* Lista os produtos recursivamente a partir de um indice. */
void listarProdutos(Produto *Produtos, int tamanho, int indice);
/* Remove do vetor o produto que possui o ID informado. */
int deletarProduto(Produto *produtos, int *tamanho, int id);
/* Busca um produto por ID em um vetor ordenado. */
int buscarProdutoPorId(Produto *produtos, int inicio, int fim, int id);
/* Calcula o valor total dos produtos armazenados. */
float somaProduto(Produto **produtos, int *tamanho);
/* Ordena uma copia dos produtos por preco e exibe a lista ordenada. */
void ordenarProdutosPreco(Produto **produtos, int tamanho);
#endif