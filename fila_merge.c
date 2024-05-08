#include <stdio.h> 
#include <stdlib.h>

typedef struct No{
    struct No* prox;
    int dado;
} No;

typedef struct Fila{
    No* inicio;
    No* fim;
}Fila;

Fila* criar_fila(){
    Fila *fila = malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL; 
    return fila;
}

void destruir_fila(Fila *f){
    
    if (f->inicio != NULL){
        No *aux = f->inicio;
        No *prox = f->inicio;
    
        while(aux->prox != NULL){
            prox = aux->prox;
            free(aux);
            aux = prox;
        }
    }
    
    free(f);
    return;
}

void inserir(Fila* f, int x){
    No *aux;
    No *elemento = malloc(sizeof(No));
    elemento -> dado = x;
    elemento -> prox = NULL;
    
    if (f->inicio == NULL){
        f->inicio = elemento;
        f->fim = elemento;
    }else{
        aux = f->fim;
        aux->prox=elemento; 
        f->fim = elemento;
    }
}

int remover(Fila* f){
    No *aux = f->inicio;
    f->inicio = f->inicio->prox;
    int dado = aux->dado; 
    free(aux);
    
    return dado;
}

int tamanho(Fila* f){
    int tamanho = 0; 
    
    if(f->inicio != NULL){
        No *aux = f->inicio;
        while(aux->prox != NULL){
            tamanho++;
            aux = aux->prox;
        }
        tamanho++; 
    }
    
    return tamanho; 
}


Fila *juncao(Fila *fila1, Fila *fila2){

    int indice = 0;

    Fila *fila3 = criar_fila(fila3);

    No * aux1 = fila1->inicio;
    No * aux2 = fila2->inicio;

    while(indice < tamanho(fila1) || indice < tamanho(fila2)){
        if(indice < tamanho(fila1)){
            inserir(fila3, aux1->dado);
            aux1 = aux1->prox;
        }
        if(indice < tamanho(fila2)){
            inserir(fila3, aux2->dado);
            aux2 = aux2->prox;
        }
        indice++;
    }

    return fila3;
}

void elementos(Fila * fila){
    No * aux = fila->inicio;

    while(aux != NULL){
        printf("\n%d", aux->dado);
        aux = aux->prox;
    }
}

int main(){

    Fila *fila1 = criar_fila(fila1);
    Fila *fila2 = criar_fila(fila1);

    inserir(fila1, 3);
    inserir(fila1, 6);
    inserir(fila1, 9);

    inserir(fila2, 2);
    inserir(fila2, 4);
    inserir(fila2, 8);


    printf("\nTamanho fila1: %d", tamanho(fila1));
    printf("\nTamanho fila2: %d", tamanho(fila2));

    Fila *fila3 = juncao(fila1, fila2);

    printf("\nTamanho fila3: %d", tamanho(fila3));


    elementos(fila3);

}