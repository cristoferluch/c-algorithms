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

void compara_tamanho(Pilha *p1, Pilha *p2){

    if(tamanho(p1) == tamanho(p2)){
        printf("Iguais");
    } else if(tamanho(p1) > tamanho(p2)){
        printf("Pilha 1 maior");
    } else {
        printf("Pilha 2 maior");
    }
}

int main(){

    Pilha *p1 = criar_pilha();
    Pilha *p2 = criar_pilha();

    push(p1, 2);
    push(p1, 3);
    push(p1, 1);
    push(p1, 1);
    
    push(p2, 5);
    push(p2, 5);
    push(p2, 5);

    compara_tamanho(p1, p2);

    return 0;
}