#include <stdio.h>
#include <stdlib.h>
void MoveTorre(int casas)
{
    if(casas > 0)
    {
        printf("Direita\n");
        MoveTorre(casas - 1);
    }
}
void MoveDama(int casas)
{
    if(casas > 0)
    {
        printf("Esquerda\n");
        MoveDama(casas - 1);
    }
}
void MoveBispo(int casas)
{
    if(casas > 0)
    {
        printf("Cima\n");
        printf("Direita\n");
        MoveBispo(casas - 1);
    }
}
void MoveCavalo(int vezes)
{
    for(int i = 0; i < vezes; i++)
    {
        printf("Baixo\n");
        printf("Baixo\n");
        printf("Esquerda\n");
    }
}

int main()
{

    printf("Movendo a torre 8 casas à direita\n");
    MoveTorre(8);
    printf("Movendo a dama 8 casas à esquerda\n");
    MoveDama(8);
    printf("Movendo o bispo 5 casas para cima e à direita\n");
    MoveBispo(5);
    printf("Movendo o cavalo 1 vez para 2 casas para baixa e 1 casa a esquerda\n");
    MoveCavalo(1);
    return 0;

}



