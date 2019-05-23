//
//  main.c
//  Jogo do Bingo
//
//  Created by Marcos Rocha on 20/05/2019.
//  Copyright © 2019 Marcos Rocha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função clrscr: Limpar a tela do terminal*/
void clrscr()
{
    //Fiz isso para poder funcionar no Windows e Linux
    system("cls||clear");

}


void gerarPedras()
{
    getchar();
    int pedras[75] = { 0 };       //Array de pedras do jogo
    int ultimaPedra = 0;          //salvar a ultima pedra sorteada
    int qtdSorteada = 0;          //Contar quantas pedras já foram sorteadas
    int sair = 0;                 //Quando igual a 1 o sistema sai do Loop de Sorteio
    char caractereGet=0;          //Salvar o input do usuario
    int posicao=0;
    char letra = ' ';
    srand((unsigned)time(NULL));  //Uso isso para que o randon seja diferente a cada execução

    do
    {
        clrscr();

        /* Bloco para imprimir tablea*/
        printf("  ┌──────────────────────────────────────────────────────┐\n");
        printf("  │ ╔════════════════════════════════════════════════════╧═╗\n");
        printf("  │ ║     Ultima pedra: %c %02d          Qtd Sorteada: %02d     ║\n", letra, ultimaPedra, qtdSorteada);
        printf("  │ ╟──────────────────────────────────────────────────────╢\n");


        int i=0;
        for (i=0; i<75; i++)
        {
            if (i==0)
                printf("  │ ║  B |");

            if (pedras[i]==0)
            {
                printf("  |");
            }
            else
            {
                printf("%02d|", pedras[i]);
            }

            if (i==14)
                printf(" B  ║\n  │ ║  I |");

            if (i==29)
                printf(" I  ║\n  │ ║  N |");

            if (i==44)
                printf(" N  ║\n  │ ║  G |");

            if (i==59)
                printf(" G  ║\n  └─║  O |");

            if (i==74)
                printf(" O  ║\n");
        }
        printf("    ╚══════════════════════════════════════════════════════╝\n");
        /* Fim Block para Imprimir tabela*/

        printf("Pressione ENTER perar gerar uma nova pedra!\n");
        printf("Pressione S para sair!\n");

        //Pausa o sistema e fica esperando um comando do usuário
        caractereGet = getchar();

        //Verifica se o usuário quer sair ou se o sorteio terminou
        if ((caractereGet=='s') || (caractereGet=='S')|| qtdSorteada>=75)
            sair=1;

        posicao = rand() % (75-qtdSorteada);

        int j=0;
        for(j=0; j<=posicao; j++)
        {
            if (pedras[j]!=0)
            {
                posicao++;
            }

        }

        qtdSorteada++;
        ultimaPedra = posicao+1;
        pedras[posicao]= ultimaPedra;

        /* Bloco para identificar qual letra a ultima pedra saiu */
        if (ultimaPedra<=15)
            letra = 'B';

        if (ultimaPedra>15 && ultimaPedra<=30)
            letra = 'I';

        if (ultimaPedra>30 && ultimaPedra<=45)
            letra = 'N';

        if (ultimaPedra>45 && ultimaPedra<=60)
            letra = 'G';

        if (ultimaPedra>60)
            letra = 'O';

    }while(sair==0);
    printf("\n\nSorteio Encerrado!\n\n");
    printf("Pressione ENTER para continuar!\n");
    getchar();
}


void ordenaCrescente (int n, int v[])
{
    for (int j = 1; j < n; ++j) {
        int x = v[j];
        int i;
        for (i = j-1; i >= 0 && v[i] > x; --i)
            v[i+1] = v[i];
        v[i+1] = x;
    }
}


void gerarCartela(int pedras[])
{

    int qtdSorteada = 0;

    srand((unsigned)time(NULL)); //Uso isso para ele ficar aleatório de verdade

    clrscr();

    int i=0, j=0;
    int pedra=0;
    int igualdade = 0;

    for (i=0; i<5; i++)
    {
        do
        {
            igualdade = 0;
            pedra = (rand() % 15) + 1;
            for (j=0; j<5; j++)
                if (pedras[j]==pedra)
                    igualdade=1;

        }while(igualdade);
        qtdSorteada++;
        pedras[i] = pedra;
    }

    for (i=5; i<10; i++)
    {
        do
        {
            igualdade = 0;
            pedra = (rand() % 15) + 1 + 15;
            for (j=5; j<10; j++)
                if (pedras[j]==pedra)
                    igualdade=1;

        }while(igualdade);
        qtdSorteada++;
        pedras[i] = pedra;
    }

    for (i=10; i< 14; i++)
    {
        do
        {
            igualdade = 0;
            pedra = (rand() % 15) + 1 + 30;
            for (j=10; j<14; j++)
                if (pedras[j]==pedra)
                    igualdade=1;

        }while(igualdade);
        qtdSorteada++;
        pedras[i] = pedra;
    }

    for (i=14; i< 19; i++)
    {
        do
        {
            igualdade = 0;
            pedra = (rand() % 15) + 1 + 45;
            for (j=14; j<19; j++)
                if (pedras[j]==pedra)
                    igualdade=1;

        }while(igualdade);
        qtdSorteada++;
        pedras[i] = pedra;
    }

    for (i=19; i< 24; i++)
    {
        do
        {
            igualdade = 0;
            pedra = (rand() % 15) + 1 + 60;
            for (j=19; j<24; j++)
                if (pedras[j]==pedra)
                    igualdade=1;

        }while(igualdade);
        qtdSorteada++;
        pedras[i] = pedra;
    }


     /* Bloco para ordenar o vetor */
    ordenaCrescente(24, pedras);
}

