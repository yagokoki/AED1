#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

struct no {
    char nome[MAX];
    struct no *prox;
};
typedef struct no *no;




no cria_no(char *ainserir, int tam){
    no novoNo = (no) malloc(sizeof(struct no));
    int i;
    for (i = 0; i < tam; i++){
        novoNo->nome[i] = ainserir[i];
    }
    novoNo->nome[i] = '\0';
    novoNo->prox = NULL;
    return novoNo;
}

no insere_ordenado(no raiz, char *ainserir, int tam) {
    no novoNo = cria_no(ainserir, tam);
    if (raiz == NULL || strcmp(ainserir, raiz->nome) < 0) {
        novoNo->prox = raiz;
        return novoNo;
    }
    no aux = raiz;
    while (aux->prox != NULL && strcmp(ainserir, aux->prox->nome) >= 0) {
        aux = aux->prox;
    }
    novoNo->prox = aux->prox;
    aux->prox = novoNo;
    return raiz;
}


void printa(no raiz){
    no aux = raiz;
    for (aux = raiz; aux != NULL; aux = aux->prox) {
        printf("%s\n", aux->nome);
    }
       // printf("\n");
}


int main(void){
no raiz = NULL;
int n;
int aux;
int k;
char nome[MAX];

//n = 4;
//k = 2;
scanf("%d %d", &n, &k);
for (int i = 0; i < n; i++){
    scanf("%s", &nome);
    aux = strlen(nome);
    if (i == 0){
        raiz = cria_no(nome, aux);
    }
    else{
        raiz = insere_ordenado(raiz, nome, aux);
    }
}

//organizalista(raiz);

for (int i = 0; i < k-1; i++){
    raiz = raiz->prox;
}

printf("%s\n", raiz->nome);


    return 0;
}
