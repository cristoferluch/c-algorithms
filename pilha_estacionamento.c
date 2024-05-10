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

void lista_veiculos(Pilha *p, int pos){
    No * aux = p->topo;
    int indice = 0;

    if(pos > -1){
        while(indice != pos && aux != NULL){
            aux = aux->prox;
            indice++;
        }
    }

    while(aux != NULL){
        indice++;
        printf("\n[%d] -> %d", indice, aux->dado);
        if(pos > -1){
            return;
        }
        aux = aux->prox;
    }
}

void verifica_carro(Pilha *p, int placa){
    No * aux = p->topo;
    int pos = 0;

    while(aux != NULL){
        if(aux->dado != placa){
            lista_veiculos(p, pos);
        } else {
            return;
        }
        aux = aux->prox;
        pos++;
    }
}

int main(){

    Pilha *p = criar_pilha();

    push(p, 123456);
    push(p, 987654);
    push(p, 121212);
    push(p, 888888);
    push(p, 333333);
    push(p, 222222);

    printf("\nOrdem dos veiculos:");
    lista_veiculos(p, -1);

    printf("\n\nVeiculos que estao na frente:");
    verifica_carro(p, 121212);

    return 0;
}