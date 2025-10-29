#include <stdio.h>

typedef node *nodePointer;

typedef struct node
{
  int v;
  nodePointer next;
} node;

typedef graph *Graph;

typedef struct graph
{
  int n;
  node *adj;
} graph;

Graph create_graph (int n) {
  Graph graphs = malloc(sizeof(struct graph));
  graphs->n = n;
  graphs->adj = malloc(n * sizeof(Graph));
  for (int i = 0; i < n; i++)
    graphs->adj[i] = NULL;
  return graphs;
}

void free_list (nodePointer n) {
  if (n != NULL){
    free_list(n->next);
    free(n);
  } 
}

void destroy_graph (Graph g) {
  for (int i = 0; i < g->n; i++){
    free_list(g->adj[i]);
  }
  free(g->adj);
  free(g);
}

nodePointer insert (nodePointer n, int v) {
  nodePointer new = malloc(sizeof(struct node));
  new->v = v;
  new->next = n;
  return new;
}

void insert_graph (Graph g, int u, int v) {
  g->adj[v] = insert(g->adj[v], u);
  g->adj[u] = insert(g->adj[u], v);
}

nodePointer remove_node (nodePointer n, int v) {
  nodePointer next;
  if (n == NULL)
    return NULL;
  if (n->v != v){
    n->next = remove_node (n->next, v);
    return n;
  } else {
    next = n->next;
    free(n);
    return next;
  }
}

void remove_graph (Graph g, int u, int v) {
  g->adj[v] = remove_node(g->adj[v], u);
  g->adj[u] = remove_node(g->adj[u], v);
}

int link_exists (Graph g, int u, int v) {
  for (int i = 0; i < g->n; i++){
    if (g[u][i]->v == v)
      return 1;
  }
  return 0;
}

void print(Graph g) {
  for (int i = 0; i < g->n; i++){
    for (Graph t = g; t != NULL; t = t->next)
      printf("{%d,%d}\n", i, t->v);
  }
}

Graph digraph_to_graph(Graph d) {
  Graph g = create_graph(d->n);
  for (int i = 0; i < d->n; i++){
    for (Graph t = g; t != NULL; t = t->next){
      if (link_exists(g,i,t->v))
      {
        insert_graph(g, i, t->v);
      }
    }
  } return g;
}

int *find_paths(Graph g, int s)
{
  int *head = malloc(g->n * sizeof(int));
  for (int i = 0; i < g->n; i++)
    head[i] = -1;
  deep_search(g,head,s,s);
  return head;
}

void deep_search(Graph g, int *head, int p, int v)
{
  head[v] = p;
  for (nodePointer t = g->adj[v]; t != NULL; t = t->prox)
    if (head[t->v] == -1)
      deep_search(g, head, v, t->v);
}

void print_reverse_path(int v, int *head){
  printf("%d", v);
  if (head[v]!=v)
    print_reverse_path(head[v], head);
}

void print_path(int v, int *head)
{
  if (head[v] != v)
    print_reverse_path(head[v], head);
  printf("%d", v);
}



int main()
{
  Graph g = create_graph(5);

  insert_graph(g, 0, 1);
  insert_graph(g, 0, 2);
  insert_graph(g, 1, 3);
  insert_graph(g, 2, 3);
  insert_graph(g, 3, 4);

  printf("Arestas do grafo original:\n");
  print(g);

  printf("\nRemovendo aresta {0,2}\n");
  remove_graph(g, 0, 2);
  print(g);

  printf("\nVerificando conexão entre 1 e 3: ");
  printf("%s\n", link_exists(g, 1, 3) ? "Sim" : "Não");

  printf("Verificando conexão entre 0 e 2: ");
  printf("%s\n", link_exists(g, 0, 2) ? "Sim" : "Não");

  Graph d = create_graph(4);
  insert_graph(d, 0, 1);
  insert_graph(d, 1, 2);
  insert_graph(d, 2, 3);

  Graph g2 = digraph_to_graph(d);
  printf("\nConversão de dígrafo para grafo não direcionado:\n");
  print(g2);

  destroy_graph(g);
  destroy_graph(d);
  destroy_graph(g2);

  return 0;
}
