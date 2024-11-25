/*Autor..... Joao Victor
  Data...... 12/11/24
  Objetivo.. Exercicio em sala*/

#include <stdio.h>
#include <windows.h>
#define Max 30

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct habitantes
{
    char nome[50];
    float salario;
    int num_filhos;

} reg_habitantes;

void ler_usuarios(reg_habitantes usuarios[], int num_user, int test)
{
    int i;
    num_user = test;
    if (num_user > 0)
    {
        for (i = 0; i < num_user; i++)
        {
            printf("Nome ............. %s ", usuarios[i].nome);
            printf("Salario .......... %.2f \n", usuarios[i].salario);
            printf("Numero filhos .... %d \n", usuarios[i].num_filhos);
        }
    }
    else
    {
        printf("Nenhum dado cadastrado");
    }
}

int layout()
{
    int escolha;
    system("cls");
    gotoxy(10, 10);
    printf("**MENU DE OPCOES**");
    gotoxy(10, 12);
    printf("1- Cadastrar usuario");
    gotoxy(10, 14);
    printf("2- Visualizar usuarios cadastrados");
    gotoxy(10, 16);
    printf("3- Sair");
    gotoxy(10, 18);
    printf("Insira sua resposta...");
    gotoxy(33, 18);
    scanf("%d", &escolha);
    return escolha;
}

void cadastro_usu(reg_habitantes *usuario, int contagem)
{
    int i;
    int contagem = 0;
    int confirma;
    int repetir;

    do
    {
        for (i = contagem; i < Max; i++)
        {   contagem++;
            gotoxy(10, 10);
            printf("Nome ..................................");
            gotoxy(50, 10);
            fflush(stdin);
            fgets(usuario[i].nome, 50, stdin);
            gotoxy(10, 12);
            printf("Salario ...............................");
            gotoxy(50, 12);
            scanf("%f", &usuario[i].salario);
            gotoxy(10, 14);
            printf("Numero de filho .......................");
            gotoxy(50, 14);
            scanf("%d", &usuario[i].num_filhos);
            gotoxy(10, 16);
            printf("Confirmar cadastro (1-Sim 2-Nao) ......");
            gotoxy(50, 16);
            scanf("%d", &confirma);

            gotoxy(10, 18);
            printf("Cadastrar outro usuario (1-Sim 2 Nao)..");
            gotoxy(50, 18);
            scanf("%d", &repetir);
        }
    }while (repetir==1);
}

void limpar()
{

    gotoxy(50, 10);
    printf("                     ");
    gotoxy(50, 12);
    printf("                     ");
    gotoxy(50, 14);
    printf("                     ");
    gotoxy(50, 16);
    printf("                     ");
    gotoxy(50, 18);
    printf("                     ");
}

int main()
{
    int escolha;
    int menu;

    reg_habitantes usuario[Max];

    do
    {

        escolha = layout();
        system("cls");

        switch (escolha)
        {
        case 1:
            cadastro_usu(&usuario);
            break;

        case 2:
            ler_usuarios(usuario, Max);
            gotoxy(10, 18);
            printf("Voltar ao menu (1-Sim 2-Nao).....");
            gotoxy(33, 18);
            scanf("%d", &menu);
            break;

        default:
            return 0;
        }
    } while (menu == 1);
    return 0;
}