#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct no{
    struct no *prox; 
    int valor;
} Noh;

typedef struct{
    Noh *inicio, *final;
} des;

void imprimeHash(Noh *inicio, int ind){
	Noh *aux = inicio;
	printf("%d -> ", ind);
	while(aux != NULL){
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}		
	printf("\\");
	printf("\n");
}

void insereNoh(des *vet, int ind, int chave){
	Noh *aux = (Noh *)malloc(sizeof(Noh));
	aux->valor = chave;
	aux->prox = NULL;
	if(vet[ind].inicio == NULL)
		vet[ind].inicio = aux;
	else
		vet[ind].final->prox = aux;
	vet[ind].final = aux;
}

void inicializa(des *vet, int n){
	int i;
	for(i=0; i<n; i++){
		vet[i].inicio = NULL;
		vet[i].final = NULL;
	}
}

int main(){
	des vet[MAX];
	int m, c, n, chave, i, j;
	
	scanf("%d", &n);
	
	for(i=0; i < n; i++){	
		scanf("%d %d", &m, &c);
		inicializa(vet, m);
		
		for(j=0; j<c; j++){
			scanf("%d", &chave);
			insereNoh(vet, chave % m, chave);
		}
		for(j = 0; j < m; j++)
			imprimeHash(vet[i].inicio, i);	
		if(i + 1 < n)
			printf("\n");
	}
	return 0;
}