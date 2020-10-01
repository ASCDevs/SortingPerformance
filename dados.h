#include <time.h>
#include <stdio.h>

int *vetorIntP; //500
int *vetorIntM; //50000
int *vetorIntG; //100000

//Declaracao das funcoes
void encaminhaOpcaoVetor(char escolha);
void menuVetoresVariados();
void geraVetor(int vetor[],int tamanho,char tipoEntrada[]);

void entradaUserRandom();
void lerEntradaUser();
void lerArquivo();
void menuTestesOrdenacao();
void encaminhaOpcaoDados(char op);
void salvaResultados(int vetor[], int tamanho, int tipo);

int randomNumeros(int vetor[],int tamanho);

struct relatorio {
	int quantidade;
    float tMerge;
	float tQuick;
	float tShell;
	int movMerge;
	int movQuick;
	int movShell;
	int comparaMerge; 
	int comparaQuick;
	int comparaShell;
};

void gerarRelatorio(relatorio relatorioDados);

void lerArquivo(){

    FILE *arquivo;
    arquivo = fopen("arquivo.txt","r");
    if(arquivo==NULL){
        printf("\nErro ao abrir arquivo!\n");
        system("pause");
    }else{
        printf("\nArquivo Aberto.");

        int qtdItens = 0;

        //Conta quantidade de linhas 
        int n;
        while(fscanf(arquivo,"%d\n",&n)==1){
            qtdItens++;
            printf("\n%d",n);
        }

        int vetorArquivo[qtdItens];

        puts("\n-------");
        int i =0;
        while(!feof(arquivo)){
            
            fscanf(arquivo,"%d\n",&vetorArquivo[i]);
            printf("\n%d",vetorArquivo[i]);
            i++;
        }

        printf("\nQuantidade: %d\n",qtdItens);
        
        fclose(arquivo);
        printf("\nArquivo Fechado.");
    }
}

void lerEntradaUser(){

    int tamanho;

    printf("\nQuantidade de numeros: ");
    scanf("%d",&tamanho);
    int *nums;
    
    geraVetor(nums,tamanho,"user");

}

void entradaUserRandom(){

    int tamanho;
    printf("Quantidade de numeros randomicos: ");
    scanf("%d",&tamanho);
    int *nums;

    geraVetor(nums,tamanho,"userRandom");
}

