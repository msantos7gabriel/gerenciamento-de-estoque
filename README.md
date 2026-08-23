# Gerenciamento de Estoque de Produtos

Projeto desenvolvido em C para a disciplina de **Estrutura de Dados**, com foco em **Structs, Alocação Dinâmica de Memória e Recursão**.

O sistema simula o gerenciamento do estoque de uma loja, permitindo cadastrar, remover, listar, buscar produtos por ID, somar o valor total do estoque e ordenar por preço.

## Autores
* <a href="https://github.com/baianoo-cmd" target="_blank">Enzo Gabriel Lima Dias</a>

* <a href="https://github.com/msantos7gabriel" target="_blank">Gabriel Montalvão Santos</a>

* <a href="https://github.com/geovane-nves" target="_blank">Geovane Neves Rodrigues</a>

## 1. Objetivo

O projeto tem como objetivo aplicar, de forma integrada, os seguintes conceitos:
* `struct` para organização dos dados dos produtos;
* alocação dinâmica de memória;
* utilização de `realloc` para redimensionamento do vetor a cada novo item;
* utilização de `free` para liberação da memória ao encerrar;
* funções recursivas (listagem, busca e soma);
* busca binária recursiva por ID;
* algoritmo de ordenação (Bubble Sort);
* organização do código em múltiplos arquivos (`.h` e `.c`).

Cada produto possui:
* ID único (gerado de forma auto-incremental);
* nome;
* preço;
* quantidade em estoque.

## 2. Organização dos Arquivos

O projeto está dividido em três arquivos principais:

```text
├── main.c
├── produto.c
└── produto.h
```

### `produto.h`

É o arquivo de cabeçalho do módulo de produtos. Nele está definida a estrutura `Produto` e estão declaradas as assinaturas das funções utilizadas pelo restante do programa.

### `produto.c`

Contém a implementação da lógica de negócios e as funções operacionais do sistema.
Responsabilidades:

* **`cadastrarProduto()`**: aumenta dinamicamente a capacidade do vetor e insere os dados.
* **`listarProdutos()`**: lista os produtos utilizando recursão, sem laços de repetição.
* **`deletarProduto()`**: remove produtos pelo ID e desloca os elementos subsequentes.
* **`buscarProdutoPorId()`**: encontra produtos de forma eficiente utilizando busca binária recursiva.
* **`ordenarProdutosPreco()`**: exibe os itens ordenados pelo preço utilizando um vetor dinâmico auxiliar.
* **`somaProduto()`**: calcula recursivamente o valor total financeiro dos produtos em estoque.

### `main.c`

É responsável pelo fluxo principal do programa e pela interação com o usuário através de um menu interativo, além de garantir a liberação final da memória (`free(produtos)`).

## 3. Alocação Dinâmica

Os produtos são armazenados em um vetor alocado dinamicamente.
Inicialmente, o vetor começa vazio:

```c
Produto *produtos = NULL;
int tamanho = 0;
```

A cada novo cadastro, não há desperdício de memória. O tamanho do vetor é incrementado em exata 1 posição utilizando `realloc`:

```c
Produto *temp = realloc(*produtos, (*tamanho + 1) * sizeof(Produto));
```

A variável `tamanho` representa a quantidade exata de produtos atualmente cadastrados. Ao finalizar o programa (opção `0` do menu), toda a memória utilizada pelo vetor é devolvida ao sistema operacional com:

```c
free(produtos);
```

## 4. Recursão e Ordenação

O projeto utiliza funções recursivas em operações que percorrem, pesquisam ou calculam valores no vetor.

* **Listagem:** A função `listarProdutos()` percorre os produtos recursivamente. O caso base ocorre quando o índice alcança o `tamanho` do vetor. Caso contrário, imprime o produto e chama a si mesma para o próximo índice.
* **Busca por ID:** A função `buscarProdutoPorId()` implementa uma busca binária recursiva. A cada chamada, verifica o elemento central do intervalo:
* se for o ID procurado, retorna o índice;
* se for menor, continua a busca recursiva na metade esquerda;
* se for maior, continua na metade direita.


* **Soma do Estoque:** A função `somaProduto()` calcula o montante total somando o valor do produto atual (preço × quantidade) ao retorno da mesma função chamada para o restante do vetor.
* **Ordenação Inteligente:** A função `ordenarProdutosPreco()` (Bubble Sort) aloca um vetor dinâmico auxiliar para realizar a ordenação visual por preço. Isso garante que o vetor original, na função `main`, continue ordenado por ID, preservando o funcionamento da busca binária.

## 5. Tratamento de Erros

O programa possui tratamentos robustos para diversas situações, incluindo:

* falha na alocação de memória (se `realloc` ou `malloc` retornarem `NULL`);
* tentativa de remover ou buscar um produto inexistente;
* tentativa de listar, buscar ou somar quando o estoque está vazio;
* opções inválidas no menu numérico;
* entradas inválidas de texto onde se esperam números (tratamento no `scanf`).

## 6. Como Compilar e Executar

O projeto pode ser compilado utilizando o compilador GCC. Siga as instruções correspondentes ao seu sistema operacional:

### Em ambientes Linux

No terminal, dentro da pasta do projeto, execute o comando (com as flags recomendadas para avisos):

```bash
gcc -Wall -Wextra -o estoque main.c produto.c
```

Em seguida, execute o programa:

```bash
./estoque
```

### Em ambientes Windows

Abra o Prompt de Comando (CMD) ou PowerShell e compile com:

```cmd
gcc -Wall -Wextra -o estoque.exe main.c produto.c
```

Em seguida, execute o programa:

```cmd
estoque.exe
```

## 7. Como Utilizar

Ao iniciar o programa, será apresentado o menu principal em modo texto:

```text
====================================
       GERENCIAMENTO DE ESTOQUE
====================================
1 - Cadastrar produto
2 - Remover produto
3 - Listar produtos
4 - Buscar produto por ID
5 - Ordenar produtos por preco
6 - Calcular valor total do estoque
0 - Sair
====================================
Escolha uma opcao: 
```

**Dica:** Sempre utilize a opção `0` para sair do programa de forma segura, garantindo que o sistema libere a memória alocada e previna *memory leaks*.

