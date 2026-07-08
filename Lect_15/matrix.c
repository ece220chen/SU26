#include <stdio.h>
#define M 3 //row size
#define N 4 //col size

//function to exchange 2 rows (x,y) in an MxN matrix
int row_exchange(int matrix[][N], int x, int y);

int matrix_ptr(int *matrix, int x, int y);

int main(){
        int i, j;
        int matrix[M][N];

	printf("Initial Matrix: \n");
        for(i=0;i<M;i++){
                for(j=0;j<N;j++){
			matrix[i][j]= i*N+j;
			printf("%d ", matrix[i][j]);
                }
		printf("\n");
        }

	printf("New Matrix: \n");
	int rc = row_exchange(matrix, 1, 2);
	//int rc = matrix_ptr(&matrix[0][0], 1, 2); //try an out-of-bound number
	if (rc != 0){
		printf("exchange row index out of bound\n");
		return rc;
	}

        for(i=0;i<M;i++){
                for(j=0;j<N;j++){
                        printf("%d ", matrix[i][j]);
                }
                printf("\n");
        }

	return 0;
}

int matrix_ptr(int *matrix, int x, int y){
	//if x and y is greater than 5 or less than 0, just exit and return 1
	if((x==y) || (x>M-1) || (y>M-1) || (x<0) || (y<0))
		return 1;

	int i,j,temp;
	for(j=0;j<N;j++){
		temp=matrix[x*N+j];
		matrix[x*N+j] = matrix[y*N+j];
		matrix[y*N+j] = temp;
	}
	return 0;
}

int row_exchange(int matrix[][N], int x, int y){
	//if x and y is greater than 5 or less than 0, just exit and return 1
	if((x==y) || (x>M-1) || (y>M-1) || (x<0) || (y<0))
		return 1;

	int j, temp=0;
	for(j=0;j<N;j++){
		temp = matrix[x][j];
		matrix[x][j] = matrix[y][j];
		matrix[y][j] = temp;
	}
	return 0;
}
