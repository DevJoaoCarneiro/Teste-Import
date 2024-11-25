/*Autor.... Joao Victor
  Data..... 18/11/24
  Objetivo. Exec sala*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define Max 30
#define tam 5

// Estrutura de variaveis do usuario
typedef struct
{
    char nome[Max];
    char sobrenome[Max];
    char endereco[Max];
    int num_endereco;
    float cpf;
} reg_cadastro;

// Função para manipular coordenadas

void gotoxy(int x, int y)

{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Funcao para limpar tela
void limpar(){
    int i;
    for(i=0; i<15;i++){
    gotoxy(2,05+i);
    printf("                                                                          ");
    }
}
// Funcao para cadastrar usuario
int cadastro_usu(reg_cadastro *usuarios, int *num)
{
    int i;
    int confirma;
    int reinicio;
    int menu;

    for (i = *num; i < tam; i++)
    {   *num = *num + 1;
        do
        {   limpar();
            
            gotoxy(20, 06);
            printf("Insira seu nome ...........");
            fflush(stdin);
            fgets(usuarios[i].nome, Max, stdin);

            gotoxy(20, 07);
            printf("Insira seu sobrenome ......");
            fflush(stdin);
            fgets(usuarios[i].sobrenome, Max, stdin);

            gotoxy(20, 8);
            printf("Insira seu endereco .......");
            fflush(stdin);
            fgets(usuarios[i].endereco, Max, stdin);

            gotoxy(20, 9);
            printf("Insira o numero ...........");
            scanf("%d", &usuarios[i].num_endereco);

            gotoxy(20, 10);
            printf("Insira o cpf  .............");
            scanf("%f", &usuarios[i].cpf);

            gotoxy(15, 11);
            printf("Confirmar cadastro (1-Sim 2-Nao)............");
            gotoxy(60, 11);
            scanf("%d", &confirma);

            if (confirma != 1)
            {   
                gotoxy(15, 14);
                printf("***** O Usuario nao foi cadastrado*****\n");
                gotoxy(15, 15);
                printf("===PRESSIONE UMA TECLA PARA CONTINUAR===\n");
                getch();
            }
        } while (confirma != 1);

        gotoxy(15, 12);
        printf("Cadastrar outro usuario? (1-Sim 2-Nao) .....");
        gotoxy(60, 12);
        scanf("%d", &reinicio);

        if (reinicio == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    gotoxy(15, 13);
    printf("Voltar ao menu ? (1-Sim 2-Nao) .............");
    gotoxy(60, 13);
    scanf("%d", &menu);

    return menu;
}

// Função para editar usuario cadastrado
int editar_usuarios(reg_cadastro *usuarios, int *num2)
{
    int i;
    int menu;
    int edit;
    int edituser;
    int att;

    for (i = 0; i < *num2; i++)
    {   
        
        printf("==== USUARIO %d ====\n", i + 1);
        printf("Nome .......... %s\n", usuarios[i].nome);
        printf("Sobrenome ..... %s\n", usuarios[i].sobrenome);
        printf("Endereco ...... %s Num-%d \n", usuarios[i].endereco, usuarios[i].num_endereco);
        printf("Cpf ........... %.2f\n", usuarios[i].cpf);
    }

    printf("\n");
    printf("========================================= \n");
    printf("Qual usario voce deseja editar.....\n");
    scanf("%d", &edit);

    system("cls");
    printf("==== USUARIO %d ====\n", edit);
    printf("1-Nome .......... %s\n", usuarios[edit - 1].nome);
    printf("2-Sobrenome ..... %s\n", usuarios[edit - 1].sobrenome);
    printf("3-Endereco ...... %s Num-%d \n", usuarios[edit - 1].endereco, usuarios[edit - 1].num_endereco);
    printf("4-Cpf ........... %.2f\n", usuarios[edit - 1].cpf);

    printf("Qual dado voce quer editar? .....");
    scanf("%d", &edituser);

    switch (edituser)
    {
    case 1:
        do
        {
            printf("1-Nome ..................... ");
            fflush(stdin);
            fgets(usuarios[edit - 1].nome, Max, stdin);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            scanf("%d", &att);
        } while (att != 1);
        getch();
        break;
    case 2:
        do
        {
            printf("2-Sobrenome ................ ");
            fflush(stdin);
            fgets(usuarios[edit - 1].sobrenome, Max, stdin);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            scanf("%d", &att);
        } while (att != 1);
        getch();
        break;
    case 3:
        do
        {
            printf("3-Endereco ................. ");
            fflush(stdin);
            fgets(usuarios[edit - 1].endereco, Max, stdin);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            scanf("%d", &att);
        } while (att != 1);
        getch();
        break;
    case 4:
        do
        {
            printf("4-Numero endereco .......... ");
            scanf("%d", &usuarios[edit - 1].num_endereco);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            scanf("%d", &att);
        } while (att != 1);
        getch();
        break;
    case 5:
        do
        {
            printf("5-Cpf ..................... ");
            scanf("%f", &usuarios[edit - 1].cpf);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            scanf("%d", &att);
        } while (att != 1);
        getch();
        break;
    default:
        printf("**Insira um numero valido**\n");
    }

    for (i = 0; i < *num2; i++)
    {
        printf("==== USUARIO %d ====\n", i + 1);
        printf("Nome .......... %s\n", usuarios[i].nome);
        printf("Sobrenome ..... %s\n", usuarios[i].sobrenome);
        printf("Endereco ...... %s Num-%d \n", usuarios[i].endereco, usuarios[i].num_endereco);
        printf("Cpf ........... %.2f\n", usuarios[i].cpf);
    }
    printf("Voltar ao menu ? (1-Sim 2-Nao)....");
    scanf("%d", &menu);
    return menu;
}

// Funcao que le usarios cadastrados
int ler_usuarios(reg_cadastro *usuarios, int *num2)
{
    int i;
    int menu;

    for (i = 0; i < *num2; i++)
    {
        printf("%d- %s %s", i+1, usuarios[i].nome, usuarios[i].sobrenome);
    }
    printf("Voltar ao menu ? (1-Sim 2-Nao)....");
    scanf("%d", &menu);
    return menu;
}


// Funcao com menu principal
int layout()
{
    int escolha;

    gotoxy(25, 06);
    printf("=== MENU DE OPCAO ===\n");
    gotoxy(25, 10);
    printf("1- Cadastrar usuario\n");
    gotoxy(25, 11);
    printf("2- Consultar usuarios\n");
    gotoxy(25, 12);
    printf("3- Editar cadastro usario\n");
    gotoxy(25, 13);
    printf("4- Sair\n");
    gotoxy(25, 16);
    printf("Insira sua resposta .....");
    gotoxy(51, 16);
    scanf("%d", &escolha);
    system("cls");
    switch (escolha)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    default:
        return 5;
    }
}

// Tela Padrao

void tela()

{
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
    int resposta;
    int cadastro;
    int *ponteiro;
    int contagem = 0;

    ponteiro = &contagem;
    reg_cadastro usuarios[tam];

    do
    {
        tela();
        resposta = layout();

        switch (resposta)
        {
        case 1:
            tela();
            cadastro = cadastro_usu(usuarios, ponteiro);
            break;
        case 2:
            tela();
            cadastro = ler_usuarios(usuarios, ponteiro);
            break;
        case 3:
            tela();
            cadastro = editar_usuarios(usuarios, ponteiro);
            break;
        }

    } while (cadastro == 1);
    return 0;
}