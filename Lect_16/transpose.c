#include <stdio.h>
#define ROW 2
#define COL 5

void transpose_ptr(int *in, int *out);
void transpose(int in[ROW][COL], int out[COL][ROW]);
void print_matrix(int *matrix, int row, int col);

int main(){

	int in_array[ROW][COL], out_array[COL][ROW];
	
	//Set in_array value
	int r,c;
        for(r=0;r<ROW;r++){
                for(c=0;c<COL;c++){
			in_array[r][c]=r*COL+c;
                }
	}

	//Print in_array value
	printf("Input Array: \n");
	print_matrix(&in_array[0][0], ROW, COL);

	//Perform transpose
	//transpose(in_array, out_array);
	transpose_ptr((int *)in_array, (int *)out_array);
	//transpose_ptr(&in_array[0][0], &out_array[0][0]);

	//Print out_array value
	printf("Output Array: \n");
	print_matrix(&out_array[0][0], COL, ROW);
	
	return 0;
}

void transpose(int in_array[ROW][COL], int out_array[COL][ROW]){

	int r,c;
        for(r=0;r<ROW;r++){
                for(c=0;c<COL;c++){
			out_array[c][r] = in_array[r][c];
                }
	}
}


void transpose_ptr(int *in_array, int *out_array){

	int r, c;
        for(r=0;r<ROW;r++){
                for(c=0;c<COL;c++){
			out_array[c*ROW+r] = in_array[r*COL+c];
                }
	}
}


void print_matrix(int *matrix, int row, int col){
        int i,j;
        for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                        printf("%d ", matrix[i*col+j]);
                }
                printf("\n");
        }
}
