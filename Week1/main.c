#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	printf("Hello World\n"); 
	printf("Intialized git in project\n");

	// allocate memory for a 2D array 20 x 30 

	int rows = 20;
	int columns = 30;
	
	int **arr = malloc (rows * sizeof(int));
	
	for (int i = 0; i < rows; i++){
		arr[i] = (int*) malloc (columns * sizeof (int));
}

	// Assign each element a value and print the value
	for (int i = 0; i < rows; i++){
		for (int k = 0; k < columns; k++){
			arr[i][k] = i + k;
			printf("%d ", arr[i][k]);
		}
		printf("\n");
	}
	for (int i = 0; i < rows; i++){
		free(arr[i]);
	}
	free(arr);
	return 0;
}

