# Lista 4 — Ordenação elementar (C++)

Lista de exercícios de Estrutura de Dados II sobre algoritmos de ordenação e seleção: Bubble Sort, Merge Sort, Quick Sort (partição de Lomuto e de Hoare) e Quickselect. Cada exercício é um arquivo `.cpp` independente.

## Estrutura

```
Lista-4/
├── src/
│   ├── Exer01_BubbleSortSwapCount.cpp
│   ├── Exer02_SelectionKSmallest.cpp
│   ├── Exer03_InsertionKSorted.cpp
│   ├── Exer04_BubbleParitySort.cpp
│   └── Exer05_InsertionInversions.cpp
├── main.cpp
└── CMakeLists.txt
```

> Os nomes dos arquivos não descrevem o conteúdo de todos os exercícios. A tabela abaixo mostra o que cada um implementa de fato.

## Exercícios

| # | Arquivo | O que faz | Status |
|---|---------|-----------|--------|
| 1 | `Exer01_BubbleSortSwapCount.cpp` | Bubble Sort com parada antecipada que devolve o vetor ordenado e o número de trocas | Testes locais passam |
| 2 | `Exer02_SelectionKSmallest.cpp` | Ordena strings por tamanho decrescente de duas formas: Merge Sort estável (a) e Quick Sort com partição de Lomuto, instável (b) | Sem `main` e sem testes |
| 3 | `Exer03_InsertionKSorted.cpp` | Quickselect com partição de Lomuto para achar o k-ésimo maior elemento, contando as trocas | Teste 1 passa, teste 2 falha |
| 4 | `Exer04_BubbleParitySort.cpp` | Pares em ordem crescente, depois ímpares em ordem decrescente. Versão com Bubble Sort e versão com partição de Hoare + `std::sort` | Testes locais passam |
| 5 | `Exer05_InsertionInversions.cpp` | Contagem de inversões com Insertion Sort | Arquivo vazio |

### Detalhes

**1. Contagem de trocas no Bubble Sort.** `bubble_sort_swap_count` percorre o vetor, conta cada troca e para se uma passada completa não trocar nada. Exemplo: `{2, 3, 8, 6, 1}` termina em `{1, 2, 3, 6, 8}` com 5 trocas.

**2. Estabilidade com strings.**
- `stableMergeSort` usa `>=` na comparação do merge, então strings de mesmo tamanho mantêm a ordem original.
- `unstableQuickSort` usa Lomuto com o pivô na última posição. A troca final do pivô pode mudar a ordem relativa de elementos de mesmo tamanho.

**3. Quickselect.** O k-ésimo maior é o elemento na posição `n - k` do vetor ordenado. `quickselect` particiona e desce só para o lado que contém essa posição. Cada troca feita pela partição é contada em `swap_count`.

**4. Ordenação por paridade.** `bubble_sort_parity` usa o critério `should_swap`. `hoare_parity_sort` separa pares e ímpares com uma partição de Hoare e ordena cada metade com `std::sort`. Exemplo: `{4, 3, 2, 7, 8, 1}` vira `{2, 4, 8, 7, 3, 1}`.

## Como compilar e rodar

Requisitos: compilador com suporte a C++20 e CMake. O `CMakeLists.txt` pede CMake 4.2 ou superior.

Cada exercício gera um executável próprio:

```bash
cmake -S . -B build
cmake --build build --target Exer01_BubbleSortSwapCount
./build/Exer01_BubbleSortSwapCount
```

Troque o nome do target para rodar os outros (`Exer03_InsertionKSorted`, `Exer04_BubbleParitySort`, `main_app`).

Sem CMake, direto com g++:

```bash
g++ -std=c++20 -o exer01 src/Exer01_BubbleSortSwapCount.cpp
./exer01
```

### Modo juiz online

Os exercícios 1, 3 e 4 têm duas funções em `main`: `runLocalTests()` (ativa) e `onlineJudge()` (comentada). Para submeter em um juiz online, comente `runLocalTests();` e descomente `onlineJudge();`. A entrada vem do `stdin`.

## Problemas conhecidos

- `Exer05_InsertionInversions.cpp` só tem o cabeçalho de comentário, sem código.
- `Exer02_SelectionKSmallest.cpp` não tem `main`. Compilado sozinho dá erro de link (`undefined reference to main`).
- No `CMakeLists.txt`, os targets de `Exer02` e `Exer05` falham no link pelo mesmo motivo. Um `cmake --build build` sem `--target` não termina com sucesso.
- `Exer03`, teste 2: o `assert` espera 2 trocas e o vetor final igual ao original, mas a execução dá 0 trocas. Como o assert falha, o programa aborta ao fim do primeiro teste.
