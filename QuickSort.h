int quickSort(int number[], int first, int last) {  
	int pivo, temp, i, j;
	
	i = first;
    j = last;
	pivo = number[(first+last)/2];
      	
	while(i < j) {
		comparacoes++;
		while(number[i] < pivo){
			comparacoes++;
			i++;
		}
		while(number[j] > pivo){
			comparacoes++;
			j--;
		}
			
		if(i <= j) {
			comparacoes++;

			movimentacoes++;
			temp = number[i];
			number[i] = number[j];
			number[j] = temp;
			i++;
			j--;
		}
	}

	if(first < j){
		comparacoes++;
		movimentacoes++;
		quickSort(number,first,j);
	}
	if(i < last){
		comparacoes++;
		movimentacoes++;
		quickSort(number,i,last);
	}
   	
}
