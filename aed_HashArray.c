#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valoralfa(char letra){
    int x;
    x = letra - 'A';
    return x;
}

int calculate(char *elemento, int j){
    int i, tam, hash = 0;
    tam = strlen(elemento);

    for (i = 0; i < tam; i++){
    hash += valoralfa(elemento[i]);
    hash += i;
    hash += j; 
    }
    return hash;
}


int main(){
int N, L, hash;

scanf("%d", &N);
for (int i = 0; i < N; i++){
    hash = 0;
    scanf("%d", &L);
    if (L > 100){
        break;
    }

    else{
        for(int j = 0; j < L; j++){
            char elemento[51];
            scanf("%s", &elemento);
            hash += calculate(elemento, j);  
        }
        printf("%d\n", hash);
    }

}


return 0;
}