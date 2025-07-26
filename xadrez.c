#include <stdio.h>

char tabuleiro[8][8];
char dama = 'D';
char torre = 'T';
char bispo = 'B';

int movimentosDaTorre[14][2];
int contaMovimentosTorre = 0;

void PegarMovimentosDaTorre(int x, int y)
{
    int direcao[2] = {-1, 1};
    for(int i = 0; i < 2; i++)
    {
        for(int j = x + direcao[i]; j >= 0 && j < 8; j += direcao[i])
        {
                if(tabuleiro[j][y] == '*')
                {
                    movimentosDaTorre[contaMovimentosTorre][0] = j;
                    movimentosDaTorre[contaMovimentosTorre][1] = y;
                    printf("Movimento da Torre: %d, %d\n", x, j);
                    contaMovimentosTorre++;
                }else{
                    break;
                }
        }
        for(int j = y + direcao[i]; j >= 0 && j < 8; j += direcao[i])
        {
                if(tabuleiro[x][j] == '*')
                {
                    movimentosDaTorre[contaMovimentosTorre][0] = x;
                    movimentosDaTorre[contaMovimentosTorre][1] = j;
                    printf("Movimento da Torre: %d, %d\n", j, y);
                    contaMovimentosTorre++;
                }
                else{
                    break;
                }
        }
    }   
}
int movimentosDoBispo[14][2];
int contaMovimentosBispo = 0;

void PegarMovimentoDoBispo(int x, int y)
{
    int direcao[2] = {-1, 1};
    for(int i = 0; i < 2; i++)
    {
        //Movimentos na diagonal
        for(int j = x + direcao[i]; j >= 0 && j < 8; j += direcao[i])
        {
            for(int k = y + direcao[i]; k >= 0 && k < 8; k += direcao[i])
            {
                if(tabuleiro[j][k] == '*')
                {
                    movimentosDoBispo[contaMovimentosBispo][0] = j;
                    movimentosDoBispo[contaMovimentosBispo][1] = k;
                    printf("Movimento do bispo: %d, %d\n", j, k);
                    contaMovimentosBispo++;
                }
                else{
                    break;
                }
            }
        }
    }

}
int movimentosDaDama[28][2];
int contaMovimentosDama = 0;

void PegarMovimentoDaDama(int x, int y)
{
    int direcao[2] = {-1, 1};
    for(int i = 0; i < 2; i++)
    {
        for(int j = x + direcao[i]; j >= 0 && j < 8; j += direcao[i])
        {
                if(tabuleiro[j][y] == '*')
                {
                    movimentosDaDama[contaMovimentosDama][0] = j;
                    movimentosDaDama[contaMovimentosDama][1] = y;
                    printf("Movimento da dama: %d, %d\n", j, y);
                    contaMovimentosDama++;
                }else{
                    break;
                }
        }
        for(int j = y + direcao[i]; j >= 0 && j < 8; j += direcao[i])
        {
                if(tabuleiro[x][j] == '*')
                {
                    movimentosDaDama[contaMovimentosDama][0] = x;
                    movimentosDaDama[contaMovimentosDama][1] = j;
                    printf("Movimento da dama: %d, %d\n", x, j);
                    contaMovimentosDama++;
                }
                else{
                    break;
                }
        }
        for(int j = x + direcao[i]; j >= 0 && j < 8; j += direcao[i])
        {
            for(int k = y + direcao[i]; k >= 0 && k < 8; k += direcao[i])
            {
                if(tabuleiro[j][k] == '*')
                {
                    movimentosDaDama[contaMovimentosDama][0] = j;
                    movimentosDaDama[contaMovimentosDama][1] = k;
                    printf("Movimento da dama: %d, %d\n", j, k);
                    contaMovimentosDama++;
                }
                else{
                    break;
                }
            }
        }
    }

}

void IniciaTabuleiro()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            tabuleiro[i][j] = '*';
        }
    }

}
void ImprimeTabuleiro()
{
    for(int i = 7; i >= 0; i--)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%c", tabuleiro[i][j]);
        }
        printf("\n");
    }

}

int main() {
    IniciaTabuleiro();
    //Posição inicial
    tabuleiro[0][0] = torre;
    tabuleiro[0][2] = bispo;
    tabuleiro[0][3] = dama;
    ImprimeTabuleiro();
    PegarMovimentosDaTorre(0, 0);
    PegarMovimentoDoBispo(2, 0);
    PegarMovimentoDaDama(3, 0);
    
    return 0;
}




