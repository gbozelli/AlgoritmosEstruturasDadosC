# AlgorithmsDataStructuresC

Este repositório contém implementações em linguagem C de diversos algoritmos clássicos e estruturas de dados fundamentais, organizados para facilitar o estudo, aprendizado e uso prático. É uma excelente base para estudantes de Ciência da Computação, Engenharia e áreas afins que desejam entender profundamente o funcionamento interno das estruturas e algoritmos, além de praticar programação em C.

---

## 📚 Conteúdo do Projeto

O projeto cobre uma gama abrangente de algoritmos e estruturas de dados, incluindo, mas não limitado a:

### Estruturas de Dados
- **Listas Ligadas** (simples, duplamente ligadas)
- **Pilhas** (Stacks)
- **Filas** (Queues)
- **Árvores** (Árvores binárias, árvores de busca binária)
- **Grafos** (representação, busca em largura, busca em profundidade)

### Algoritmos Clássicos
- **Ordenação**: Bubble Sort, Insertion Sort, Selection Sort, Merge Sort, Quick Sort, Heap Sort
- **Busca**: Busca Linear, Busca Binária
- **Algoritmos em Grafos**: Busca em Largura (BFS), Busca em Profundidade (DFS), Dijkstra, Kruskal, Prim
- **Algoritmos de Strings**: Busca de padrões, como KMP (Knuth-Morris-Pratt)
- **Algoritmos Matemáticos**: Euclides para MDC, Fatorial, Fibonacci

---

## 🛠️ Implementação

- Todas as implementações são feitas em **C puro**, sem dependências externas, com foco em clareza, simplicidade e eficiência.
- Os arquivos estão organizados por tipo de algoritmo ou estrutura de dados.
- Cada algoritmo/estrutura vem acompanhado de funções para criação, manipulação e destruição (quando aplicável), seguindo boas práticas de programação.

---

## 🚀 Como usar

### Compilação

Para compilar os códigos, você pode usar o `gcc` no terminal:

```bash
gcc nome_do_arquivo.c -o nome_do_programa
```
Exemplo:
```bash
gcc bubble_sort.c -o bubble_sort
./bubble_sort
```
### Testes e Exemplos
Cada arquivo de implementação contém funções main() com exemplos de uso para testar diretamente a funcionalidade. Você pode compilar e executar para observar o funcionamento.

##🔍 Explicação breve de alguns algoritmos
Bubble Sort: Ordena um array repetidamente trocando elementos adjacentes que estejam fora de ordem. Complexidade: O(n²).

Merge Sort: Algoritmo de ordenação eficiente usando divisão e conquista, que divide a lista, ordena cada parte e então mescla. Complexidade: O(n log n).

Busca Binária: Busca eficiente em arrays ordenados, dividindo repetidamente o espaço de busca ao meio. Complexidade: O(log n).

Dijkstra: Algoritmo para encontrar o caminho mais curto em grafos ponderados sem arestas negativas.

Lista Ligada: Estrutura dinâmica que conecta nós contendo dados e referência ao próximo nó.

###📖 Recursos e Referências

 "Introduction to Algorithms" - Cormen et al.
 "Algorithms" - Robert Sedgewick

Documentação e tutoriais online para C

###🤝 Contribuições
Contribuições são bem-vindas! Se você quiser adicionar novos algoritmos, otimizar implementações ou corrigir bugs, fique à vontade para abrir um Pull Request.
