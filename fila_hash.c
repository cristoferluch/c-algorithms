#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Lista;

typedef struct {
    Lista tabela[7];
} Hash;

int busca_posicao(int chave) {
    return chave % 7;
}

No* criar_no(int chave) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->valor = chave;
        novo->prox = NULL;
    }
    return novo;
}

void criar_tabela(Hash* hash) {
    for (int i = 0; i < 7; i++) {
        hash->tabela[i].topo = NULL;
    }
}

void inserir_hash(Hash* hash, int valor) {
    int index = busca_posicao(valor);
    No* novo = criar_no(valor);
    if (novo != NULL) {
        novo->prox = hash->tabela[index].topo;
        hash->tabela[index].topo = novo;
    }
}

No* buscar_hash(Hash* hash, int valor) {
    int index = busca_posicao(valor);
    No* atual = hash->tabela[index].topo;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void listar_tabela(Hash* hash) {
    for (int i = 0; i < 7; i++) {
        printf("[%d]:", i);
        No* atual = hash->tabela[i].topo;
        while (atual != NULL) {
            printf(" %d", atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
}

int main() {
    Hash hash;
    criar_tabela(&hash);

    inserir_hash(&hash, 10);
    inserir_hash(&hash, 20);
    inserir_hash(&hash, 3);

    listar_tabela(&hash);

    No* resultado = buscar_hash(&hash, 10);
    if (resultado != NULL) {
        printf("Achou\n");
    } else {
        printf("Nao achou\n");
    }

    return 0;
}
