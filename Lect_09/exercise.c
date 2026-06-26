#include<stdio.h>
#define N 5

int main(){
	int row, col;
	for(row=0;row<N;row++){
		for(col=0;col<N;col++){
			if(row==col){
				printf("1");
			}
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}
