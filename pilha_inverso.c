#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    struct No* prox;
    int dado;
} No;

typedef struct Pilha{
    No* topo;
}Pilha;

Pilha* criar_pilha(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha *p, int valor){
    No *aux = malloc(sizeof(No));
    aux->dado = valor;
    aux->prox = p->topo;
    p->topo = aux;
}

int pop(Pilha *p){
    int removido;
    if(p->topo == NULL){
        return 0;
    }
    No *aux = p->topo;
    p->topo = aux->prox;
    removido = aux->dado;
    free(aux);
    return removido;
}

int tamanho(Pilha *p){
    int tamanho = 0;
    No *aux = p->topo;
    
    while(aux->prox){
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}

void destruir_pilha(Pilha *p){
    No *aux;
    
    while(p->topo){
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }
    free(p);
}

void inverso(Pilha *p){
    int dado = 0;
    No * aux = p->topo;
    while(aux != NULL){
        dado = pop(p);
        if(dado == 0){
            return;
        }
        printf("\n%d", dado);
        aux = aux->prox;
    }
}

int main(){

    Pilha *p = criar_pilha();

    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);

    inverso(p);

    return 0;
}