void marcarPedra()
{
    getchar();
    int pedras[24] = { 0 };
    int marcada[24] = { 0 };
    gerarCartela(pedras);
    int ganhou=0;
    int key=0;
    int sair=0;

    do
    {
        clrscr();
        printf("\nDigite o número e pressione ENTER para marcar!\n");
        printf("\nDigite 0 para SAIR!\n");
        printf("  ┌──────────────────────────────────────┐\n");
        printf("  │ ╔════════════════════════════════════╧═╗\n");
        printf("  │ ║    B      I      N      G      O     ║\n");
        printf("  │ ╟──────────────────────────────────────╢\n");
        int i=0;
        int j=0;
        int contAux=0;
        for (i=0; i<5; i++)
        {
            for (j=0; j<25; j= j+5)
            {
                if (j==0)
                    printf("  │ ║ ");
                contAux++;
                int linha=0;

                if (j<15) //Após a coluna que possui centro, descontar uma casa.
                    linha = i;
                else
                    linha = i -1;

                if (j==10 && (i==3 || i==4)) //para os casos após o centro, a uma difença de indice
                    linha--;


                if (j==10 && i==2) //Caso seja o centro da cartela, faça isso
                    printf("|  ☺   ");
                else
                    if (marcada[j+linha]==1)
                        printf("| ▓%02d▓ ",pedras[j+linha]);
                    else
                        printf("|  %02d  ",pedras[j+linha]);

                if (j==20)
                    printf("| ║\n");
            }

        }
        if (ganhou==1)
            printf("  └─║   ***BINGOOOOO!! Você ganhou!!!***   ║\n");
        else
            printf("  └─║                                      ║\n");
        printf("    ╚══════════════════════════════════════╝\n");

        scanf("%d", &key);


        ganhou=1;

        for(i=0; i<25; i++)
        {
            if (pedras[i]==key)
            {
                if (marcada[i]==0)
                    marcada[i]=1;
                else
                    marcada[i]=0;
            }

            if (marcada[i]==0)
                ganhou=0;
        }


        if (key==0)
            sair=1;

    }while(!sair);

    printf("Pressione ENTER para continuar!");
    getchar();
}


int main(int argc, const char * argv[]) {
    while (1)
    {
      
        clrscr();

        //printf("Gerador de Pedras\n");
        //printf("Gerador de Cartela\n");
        printf("\n");
        printf("  ┌──────────────────────────────────────────────┐\n");
        printf("  │ ╔════════════════════════════════════════════╧═╗\n");
        printf("  │ ║                                              ║\n");
        printf("  │ ║    ██████╗ ██╗███╗   ██╗ ██████╗  ██████╗    ║\n");
        printf("  │ ║    ██╔══██╗██║████╗  ██║██╔════╝ ██╔═══██╗   ║\n");
        printf("  │ ║    ██████╔╝██║██╔██╗ ██║██║  ███╗██║   ██║   ║\n");
        printf("  │ ║    ██╔══██╗██║██║╚██╗██║██║   ██║██║   ██║   ║\n");
        printf("  │ ║    ██████╔╝██║██║ ╚████║╚██████╔╝╚██████╔╝   ║\n");
        printf("  │ ║    ╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚═════╝    ║\n");
        printf("  │ ║                                              ║\n");
        printf("  └─║      V. 1.0   -   2019   -   Marcos Rocha    ║\n");
        printf("    ╚══════════════════════════════════════════════╝\n");
        printf("\n");
        //printf("Pressione ENTER para começar!\n");
        printf("(1)Gerar Pedras;   (2)Gerar Cartela!\n");

        int key=0;
        scanf("%d", &key);

        switch(key)
        {
            case 1:
                gerarPedras();
            break;
            case 2:
                marcarPedra();
            break;
        }
    }
    return 0;
}

