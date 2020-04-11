#include <iostream>
#include <stdlib.h>
using namespace std;

//Variáveis
string Titulo = "<<<< JOGO DA VELHA >>>>\n\n";
int Continuar;
const int Tam=11, pos = 3;//
char Mapa[Tam][Tam];
char tabuleiro [pos][pos];
char vazio=' ';
char cerquilha='#';
char jogador1='O', jogador2='X';
bool gameOver;
int jogadorAtual=1;
int Jogada;
bool jogadaValida;
int ganhou=false;
int NumeroDeJogadas=0;
char A, B, C, D, E, F, G,H;

void menu()
{
    //Desenhando o título
    cout<<Titulo;
    //Especificação dos jogadores
    cout<<"Jogador 1: O\t";
    cout<<"Jogador 2: X\n\n";
    //Confirmação de continuação
    cout<<"Digite 1 para continuar ou 0 para sair...";
    cin>>Continuar;

}

void inicializar()
{
    //Tabuleiro
    for (int i=0;i<Tam;i++)
    {
        for(int j=0;j<Tam;j++)
        {
            tabuleiro[j]=vazio;
        }
    }


    //Mapa
    for (int i=0;i<Tam;i++)
    {
        for(int j=0;j<Tam;j++)
        {
            //Espaços
            Mapa[j]=vazio;

            //cerquilha

            if((i==3)||(i==7)||(j==3)||(j==7))
                Mapa[j] = cerquilha;
        }
    }
}

void desenharJogo()
{

    system("cls");

    //Desenhar título
    cout<<Titulo;

    //Desenhar tabuleiro
    for(int i=0;i<Tam;i++)
    {
        for(int j=0;j<Tam;j++)
        {
            cout<<Mapa[j]<<" ";
        }
        cout<<endl;
    }

    //Pedir comando
    cout<<"\nJogador da Rodada: ";
    if(jogadorAtual == 1)
        cout<<"O"<<endl;
    else
        cout<<"X"<<endl;

    cout<<"Jogada: ";
    cin>>Jogada;

    while(Jogada/10<0 || Jogada/10>=4 || Jogada%10<0 || Jogada%10>=4 || tabuleiro[(Jogada/10)-1][(Jogada%10)-1]!=vazio)
    {
        cout<<"Jogada invalida. Tente novamente: ";
        cin>>Jogada;
    }
    jogadaValida=true;
    //NumeroDeJogadas++;
}

void comando()
{
    //Preenchimento do tabuleiro
    cout<<"\nJogador da Rodada: ";
    if(jogadorAtual == 1)
        tabuleiro[Jogada/10-1][Jogada%10-1]='O';
    else
        tabuleiro[Jogada/10-1][Jogada%10-1]='X';


    //Preenchimento do Mapa
    for(int i=0; i<pos; i++)
    {
        for(int j=0; j<pos; j++)
        {
            Mapa[1+4*i][1+4*j]=tabuleiro[j];
        }
    }

    jogadorAtual = jogadorAtual*(-1);
}

void ganhador()
{
    A=((tabuleiro[0][0]==tabuleiro[0][1])&&(tabuleiro[0][1]==tabuleiro[0][2])&&(tabuleiro[0][0]!=vazio));
    B=((tabuleiro[1][0]==tabuleiro[1][1])&&(tabuleiro[1][1]==tabuleiro[1][2])&&(tabuleiro[1][0]!=vazio));
    C=((tabuleiro[2][0]==tabuleiro[2][1])&&(tabuleiro[2][1]==tabuleiro[2][2])&&(tabuleiro[2][0]!=vazio));
    D=((tabuleiro[0][0]==tabuleiro[1][0])&&(tabuleiro[1][0]==tabuleiro[2][0])&&(tabuleiro[0][0]!=vazio));
    E=((tabuleiro[0][1]==tabuleiro[1][1])&&(tabuleiro[1][1]==tabuleiro[2][1])&&(tabuleiro[0][1]!=vazio));
    F=((tabuleiro[0][2]==tabuleiro[1][2])&&(tabuleiro[1][2]==tabuleiro[2][2])&&(tabuleiro[0][2]!=vazio));
    G=((tabuleiro[0][0]==tabuleiro[1][1])&&(tabuleiro[1][1]==tabuleiro[2][2])&&(tabuleiro[0][0]!=vazio));
    H=((tabuleiro[0][2]==tabuleiro[1][1])&&(tabuleiro[1][1]==tabuleiro[2][0])&&(tabuleiro[0][2]!=vazio));

    //verificando o ganhador na horizontal
    if (A)
    {
        gameOver=true;
    }
    else if (B)
    {
        gameOver=true;
    }
    else if (C)
    {
        gameOver=true;
    }

    //verificando ganhador na vertical
    if(D)
    {
        gameOver = true;
    }
    else if(E)
    {
        gameOver = true;
    }
    else if(F)
    {
        gameOver = true;
    }

    //verificando ganhador na diagonal
    if(G)
    {
        gameOver=true;
    }
    else if(H)
    {
        gameOver = true;
    }

    //verificando se deu velha
    if (NumeroDeJogadas==9 && !(A)&&!(B)&&!(C)&&!(D)&&!(E)&&!(F)&&!(G)&&!(H))
    {
            gameOver = true;
            cout<<"Deu Velha \n";

    }
    if(NumeroDeJogadas%2!=0)
        {
           cout<<"Jogador 1 venceu";
        }
        else
        {
            cout<<"Jogador 2 venceu";
        }

}

void jogo()
{
    inicializar();
    NumeroDeJogadas=0;
    while(!(gameOver))
    {
        desenharJogo();
        comando();
        NumeroDeJogadas++;
        ganhador ();
    }

}

int main ()
{
    system("color e2");
    menu();//Função para desenhar o menu

    if(Continuar==0)
        return 0;


    jogo();
    char novo;
    while (novo!='n')
    {
        cout<<"\nDigite 's' para jogar novamente e 'n' para finalizar o jogo ";
        cin>>novo;
        if(novo=='s')
           {
               jogo();
           }
    }
} 