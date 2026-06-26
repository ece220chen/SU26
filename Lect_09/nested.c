#include <stdio.h>

/* use nested for loops to print an n x n identity matrix */

int main(){
   int row, col, n=0;

   do{
   	printf("Enter a number between 1 and 9 for n x n matrix size: ");
   	scanf("%d", &n);
   	if(n<1 || n>9)
		printf("Number entered is invalid. \n");
   }while(n<1 || n>9);

   printf("Output Identity Matrix: \n");

   for (row = 0; row < n; row++){
	for (col = 0; col < n; col++){
		if(row == col)
		   printf("1");
		else
		   printf("0");
	}
	printf("\n");
   }

   printf("Stop Printing after the third '1'\n");
   for (row = 0; row < n; row++){
	for (col = 0; col < n; col++){
		if(row == col){
		   printf("1");
		   if(row == 2){
			break;	
		   }
		}
		else
		   printf("0");
	}
	printf("\n");
	if(row==2)
		break;
   }

   return 0;
}
