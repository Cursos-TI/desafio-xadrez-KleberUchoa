#include <stdio.h>
#include <stdlib.h>
void MoveTorre(int casas)
{
    if(casas > 0)
    {
        MoveTorre(casas - 1);
        printf("%dª casa à Direita\n", casas);
       
    }
}
void MoveDama(int casas)
{
    if(casas > 0)
    {
        MoveDama(casas - 1);
        printf("%dª casa à esquerda\n", casas);
    }
}
void MoveBispo(int casas)
{
    if(casas > 0)
    {
        MoveBispo(casas - 1);
        printf("%dª casa\n", casas);
        printf("Cima\n");
        printf("Direita\n");
    }
}
void MoveCavalo(int vezes)
{
    for(int i = 0; i < vezes; i++)
    {
        printf("%dº movimento\n", vezes);
        for(int j = 0; j < 2; j++)
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
    printf("Movendo o cavalo 1 vez: 2 casas para baixo e 1 casa a esquerda\n");
    MoveCavalo(1);
    return 0;

}



