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
void encaminhaOpcaoDoMenu(char op);
void encaminhaOpcaoGeral(char op, char tipo[]);
void menuGeralVetor(char tipoVetor[]);

int main(){

    menu();

}

void menu(){

    char opcao;
    
    do{
        
        puts("------Performance-de-Ordenacao------");
        puts("1 - Ordernar numeros digitados");
        puts("2 - Ordenar vetores randomicos");
        puts("3 - Ordenar vetores semi orndenados");
        puts("4 - Ordenar vetores ja ordenado");
        puts("0 - Sair");
        scanf("%c",&opcao);

        encaminhaOpcaoDoMenu(opcao);
        
        system("cls||clear");

    }while(opcao!='0');

    puts("Saida do sistema\n");
    system("pause");
}

void encaminhaOpcaoDoMenu(char op){

    switch (op){
        case '1':
            system("cls||clear");
            lerEntradaUser();
            puts("");
            system("pause");
            break;
        case '2':
            system("cls||clear");
            menuGeralVetor("randomicos");
            puts("");
            break;
        case '3':
            system("cls||clear");
            menuGeralVetor("semi ordenados");
            puts("");
            break;
        case '4':
            system("cls||clear");
            menuGeralVetor("ordenados");
            puts("");
            break;

    }
}

void menuGeralVetor(char tipoVetor[]){
    char op;
    do{
        system("cls||clear");
        printf("1 - Dados %s (20000 inteiros)",tipoVetor);
        printf("\n2 - Dados %s (60000 inteiros)",tipoVetor);
        printf("\n3 - Dados %s (120000 inteiros)",tipoVetor);
        printf("\n4 - Ordenar N quantidade de numeros %s",tipoVetor);
        puts("\n0 - Voltar");
        scanf("%c",&op);

        encaminhaOpcaoGeral(op,tipoVetor);

    }while(op!='0');
}

void encaminhaOpcaoGeral(char op, char tipo[]){

    switch (op){
        case '1':
            system("cls");
            geraVetor(vetorInt,20000,tipo);
            system("pause");
            break;
        case '2':
            system("cls");
            geraVetor(vetorInt,60000,tipo);
            system("pause");
            break;
        case '3':
            system("cls");
            geraVetor(vetorInt,120000,tipo);
            system("pause");
            break;
        case '4':
            system("cls");
            entradaUserRandom(tipo);
            system("pause");
            break;

    }
}