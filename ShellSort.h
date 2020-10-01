void shellSort(int *vetor, int tamanho){
    int h = 1;
    
    while(h < tamanho){
        comparacoes++;
        h = h * 3 + 1;
    }

    h = h/3;
    int c, j;

    while (h > 0){
        comparacoes++;
        for(int i=h;i<tamanho;i++){
            c = vetor[i];
            j = i;
            while (j>=h && vetor[j-h]>c){
                comparacoes++;
                movimentacoes++;
                vetor[j] = vetor[j-h];
                j = j - h;
            }
            movimentacoes++;
            vetor[j] = c;
        }
        h = h/2;
    }
}