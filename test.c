#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int dado;
    struct node *prox;
} node;

typedef struct node * nodePointer;


nodePointer criar_lista() {
    return NULL;
}

void destruir_lista(nodePointer lista) {
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}

nodePointer adicionar_elemento(nodePointer lista, int x) {
    nodePointer novo;
    novo = malloc(sizeof(node));
    novo->dado = x;
    novo->prox = lista;
    return novo;
}

void imprime(nodePointer lista) {
    nodePointer atual;
    for(atual = lista; atual != NULL; atual = atual->prox)
    printf("%d\n", atual->dado);
}


int main(){
    nodePointer lista;
    lista = criar_lista();
    adicionar_elemento(lista, 9);
    imprime(lista);
    destruir_lista(lista);
    return 0;
}