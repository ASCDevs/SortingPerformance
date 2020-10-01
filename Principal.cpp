#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <new>

int comparacoes=0;
int movimentacoes=0;

#include "MergeSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "dados.h"

void menu();
void encaminhaOpcao(char op);

int main(){

    menu();

}

void menu(){

    char opcao;
    
    do{
        
        puts("------Performance-de-Ordenacao------");
        puts("1 - Testes Ordernacao");
        //puts("1 - Ordernar numeros digitados")
        //puts("2 - Ordenar vetores randomicos");
        //puts("3 - Ordenar vetores semi orndenados");
        //puts("4 - Ordenar vetores ja ordenado");
        puts("0 - Sair");
        scanf("%c",&opcao);

        encaminhaOpcao(opcao);
        
        system("cls||clear");

    }while(opcao!='0');

    puts("Saida do sistema\n");
    system("pause");
}

void encaminhaOpcao(char op){

    switch (op){
        case '1':
            system("cls||clear");
            menuTestesOrdenacao();
            break;
    }
}


void menuTestesOrdenacao(){

    char op;

    do{
        system("cls||clear");
        puts("1 - Digitar numeros");
        puts("2 - Ler arquivo txt");
        puts("3 - Dados randomicos (500 inteiros)");
        puts("4 - Dados randomicos (50000 inteiros)");
        puts("5 - Dados randomicos (100000 inteiros)");
        puts("6 - Digitar quantidade de numeros randomicos");
        puts("0 - Voltar");
        scanf("%c",&op);
        encaminhaOpcaoDados(op);

    }while(op!='0');
}

void encaminhaOpcaoDados(char op){

    switch (op){
        case '1':
            system("cls");
            lerEntradaUser();
            puts("");
            system("pause");
            break;
        case '2':
            system("cls");
            lerArquivo();
            system("pause");
            break;
        case '3':
            system("cls");
            geraVetor(vetorInt,500,"random");
            system("pause");
            break;
        case '4':
            system("cls");
            geraVetor(vetorInt,5000,"random");
            system("pause");
            break;
        case '5':
            system("cls");
            geraVetor(vetorInt,100000,"random");
            system("pause");
            break;
        case '6':
            system("cls");
            entradaUserRandom();
            system("pause");
            break;
    }
}