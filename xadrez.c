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
            //printf("Movimento da Torre: %d, %d\n", x, ny);
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
                //printf("Movimento da Torre: %d, %d\n", nx, y);
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
                    //printf("Movimento do bispo: %d, %d\n", nx, ny);
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
                //printf("Movimento da Dama: %d, %d\n", x, ny);
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
                //printf("Movimento da Dama: %d, %d\n", nx, y);
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
                    //printf("Movimento da dama: %d, %d\n", nx, ny);
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
void MoverTorre(int fromX, int fromY, int toX, int toY)
{
    if(tabuleiro[fromX][fromY] == torre)
    {
        int isValidMove = 0;
        for(int i = 0; i < contaMovimentosTorre; i++)
        {
            if(movimentosDaTorre[i][0] == toX && movimentosDaTorre[i][1] == toY)
            {
                tabuleiro[toX][toY] = torre;
                tabuleiro[fromX][fromY] = '*';
                isValidMove = 1;
            }
        }
        if(isValidMove == 0)
        {
            printf("Movimento Inválido!\n");
        }
    }
    else{
        printf("A peça que está tentando movimentar não é uma Torre!\n");
    }
}
void MoverBispo(int fromX, int fromY, int toX, int toY)
{
    if(tabuleiro[fromX][fromY] == bispo)
    {
        int isValidMove = 0;
        for(int i = 0; i < contaMovimentosBispo; i++)
        {
            if(movimentosDoBispo[i][0] == toX && movimentosDoBispo[i][1] == toY)
            {
                tabuleiro[toX][toY] = bispo;
                tabuleiro[fromX][fromY] = '*';
                isValidMove = 1;
            }
        }
        if(isValidMove == 0)
        {
            printf("Movimento Inválido!\n");
        }
    }
    else{
        printf("A peça que está tentando movimentar não é um Bispo!\n");
    }
}
void MoverDama(int fromX, int fromY, int toX, int toY)
{
    if(tabuleiro[fromX][fromY] == dama)
    {
        int isValidMove = 0;
        for(int i = 0; i < contaMovimentosDama; i++)
        {
            if(movimentosDaDama[i][0] == toX && movimentosDaDama[i][1] == toY)
            {
                tabuleiro[toX][toY] = dama;
                tabuleiro[fromX][fromY] = '*';
                isValidMove = 1;
            }
        }
        if(isValidMove == 0)
        {
            printf("Movimento Inválido!\n");
        }
    }
    else{
        printf("A peça que está tentando movimentar não é uma Dama!\n");
    }
}
int main() {
    printf("Movendo a torre!\n");
    IniciaTabuleiro();
    //Posição inicial
    tabuleiro[0][0] = torre;
    ImprimeTabuleiro();
   
    printf("À Direita - 8 casas:");
    PegarMovimentosDaTorre(0, 0); //pegando movimentos válidos da torre
    MoverTorre(0, 0, 7, 0); //posição 0,0 para a posição 7,0, se o movimento for válido
    ImprimeTabuleiro();

    printf("Movendo o bispo!\n");
    IniciaTabuleiro();
    tabuleiro[0][0] = bispo;
    ImprimeTabuleiro();
    
    printf("Para Cima à Direita - 5 Casas\n"); 
    PegarMovimentoDoBispo(0, 0);
    MoverBispo(0, 0, 5, 5); //posição 0,0 para a posição 5,5
    ImprimeTabuleiro();
    
    printf("Movendo a Dama!\n");
    IniciaTabuleiro();
    tabuleiro[7][0] = dama;
    ImprimeTabuleiro();

    printf("À Esquerda - 8 casas\n");
    PegarMovimentoDaDama(7, 0);
    MoverDama(7, 0, 0, 0);
    ImprimeTabuleiro();
    return 0;
}




