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

bool testaPilhas(Pilha *p1, Pilha *p2){

    No *aux1 = p1->topo;
    No *aux2 = p2->topo;
    int indice = 0;

    while(aux1 != NULL && aux2 != NULL){
        if(aux1->dado != aux2->dado){
            return false;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
        indice++;
    }
    return true;

}

int main(){

    Pilha *pilha1 = criar_pilha(pilha1);
    Pilha *pilha2 = criar_pilha(pilha2);

    
    push(pilha1, 4);
    push(pilha1, 6);
    push(pilha1, 2);
    push(pilha1, 1);

    push(pilha2, 4);
    push(pilha2, 6);
    push(pilha2, 2);
    push(pilha2, 2);


    printf("%d",testaPilhas(pilha1, pilha2));

    return 0;
}