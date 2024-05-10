#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No_float{
    float dado;
    struct No_float* prox;
}No_float;

typedef struct No_char{
    char sinal;
    struct No_char* prox;
}No_char;

typedef struct Pilha_float{
    struct No_float* topo;
}Pilha_float;

typedef struct Pilha_char{
    struct No_char* topo;
}Pilha_char;

Pilha_float* criar_pilhaF(){
    Pilha_float *p = malloc(sizeof(Pilha_float));
    p->topo = NULL;
    return p;
}

Pilha_char *criar_pilhaC(){
    Pilha_char *p = malloc(sizeof(Pilha_char));
    p->topo = NULL;
    return p;
}


void pushF(Pilha_float *p, float x){
    No_float *aux = malloc(sizeof(No_float));
    aux->dado = x;
    aux->prox = p->topo;
    p->topo = aux;
}

void pushC(Pilha_char *p, char x){
    No_char *aux = malloc(sizeof(No_char));
    aux->sinal = x;
    aux->prox = p->topo;
    p->topo = aux;
}


int popF(Pilha_float *p){
    int removido;
    if(p->topo == NULL){
        return 0;
    }
    No_float *aux = p->topo;
    p->topo = aux->prox;
    removido = aux->dado;
    free(aux);
    return removido;
}

char popC(Pilha_char *p){
    char removido;
    if(p->topo == NULL){
        return 0;
    }
    No_char *aux = p->topo;
    p->topo = aux->prox;
    removido = aux->sinal;
    free(aux);
    return removido;
}

int tamanhoF(Pilha_float *p){
    int tamanho = 0;
    No_float *aux = p->topo;
    
    while(aux->prox){
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}

int tamanhoC(Pilha_char* p){
    int tamanho = 0;
    No_char* aux; 

    aux = p->topo;
    while(aux != NULL){
        tamanho++;
        aux = aux->prox;
    }
    
    return tamanho; 
}

void destruir_pilhaF(Pilha_float *p){
    No_float *aux;
    
    while(p->topo){
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }
    free(p);
}

void destruir_pilhaC(Pilha_char *p){
    No_char *aux;
    
    while(p->topo){
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }
    free(p);
}

void elementos(Pilha_float *p){
    No_float * aux = p->topo;
    while(aux != NULL){
        printf("\n%.2f", aux->dado);
        aux = aux->prox;
    }
}

void calcular(Pilha_float *p_float, Pilha_char *p_char){

    int indice = 0;

    while(p_char->topo != NULL){
        indice ++;
        float num1 = popF(p_float);
        float num2 = popF(p_float);
        float resultado = 0;
        char operacao = popC(p_char);


        switch(operacao){
            case '+':
                resultado = num1 + num2;
            break;
            
            case '-':
                resultado = num1 - num2;
            break;
            
            case '/':
                resultado = num1 / num2;
            break;
            
            case '*':
                resultado = num1 * num2;
            break;
        }

        printf("\n[%d] - Operacao: %.2f %c %.2f = %.2f", indice, num1, operacao, num2, resultado);

        pushF(p_float, resultado);
    }
}

int main(){

    Pilha_float *p_float = criar_pilhaF();
    Pilha_char *p_char = criar_pilhaC();

    pushF(p_float, 3.3);
    pushF(p_float, 2.2);
    pushF(p_float, 4);
    pushF(p_float, 7);
    pushF(p_float, 10);
    pushF(p_float, 5);
    pushF(p_float, 64);
    pushF(p_float, 2);

    pushC(p_char, '+');
    pushC(p_char, '-');
    pushC(p_char, '/');
    pushC(p_char, '*');

    calcular(p_float, p_char);


    return 0;
}