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

void elementos(Pilha *p){
    No * aux = p->topo;
    while(aux != NULL){
        printf("\n%d", aux->dado);
        aux = aux->prox;
    }
}


Pilha *inverte(Pilha *p) {
    Pilha *p1 = criar_pilha(p1); 
    Pilha *p2 = criar_pilha(p2); 
    int dado = 0;

    while(p->topo != NULL){
        dado = pop(p);
        push(p1, dado);
    } 

    while(p1->topo != NULL){
        dado = pop(p1);
        push(p2, dado);
    } 

    while(p2->topo != NULL){
        dado = pop(p2);
        push(p, dado);
    } 

    return p;
}

int main(){

    Pilha *p = criar_pilha(p);

    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);

    printf("\n\nInvertido:");
    elementos(inverte(p));

    return 0;
}