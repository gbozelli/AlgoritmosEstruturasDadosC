#include <stdio.h>

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
    for (int j = 0; j < g->n; j += 1) {
      free(g->adj[i][j]);
    }
    free(g->adj[i]);
  }
  free(g->adj);
  free(g);
}

void insert (graph g, int u, int v) {
  g->adj[u][v] = 1; 
}

void remov (graph g, int u, int v) {
  g->adj[u][v] = 0; 
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