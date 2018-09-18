#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "stack.h"




int charToInt(char *str, int *arr){
	int lenstr = strlen(str);
	int i, j, len = 0, num = 0;

	for(i=2; i<lenstr; i++){
		if(str[i] == ','){
			arr[len] = num;
			len++;
			num = 0;
		}
		else {
			num = num*10 + str[i] - '0';
		}

	}

	return len+1;
}




struct stack * getMnistData(char *str, long start, long end){
	FILE *fptr;

	if ((fptr = fopen(str, "r")) == NULL){
        	printf("Error! opening file");
        	exit(1);
    	}

	long i, j;
	char *c = (char *) malloc(10000 * sizeof(char)); 
	int *arr = (int *) malloc(1000 * sizeof(int));

	struct stack *sta = newStack();
	struct matrix * mat;

	for(i=0; i<=end; i++){
		fgets(c,10000, fptr);
		if(i >= start){
			int len = charToInt(c, arr);

			mat = newMatrix(28, 28);

			for(j=0; j<len; j++)
				(mat->data)[j] = arr[j];
				
			pushStackElement(sta, mat);
		}
	}

	free(c);
	free(arr);

	return sta;
}

			
			

