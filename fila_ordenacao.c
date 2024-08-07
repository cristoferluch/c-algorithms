#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* topo;
    int tamanho;
} Lista;

Lista* criar_lista() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if (l != NULL) {
        l->topo = NULL;
        l->tamanho = 0;
    }
    return l;
}

void destruir_lista(Lista* l) {
    if (l != NULL) {
        No* atual = l->topo;
        No* prox;
        while (atual != NULL) {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(l);
    }
}

int tamanho(Lista* l) {
    return l ? l->tamanho : 0;
}

No* buscar(Lista* l, int x) {
    if (l == NULL) return NULL;
    No* atual = l->topo;
    while (atual != NULL) {
        if (atual->valor == x) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

No* buscar_enc(Lista* l, int x, No** ant) {
    if (l == NULL) return NULL;
    *ant = NULL;
    No* atual = l->topo;
    while (atual != NULL) {
        if (atual->valor == x) {
            return atual;
        }
        *ant = atual;
        atual = atual->prox;
    }
    return NULL;
}

No* inserir(Lista* l, int x) {
    if (l == NULL) {
    	return NULL;
    }
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
    	 return NULL;	
    }
    novo->valor = x;
    novo->prox = l->topo;
    l->topo = novo;
    l->tamanho++;
    return novo;
}

void remover(Lista* l, int x) {
    if (l == NULL) return;
    No* ant = NULL;
    No* atual = buscar_enc(l, x, &ant);
    if (atual != NULL) {
        if (ant == NULL) {
            l->topo = atual->prox;
        } else {
            ant->prox = atual->prox;
        }
        free(atual);
        l->tamanho--;
    }
}

No* primeiro(Lista* l) {
    if (l == NULL) {
        return NULL;
    }
    return l->topo;
}

No* ultimo(Lista* l) {
    if (l == NULL) return NULL;
    No* atual = l->topo;
    if (atual == NULL) return NULL;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    return atual;
}

No* buscar_por_indice(Lista* l, int i) {
    if (l == NULL || i < 0 || i >= l->tamanho) return NULL;
    No* atual = l->topo;
    for (int j = 0; j < i; j++) {
        atual = atual->prox;
    }
    return atual;
}

void ordenar(Lista* l) {

    bool flag;
    No* atual;
    No* prox = NULL;

    do {
        flag = false;
        atual = l->topo;

        while (atual->prox != prox) {
            if (atual->valor > atual->prox->valor) {
                int aux = atual->valor;
                atual->valor = atual->prox->valor;
                atual->prox->valor = aux;
                flag = true;
            }
            atual = atual->prox;
        }
        prox = atual;
    } while (flag);
}

void exibeLista(Lista* l){
	
	int indice = 0;

	No * aux = l->topo;
	while(aux != NULL){
		indice++;
		printf("\n[%d] -> %d", indice, aux->valor);
		aux = aux->prox;
	}	
}

int main(){

	Lista *lista1 = criar_lista(lista1);

	inserir(lista1, 3);
	inserir(lista1, 6);
	inserir(lista1, 2);
	inserir(lista1, 1);
	inserir(lista1, 7);

	exibeLista(lista1);
	ordenar(lista1);
	exibeLista(lista1);

	return 0;
}