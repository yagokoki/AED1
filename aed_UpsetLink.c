#include <stdio.h>
#include <stdlib.h>
#define MAX 100000


int main(){
    char nome[MAX];
    int aux;
    int i;
    int x = 0;
    scanf("%s", &nome);
    aux = strlen(nome);
    for (i = 0; i < aux; i++){
        if (nome[i] == 'Z' || nome[i] == 'z'){
            if (nome[i + 1] == 'E' || nome [i + 1] == 'e'){
                if (nome[i + 2] == 'L' || nome[i + 2] == 'l'){
                    if (nome[i + 3] == 'D' || nome[i + 3] == 'd'){
                        if (nome[i + 4] == 'A' || nome[i + 4] == 'a'){
                            x = 1;
                        }
                    }
                }
            }
        }            
    }
    if (x != 0){
        printf("Link Bolado\n");
    }
    else{
        printf("Link Tranquilo\n");
    }
    
    return 0;
}