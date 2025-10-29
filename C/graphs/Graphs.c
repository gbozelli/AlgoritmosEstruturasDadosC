#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int **adj;
  int n;
} Graph; typedef Graph * graph;

graph create (int n) {
  graph g = malloc(sizeof(Graph));
  g->n = n;
  g->adj = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i += 1)
    g->adj[i] = malloc(n * sizeof(int));
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      g->adj[i][j] = 0;
    }
  }
  return g;
}

void destroy (graph g) {
  for (int i = 0; i < g->n; i += 1) {
    free(g->adj[i]);
  }
  free(g->adj);
  free(g);
}

void insert (graph g, int u, int v) {
  g->adj[u][v] = 1;
  g->adj[v][u] = 1;
}

void remov (graph g, int u, int v) {
  g->adj[u][v] = 0;
  g->adj[v][u] = 0;
}

int conection(graph g, int u, int v) {
  return g->adj[u][v];
}

void print (graph g) {
  int u, v;
  for (u = 0; u < g->n; u += 1)
    for (v = u+1; v < g->n; v += 1)
      if (g->adj[u][v])
        printf("{%d,%d}\n", u, v);
}

int degree (graph g, int u) {
  int d = 0;
  for (int i = 0; i < g->n; i += 1){
    if (g->adj[u][i] == 1)
      d += 1;
  }
  return d;
}

int most_popular(graph g) {
  int v = 0;
  int count = 0;
  int current = 0;
  for (int i = 0; i < g->n; i += 1) {
    current = degree(g, i);
    if (current > count){
      count = current;
      v = i;
    }
  }
  return v;
}

void print_recomendations(graph g, int u) {
  for (int i = 0; i < g->n; i++){
    if (g->adj[u][i]) {
      for (int j = 0; j < g->n; j++) {
        if (!g->adj[u][j] && j != u && !g->adj[u][j])
          printf("%d\n", j);
      }
    }
  }
}

graph digraph_to_graph(graph d)
{
  graph g = create(d->n);
  for (int i = 0; i < d->n; i++)
  {
    for (int j = 0; j < d->n; j++)
    {
      if (d->adj[i][j] || d->adj[j][i])
      {
        g->adj[i][j] = 1;
        g->adj[j][i] = 1;
      }
      else
      {
        g->adj[i][j] = 0;
        g->adj[j][i] = 0;
      }
    }
  }
  return g;
}

int path_exists (graph g, int s, int t) {
  int found, *visited = malloc(g->n * sizeof(int));
  for (int i = 0; i < g->n; i++)
    visited[i] = 0;
  found = recursive_search(g, visited, s, t);
  free(visited);
  return found;
}

int recursive_search (graph g, int *visited, int v, int t) {
  if (v == t)
    return 1;
  visited[v] = 1;
  for (int w = 0; w < g->n; w++)
    if(g->adj[v][w] && !visited[w])
      if(recursive_search(g,visited,w,t))
        return 1;
  return 0;
}

int *deep_search_queue(graph g, int s)
{

}

int main()
{
  graph g = create(5);

  insert(g, 0, 1);
  insert(g, 0, 2);
  insert(g, 1, 3);
  insert(g, 2, 3);
  insert(g, 3, 4);

  printf("Arestas:\n");
  print(g);

  printf("\nGrau do vertice 3: %d\n", degree(g, 3));
  printf("Vertice mais popular: %d\n", most_popular(g));

  printf("\nRemovendo aresta {0,2}\n");
  remov(g, 0, 2);
  print(g);

  printf("\nConexao entre 1 e 3: %d\n", conection(g, 1, 3));
  printf("Conexao entre 0 e 2: %d\n", conection(g, 0, 2));

  printf("\nRecomendacoes para o vertice 4:\n");
  print_recomendations(g, 4);

  graph d = create(4);
  d->adj[0][1] = 1;
  d->adj[1][2] = 1;
  d->adj[2][3] = 1;

  graph g2 = digraph_to_graph(d);
  printf("\nGrafo nao direcionado a partir de digrafo:\n");
  print(g2);

  destroy(g);
  destroy(d);
  destroy(g2);

  return 0;
}
