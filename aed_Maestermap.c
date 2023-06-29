#include <stdio.h>

#define MAX_A 100
#define MAX_L 100

char verifica(char mapa[MAX_A][MAX_L], int altura, int largura)
{
    // Verificar se o ponto de partida é um baú
    if (mapa[0][0] == '*')
        return '*';

    // Inicializar posição atual
    int pos_x = 0;
    int pos_y = 0;

    // Inicializar direção atual
    char x = '>';

    // procura pelo baú ou por um loop no mapa
    while (1) {
        switch(x){
            case '>':
                pos_x++;
                break;
            case '<':
                pos_x--;
                break;
            case 'v':
                pos_y++;
                break;
            case '^':
                pos_y--;
                break;
            default:
            printf("erro");
            return '!';
            break;
        }

        // verificar se a posição existe no mapa
        if (pos_x >= largura || pos_y >= altura || pos_x < 0 || pos_y < 0)
            return '!';

        // verificar o ponto atual
        char ponto = mapa[pos_y][pos_x];
        switch (ponto){
        case '*':
            return '*';
        case '.':
            continue;
            break;
        case '>':
            x = '>';
            break;
        case '<':
            x =  '<';
            break;
        case 'v':
            x = 'v';
            break;
        case '^':
            x = '^';
            break;
        default:
            break;
        }
        // muda o valor do ponto
        mapa[pos_y][pos_x] = '.';
    }

    return '!';
}

int main()
{
    int largura, altura;
    char mapa[MAX_A][MAX_L];

    // Lê os valores inseridos pelo usuário
    scanf("%d", &largura);
    scanf("%d", &altura);
    for (int i = 0; i < altura; i++)
        scanf("%s", mapa[i]);

    //chama a função "verifica" para procurar no mapa
    char n = verifica(mapa, altura, largura);

    printf("%c\n", n);

    return 0;
}
