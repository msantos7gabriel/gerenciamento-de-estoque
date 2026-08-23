# gerenciamento-de-estoque
# Gerenciamento de Estoque de Produtos

Projeto desenvolvido em C para a disciplina de **Estrutura de Dados**, com foco em **Structs, Alocação Dinâmica de Memória e Recursão**.

O sistema simula o gerenciamento do estoque de uma loja, permitindo cadastrar, remover, listar, buscar produtos por ID, somar estoque e ordenar por preço.

## 1. Objetivo

O projeto tem como objetivo aplicar, de forma integrada, os seguintes conceitos:

* `struct` para organização dos dados dos produtos;
* alocação dinâmica de memória;
* utilização de `realloc` para redimensionamento do vetor;
* utilização de `free` para liberação da memória;
* funções recursivas;
* busca recursiva por ID;
* organização do código em arquivos `.h` e `.c`.

Cada produto possui:

* ID único;
* nome;
* preço;
* quantidade em estoque.

## 2. Organização dos arquivos

O projeto está dividido em três arquivos principais:

```text
├── main.c
├── produto.c
└── produto.h
```

### `produto.h`

É o arquivo de cabeçalho do módulo de produtos.

Nele está definida a estrutura `Produto` e estão declaradas as funções utilizadas pelo restante do programa.

Principais funções declaradas:

* `cadastrarProduto()`
* `listarProdutos()`
* `deletarProduto()`
* `buscarProdutoPorId()`
* `ordenarProdutosPreco()`
* `somaProduto()`


### `produto.c`

Contém a implementação das funções relacionadas aos produtos.

Responsabilidades atuais:

* cadastrar produtos;
* aumentar dinamicamente a capacidade do vetor;
* listar produtos utilizando recursão;
* remover produtos pelo ID;
* buscar produtos pelo ID utilizando busca binária recursiva;
* filtragem por ordem de preço;
* soma dos produtos em estoque.

### `main.c`

É responsável pelo fluxo principal do programa e pela interação com o usuário.

Atualmente possui um menu em modo texto com as operações:

```text
1 - Cadastrar produto
2 - Remover produto
3 - Listar produtos
4 - Buscar produto por ID
5 - Ordenar produtos por preço
6 - Calcular valor total do estoque
0 - Sair
```

## 3. Alocação dinâmica

Os produtos são armazenados em um vetor alocado dinamicamente.

Inicialmente:

```c
Produto *produtos = NULL;
int tamanho = 0;
int capacidade = 0;
```

Quando não existe espaço disponível, a capacidade do vetor é aumentada utilizando `realloc`.

A capacidade começa em 1 posições e, quando necessário, é incrementada:

```text
1 → 2 → 3 → 4 → ...
```

A variável `tamanho` representa a quantidade de produtos atualmente cadastrados, enquanto `capacidade` representa a quantidade de posições disponíveis no vetor.

Ao finalizar o programa, a memória utilizada pelo vetor é liberada com:

```c
free(produtos);
```

## 4. Recursão

O projeto utiliza funções recursivas em operações que percorrem ou pesquisam o vetor.

### Listagem

A função `listarProdutos()` percorre os produtos recursivamente.

O caso base ocorre quando o índice chega ao tamanho do vetor:

```c
if (indice == tamanho)
    return;
```

Caso ainda existam produtos, a função exibe o produto atual e chama a si mesma com o próximo índice.

### Busca por ID

A função `buscarProdutoPorId()` utiliza uma busca binária recursiva.

A busca trabalha com um intervalo definido por `inicio` e `fim`.

A cada chamada:

* se o ID for encontrado, retorna seu índice;
* se o ID procurado for menor que o elemento do meio, continua na metade esquerda;
* se for maior, continua na metade direita;
* se `inicio` ultrapassar `fim`, o produto não foi encontrado e a função retorna `-1`.

## 5. Tratamento de erros

O programa possui tratamentos para algumas situações de erro, incluindo:

* falha na alocação de memória com `realloc`;
* tentativa de remover um produto inexistente;
* tentativa de buscar um produto inexistente;
* tentativa de realizar operações quando o estoque está vazio;
* opção inválida no menu;
* entrada inválida no campo de opção do menu.

Em caso de falha no `realloc`, a função de cadastro retorna um código de erro para que o `main.c` possa informar o usuário.

## 6. Como compilar

O projeto pode ser compilado utilizando o GCC.

No terminal, dentro da pasta onde estão os arquivos, execute:

```bash
gcc -Wall -o estoque main.c produto.c
```

Depois, execute o programa com:

```bash
./estoque
```

No Windows, dependendo do ambiente utilizado, o executável poderá ser gerado como:

```bash
estoque.exe
```

e executado com:

```bash
estoque.exe
```

## 7. Como utilizar

Ao iniciar o programa, será apresentado o menu principal:

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
Escolha uma opção:
```


## 8. Compilação recomendada

Para verificar possíveis avisos durante a compilação:

```bash
gcc -Wall -Wextra -o estoque main.c produto.c
```

A execução deve ser feita com:

```bash
./estoque
```

