#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int proximoId = 1;

/* Cadastra um novo produto, aumentando o vetor e preenchendo seus dados. */
int cadastrarProduto(Produto **produtos, int *tamanho)
{
    // Redimensiona o vetor para abrir espaço para mais um produto.
    Produto *temp = realloc(*produtos, (*tamanho + 1) * sizeof(Produto));

    // Interrompe o cadastro caso a memoria nao possa ser reservada.
    if (temp == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 500;
    }

    *produtos = temp;

    // Gera um ID exclusivo para o novo produto.
    (*produtos)[*tamanho].id_produto = proximoId;
    proximoId++;

    // Le os dados informados pelo usuario e armazena-os no novo item.
    printf("Digite o nome: ");
    scanf("%99s", (*produtos)[*tamanho].nome);

    printf("Digite o preco: ");
    scanf("%f", &(*produtos)[*tamanho].preco);

    printf("Digite a quantidade: ");
    scanf("%d", &(*produtos)[*tamanho].quantidade);

    printf("Produto cadastrado com sucesso!\n");
    printf("\n");

    (*tamanho)++; // Operador de incremento tem ordem de precedência maior que desreferenciação

    return 0;
}

/* Lista recursivamente todos os produtos a partir do indice informado. */
void listarProdutos(Produto *produtos, int tamanho, int indice)
{
    // Encerra a recursao quando todos os produtos forem exibidos.
    if (indice == tamanho)
        return;

    printf("ID: %d\n", produtos[indice].id_produto);
    printf("Nome: %s\n", produtos[indice].nome);
    printf("Preco: %.2f\n", produtos[indice].preco);
    printf("Quantidade: %d\n", produtos[indice].quantidade);
    printf("\n");

    listarProdutos(produtos, tamanho, indice + 1);
}

/* Procura um produto pelo ID, remove-o do vetor e atualiza seu tamanho. */
int deletarProduto(Produto *produtos, int *tamanho, int id)
{

    int indiceEncontrado = -1;

    // Procura no vetor a posicao correspondente ao ID informado.
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
        // Retorna zero quando nenhum produto possui o ID procurado.
        return 0;
    }

    // Move os produtos seguintes uma posicao para preencher o espaco removido.
    for (int i = indiceEncontrado; i < *tamanho - 1; i++)
    {
        produtos[i] = produtos[i + 1];
    }
    // Realloc
    (*tamanho)--;

    return 1;
}

/* Busca recursivamente um ID em um vetor ordenado usando busca binaria. */
int buscarProdutoPorId(Produto *produtos, int inicio, int fim, int id)
{

    // Caso-base: o intervalo de busca terminou sem encontrar o produto.
    if (inicio > fim)
    {
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;

    // Verifica o produto localizado no meio do intervalo atual.
    if (id == produtos[meio].id_produto)
    {
        return meio;
    }

    if (id < produtos[meio].id_produto)
    {
        // Continua a busca na metade esquerda do vetor.
        return buscarProdutoPorId(produtos, inicio, meio - 1, id);
    }
    else
    {
        // Continua a busca na metade direita do vetor.
        return buscarProdutoPorId(produtos, meio + 1, fim, id);
    }
}

/* Soma recursivamente o valor de todos os produtos do estoque. */
float somaProduto(Produto **produtos, int *tamanho)
{

    if (*produtos == NULL)
    {
        printf("Não há produtos cadastrados para realizar o calculo\n\n");
        return -1;
    }
    if (*tamanho == 0)
    {
        // Nao ha itens para somar quando o tamanho do vetor e zero.
        return 0;
    }

    int indice_atual = *tamanho - 1;

    // Calcula o valor total do produto que sera somado nesta chamada.
    float valor_atual = (*produtos)[indice_atual].preco * (*produtos)[indice_atual].quantidade;

    // Para Não alterar o valor da main
    int novo_tamanho = indice_atual;

    float soma = valor_atual + somaProduto(produtos, &novo_tamanho);

    return soma;
}

/* Ordena uma copia dos produtos por preco e exibe o resultado. */
void ordenarProdutosPreco(Produto **produtos, int tamanho)
{
    // Evita acessar o vetor quando nenhum endereco foi fornecido.
    if (produtos == NULL)
    {
        printf("Não há produtos cadastrados\n\n");
        return;
    }

    // Cria uma copia para que a ordenacao nao altere o vetor original.
    // Criando um vetor auxiliar para não alterar os produtos na main
    Produto *sorted_produtos = malloc(tamanho * sizeof(Produto));
    if (sorted_produtos == NULL)
    {
        printf("Erro na alocação de memoria\n");
        printf("Não foi possivel executar a função\n\n");
        return;
    }

    // Passando todos os valores do vetor da main para o vetor local para evitar de trocar valores
    for (int i = 0; i < tamanho; i++)
    {
        sorted_produtos[i] = (*produtos)[i];
    }

    // Organizando com base no valor dos produtos (Bubble Sort)
    Produto aux; // Variável auxiliar para a troca de ordem
    // Laco que garante que todos os elementos vao para seus devidos lugares
    for (int i = 0; i < tamanho - 1; i++)
    {
        // Repete as comparacoes para posicionar os maiores precos primeiro.
        // Laço das comparações dos vizinhos
        for (int j = 0; j < tamanho - 1; j++)
        {
            // Crescente = > || Decrescente = <
            if (sorted_produtos[j].preco < sorted_produtos[j + 1].preco)
            {
                // Menor para o Maior
                aux = sorted_produtos[j + 1];
                sorted_produtos[j + 1] = sorted_produtos[j];
                sorted_produtos[j] = aux;
            }
        }
    }

    // Exibe os produtos depois da ordenacao por preco.
    // Impressão da Lista
    printf("\n========== PRODUTOS ==========\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("ID: %d\n", sorted_produtos[i].id_produto);
        printf("Nome: %s\n", sorted_produtos[i].nome);
        printf("Preco: %.2f\n", sorted_produtos[i].preco);
        printf("Quantidade: %d\n", sorted_produtos[i].quantidade);
        printf("\n");
    }

    // Liberando o vetor organizado
    free(sorted_produtos);
    return;
}