void geraVetor(int vetor[],int tamanho, char tipoEntrada[]){

    int tamanhoExibicao;
    //Verifica se é entrada por usuario ou randomico
    if(tipoEntrada == "random"){

        vetor = (int* )malloc(tamanho * sizeof(int));
        
        randomNumeros(vetor,tamanho);
        printf("RESULTADO DE VALORES RANDOMICOS - tamanho vetor: %d",tamanho);

        tamanhoExibicao = 500;
    }else if(tipoEntrada == "user"){
        vetor = (int* )malloc(tamanho * sizeof(int));
        
        for(int i=0;i<tamanho;i++){
            printf("\nNumero: ");
            scanf("%d",&vetor[i]);
        }
        system("cls");
        printf("RESULTADO DE ENTRADA PELO USUARIO - tamanho vetor: %d",tamanho);
        tamanhoExibicao = tamanho;
    }else if(tipoEntrada == "userRandom"){
        system("cls");
        vetor = (int* )malloc(tamanho * sizeof(int));
        randomNumeros(vetor,tamanho);
        printf("RESULTADO DE ENTRADA PELO USUARIO (RANDOMICO) - tamanho vetor: %d",tamanho);
        if(tamanho>=300){
            tamanhoExibicao = 300;
        }else{
            tamanhoExibicao = tamanho;
        }
    }
    

    //declara variaveis de tempo
    clock_t tMerge,tQuick,tShell;

    //variaveis de comparacoes
    int comparaMerge,comparaQuick,comparaShell;

    //variaveis de movimentacoes
    int movMerge,movQuick,movShell;

    //declara vetores auxiliares
    int vMerge[tamanho];
    int vQuick[tamanho];
    int vShell[tamanho];

    //Copia o vetor para os vetores auxiliares
    for(int i=0;i<tamanho;i++){
        vMerge[i] = vetor[i];
        vQuick[i] = vetor[i];
        vShell[i] = vetor[i];
    }
    
    //Marca os tempos e chama os métodos de ordenação
    tMerge = clock();
    mergeSort(vMerge,tamanho);
    tMerge = clock() - tMerge;
    comparaMerge = comparacoes;
    movMerge = movimentacoes;
    comparacoes = 0;
    movimentacoes = 0;

    tQuick = clock();
    quickSort(vQuick,0,tamanho-1);
    tQuick = clock() - tQuick;
    comparaQuick = comparacoes;
    movQuick = movimentacoes;
    comparacoes=0;
    movimentacoes=0;
    
    tShell = clock();
    shellSort(vShell,tamanho);
    tShell = clock() - tShell;
    comparaShell = comparacoes;
    movShell = movimentacoes;
    comparacoes = 0;
    movimentacoes = 0;
    
    float tempoMerge = ((double)tMerge/CLOCKS_PER_SEC);
    float tempoQuick = ((double)tQuick/CLOCKS_PER_SEC);
    float tempoShell = ((double)tShell/CLOCKS_PER_SEC);
    
    //Formata e exibe saída
    printf("\n-----------------------------------------------------------");
    printf("\nDesordenado      Merge Sort      Quick Sort      Shell Sort");
    for(int i=0;i<tamanhoExibicao;i++){
        printf("\n%11d%16d%16d%16d",vetor[i],vMerge[i],vQuick[i],vShell[i]);
    }
    
    salvaResultados(vMerge, tamanho, 1);
    salvaResultados(vQuick, tamanho, 2);
    salvaResultados(vShell, tamanho, 3);
    
    printf("\n-----------------------------------------------------------");
    printf("\nTempos de\nordenacao:%16fs%15fs%15fs", tempoMerge, tempoQuick, tempoShell);
    printf("\nComparacoes:%15d%16d%16d",comparaMerge,comparaQuick,comparaShell);
    printf("\nMovimentacoes:%13d%16d%16d",movMerge,movQuick,movShell);
    printf("\n\nObs: O tempo de ordenacao pode n aparecer devido\nao metodo estar preparado para lidar com\nvetores pequenos ou grandes.\n");
    //Funcionalidade de gerar um arquivo com os resultados
    //Perguntar se deseja exibir mais resultados
    
    
    // Colocando Dados no Relatorio
    relatorio relatorioDados;
    
    relatorioDados.quantidade = tamanho;
    
    relatorioDados.tMerge = tempoMerge;
	relatorioDados.tQuick = tempoQuick;
	relatorioDados.tShell = tempoShell;
	
	relatorioDados.movMerge = movMerge;
	relatorioDados.movQuick = movQuick;
	relatorioDados.movShell = movShell;
	
	relatorioDados.comparaMerge = comparaMerge; 
	relatorioDados.comparaQuick = comparaQuick;
	relatorioDados.comparaShell = comparaShell;
    
    gerarRelatorio(relatorioDados);
    
    free(vetor);
}


void gerarRelatorio(relatorio relatorioDados) {
	
	FILE *arquivo;
    arquivo = fopen("report/dataReport.json","w");
    
    fprintf(arquivo, "dataReport = {\n");
    fprintf(arquivo, "quantidade: %d,\n", relatorioDados.quantidade);
    fprintf(arquivo, "tempos: {'tempoMerge': %f, 'tempoQuick': %f, 'tempoShell': %f},\n ", relatorioDados.tMerge, relatorioDados.tQuick, relatorioDados.tShell);
    fprintf(arquivo, "movimentacoes: { 'movMerge': %d, 'movQuick': %d, 'movShell': %d},\n", relatorioDados.movMerge, relatorioDados.movQuick, relatorioDados.movShell);
    fprintf(arquivo, "comparacoes: { 'compMerge': %d, 'compQuick': %d, 'compShell': %d}\n ", relatorioDados.comparaMerge, relatorioDados.comparaQuick, relatorioDados.comparaShell);
	fprintf(arquivo, "}");
	
    
    fclose(arquivo);
	
}

void salvaResultados(int vetor[], int tamanho, int tipo){
	if(tipo == 1){
		FILE *merge;
		merge = fopen("arquivos/merge.txt","w");
		int i;
		
		for(i = 0; i < tamanho;i++){
			fprintf(merge,"\n%d",vetor[i]);
		}
		
		fclose(merge);
	}
	if(tipo == 2){
		FILE *quick;
		quick = fopen("arquivos/quick.txt","w");
		
		int i;
		for(i = 0; i < tamanho;i++){
			fprintf(quick,"\n%d",vetor[i]);
		}
		
		fclose(quick);
	} else{
		FILE *shell;
		shell = fopen("arquivos/shell.txt","w");
		
		int i;
		for(i = 0; i < tamanho;i++){
			fprintf(shell,"\n%d",vetor[i]);
		}
		
		fclose(shell);
	}
}


int randomNumeros(int vetor[], int tamanho){
    srand((unsigned)time(NULL));
   
    for(int i=0;i<tamanho;i++){
        vetor[i] = rand()%1000 +1; // de 1 a 100    
    }
}
