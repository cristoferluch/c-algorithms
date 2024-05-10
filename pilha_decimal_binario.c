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


Pilha* binario(int num){
    
    Pilha *p = criar_pilha();
    int indice = 0;
    while(num > 0){
        push(p, num % 2);
        num = num / 2;
    }

    return p;
}

int main(){

    Pilha *p = binario(342);

    No * aux = p->topo;

    while(aux != NULL){
        printf("%d", aux->dado);
        aux = aux->prox;
    }

    return 0;
}