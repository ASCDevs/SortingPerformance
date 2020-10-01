
void merge(int *vetor,int inicio, int meio, int fim, int *vetorAux){
    
    int iEsquerdo = inicio;
    int iDireito = meio; 

    for (int i = inicio; i < fim ; i++){
        if(iEsquerdo < meio and ((iDireito >=fim) or (vetor[iEsquerdo] < vetor[iDireito]))){
            comparacoes++;
            movimentacoes++;
            vetorAux[i] = vetor[iEsquerdo];
            iEsquerdo++;
        }else{
            comparacoes++;
            movimentacoes++;
            vetorAux[i] = vetor[iDireito];
            iDireito++;
        }
    }

    for(int i=inicio;i<fim;i++){
        movimentacoes++;
        vetor[i] = vetorAux[i];
    }
    
}

void mergeSort(int vetor[], int inicio, int fim,int vetorAux[]){
    if(fim - inicio >1){
        comparacoes++;
        int meio = (fim+inicio)/2; 
        
        movimentacoes++;
        mergeSort(vetor,inicio,meio,vetorAux);
        movimentacoes++;
        mergeSort(vetor,meio,fim,vetorAux);
        movimentacoes++;
        merge(vetor,inicio,meio,fim,vetorAux);
    }
}

void mergeSort(int vetor[], int tamanho){

    int vetorAux[tamanho];
    mergeSort(vetor,0,tamanho,vetorAux);
}