/*Autor.... Joao Victor
  Data..... 18/11/24
  Objetivo. Exec sala*/

#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)

{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void limpar (){
    int i;
    for(i=0; i<15;i++){
    gotoxy(2,05+i);
    printf("                                                                          ");
    }
}

void tela (){
    int i;
    system("cls");
    printf("===============================================================================\n");
    for (i = 0; i < 22; i++)
    {
        printf("|                                                                             |\n");
    }
    printf("===============================================================================\n");
    gotoxy(30, 02);
    printf("*EXERCICIO 8*");
    gotoxy(01, 01);
    printf("Autor.......Joao Carneiro");
    gotoxy(01, 02);
    printf("Faculdade...UNICV");
    gotoxy(01, 03);
    printf("Ano.........2024");
    gotoxy(00, 04);
    printf("===============================================================================\n");
    gotoxy(00, 20);
    printf("===============================================================================\n");
    gotoxy(01, 21);
    printf("Reiniciar o programa (1-Sim 2-Nao).......");
}
int main()
{
   tela();
   gotoxy(12,12);
   printf("MAMAADSADASDASDAD");
   gotoxy(12,13);
   printf("MAMAADSADASDASDAD");
   gotoxy(12,14);
   printf("MAMAADSADASDASDAD");
   gotoxy(12,15);
   printf("MAMAADSADASDASDAD");
   gotoxy(12,16);
   printf("MAMAADSADASDASDAD");
   limpar();
gotoxy(12,30);
    return 0;
}