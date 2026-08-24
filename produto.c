#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int proximoId = 1;

int cadastrarProduto(Produto **produtos, int *tamanho)
{
    Produto *temp = realloc(*produtos, (*tamanho + 1) * sizeof(Produto));

    if (temp == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 500;
    }

    *produtos = temp;

    (*produtos)[*tamanho].id_produto = proximoId;
    proximoId++;

    printf("Digite o nome: ");
    scanf("%99s", (*produtos)[*tamanho].nome);

    printf("Digite o preco: ");
    scanf("%f", &(*produtos)[*tamanho].preco);

    printf("Digite a quantidade: ");
    scanf("%d", &(*produtos)[*tamanho].quantidade);

    printf("Produto cadastrado com sucesso!\n");
    printf("\n");

    (*tamanho)++;

    return 0;
}

void listarProdutos(Produto *produtos, int tamanho, int indice)
{
    if (indice == tamanho)
        return;

    printf("ID: %d\n", produtos[indice].id_produto);
    printf("Nome: %s\n", produtos[indice].nome);
    printf("Preco: %.2f\n", produtos[indice].preco);
    printf("Quantidade: %d\n", produtos[indice].quantidade);
    printf("\n");

    listarProdutos(produtos, tamanho, indice + 1);
}

int deletarProduto(Produto *produtos, int *tamanho, int id)
{

    int indiceEncontrado = -1;

    for (int i = 0; i < *tamanho; i++)
    {
        if (produtos[i].id_produto == id)
        {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado == -1)
    {
        return 0;
    }

    for (int i = indiceEncontrado; i < *tamanho - 1; i++)
    {
        produtos[i] = produtos[i + 1];
    }
    (*tamanho)--;

    return 1;
}

int buscarProdutoPorId(Produto *produtos, int inicio, int fim, int id)
{

    if (inicio > fim)
    {
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;

    if (id == produtos[meio].id_produto)
    {
        return meio;
    }

    if (id < produtos[meio].id_produto)
    {
        return buscarProdutoPorId(produtos, inicio, meio - 1, id);
    }
    else
    {
        return buscarProdutoPorId(produtos, meio + 1, fim, id);
    }
}

float somaProduto(Produto **produtos, int *tamanho)
{

    if (*produtos == NULL)
    {
        printf("Não há produtos cadastrados para realizar o calculo\n\n");
        return -1;
    }
    if (*tamanho == 0)
    {
        return 0;
    }

    int indice_atual = *tamanho - 1;

    float valor_atual = (*produtos)[indice_atual].preco * (*produtos)[indice_atual].quantidade;

    int novo_tamanho = indice_atual;

    float soma = valor_atual + somaProduto(produtos, &novo_tamanho);

    return soma;
}

void ordenarProdutosPreco(Produto **produtos, int tamanho)
{
    if (produtos == NULL)
    {
        printf("Não há produtos cadastrados\n\n");
        return;
    }

    Produto *sorted_produtos = malloc(tamanho * sizeof(Produto));
    if (sorted_produtos == NULL)
    {
        printf("Erro na alocação de memoria\n");
        printf("Não foi possivel executar a função\n\n");
        return;
    }

    for (int i = 0; i < tamanho; i++)
    {
        sorted_produtos[i] = (*produtos)[i];
    }

    Produto aux;
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - 1; j++)
        {
            if (sorted_produtos[j].preco < sorted_produtos[j + 1].preco)
            {
                aux = sorted_produtos[j + 1];
                sorted_produtos[j + 1] = sorted_produtos[j];
                sorted_produtos[j] = aux;
            }
        }
    }

    printf("\n========== PRODUTOS ==========\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("ID: %d\n", sorted_produtos[i].id_produto);
        printf("Nome: %s\n", sorted_produtos[i].nome);
        printf("Preco: %.2f\n", sorted_produtos[i].preco);
        printf("Quantidade: %d\n", sorted_produtos[i].quantidade);
        printf("\n");
    }

    free(sorted_produtos);
    return;
}