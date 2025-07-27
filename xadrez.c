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
        //Movimento pela coluna
        int ny = y + direcao[i];
        while (ny >= 0 && ny < 8)
        {
            if(tabuleiro[x][ny] == '*')
            {
            movimentosDaTorre[contaMovimentosTorre][0] = x;
            movimentosDaTorre[contaMovimentosTorre][1] = ny;
            contaMovimentosTorre++;
            printf("Movimento da Torre: %d, %d\n", x, ny);
            }
            else break; 
            ny += direcao[i];
        }
        //Movimento pela linha
        int nx = x + direcao[i];
        while (nx >= 0 && nx < 8)
        {
            if(tabuleiro[nx][y] == '*')
            {
                movimentosDaTorre[contaMovimentosTorre][0] = nx;
                movimentosDaTorre[contaMovimentosTorre][1] = y;
                contaMovimentosTorre++;
                printf("Movimento da Torre: %d, %d\n", nx, y);
            } else break; 
            nx += direcao[i];
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
        for(int j = 0; j < 2; j++)
        {
            int dx = direcao[i];
            int dy = direcao[j];
            int nx = x + dx;
            int ny = y + dy; 
            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
            {
                if(tabuleiro[nx][ny] == '*')
                {
                    movimentosDoBispo[contaMovimentosBispo][0] = nx;
                    movimentosDoBispo[contaMovimentosBispo][1] = ny;
                    printf("Movimento do bispo: %d, %d\n", nx, ny);
                    contaMovimentosBispo++;
                } else break;
                ny += dy;
                nx += dx;
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
         //Movimento pela coluna
        int ny = y + direcao[i];
        while (ny >= 0 && ny < 8)
        {
            if(tabuleiro[x][ny] == '*')
            {
                movimentosDaDama[contaMovimentosDama][0] = x;
                movimentosDaDama[contaMovimentosDama][1] = ny;
                contaMovimentosDama++;
                printf("Movimento da Dama: %d, %d\n", x, ny);
            }
            else break; 
            ny += direcao[i];
        }
        //Movimento pela linha
        int nx = x + direcao[i];
        while (nx >= 0 && nx < 8)
        {
            if(tabuleiro[nx][y] == '*')
            {
                movimentosDaDama[contaMovimentosDama][0] = nx;
                movimentosDaDama[contaMovimentosDama][1] = y;
                contaMovimentosDama++;
                printf("Movimento da Dama: %d, %d\n", nx, y);
            } else break; 
            nx += direcao[i];
        }
        nx = x + direcao[i];
        ny = y + direcao[i];
        //Movimentos na diagonal
        for(int j = 0; j < 2; j++)
        {
            int dx = direcao[i];
            int dy = direcao[j];
            int nx = x + dx;
            int ny = y + dy; 
            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
            {
                if(tabuleiro[nx][ny] == '*')
                {
                    movimentosDaDama[contaMovimentosDama][0] = nx;
                    movimentosDaDama[contaMovimentosDama][1] = ny;
                    printf("Movimento da dama: %d, %d\n", nx, ny);
                    contaMovimentosDama++;
                } else break;
                ny += dy;
                nx += dx;
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
            printf("%c", tabuleiro[j][i]);
        }
        printf("\n");
    }

}

int main() {
    IniciaTabuleiro();
    //Posição inicial
    tabuleiro[0][0] = torre;
    tabuleiro[2][0] = bispo;
    tabuleiro[3][0] = dama;
    ImprimeTabuleiro();
    PegarMovimentosDaTorre(0, 0);
    PegarMovimentoDoBispo(2, 0);
    PegarMovimentoDaDama(3, 0);
    
    return 0;
}




