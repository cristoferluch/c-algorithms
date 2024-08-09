#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

No* novo_no(int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir_arvore(No* raiz, int chave) {
    if (raiz == NULL) {
        return novo_no(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = inserir_arvore(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir_arvore(raiz->direita, chave);
    }

    return raiz;
}

No* minimo_no(No* no) {
    No* atual = no;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* remover_no(No* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }

    if (chave < raiz->chave) {
        raiz->esquerda = remover_no(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = remover_no(raiz->direita, chave);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* temp = minimo_no(raiz->direita);

        raiz->chave = temp->chave;

        raiz->direita = remover_no(raiz->direita, temp->chave);
    }
    return raiz;
}

void imprimir_arvore(No* no) {
    if (no != NULL) {
        imprimir_arvore(no->esquerda);
        printf("%d ", no->chave);
        imprimir_arvore(no->direita);
    }
}

// Função principal
int main() {
    No* raiz = NULL;

    // Inserir elementos na árvore
    raiz = inserir_arvore(raiz, 50);
    raiz = inserir_arvore(raiz, 30);
    raiz = inserir_arvore(raiz, 20);
    raiz = inserir_arvore(raiz, 40);
    raiz = inserir_arvore(raiz, 70);
    raiz = inserir_arvore(raiz, 60);
    raiz = inserir_arvore(raiz, 80);

    // Imprimir a árvore em ordem
    printf("arvore em ordem: ");
    imprimir_arvore(raiz);
    printf("\n");

    // Remover um elemento
    raiz = remover_no(raiz, 50);

    // Imprimir a árvore após remoção
    printf("arvore apos remocao de 50: ");
    imprimir_arvore(raiz);
    printf("\n");

    return 0;
}
