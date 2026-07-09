#include <stdio.h>

int main(){
	int x[3]={1,2,3};
	int y[4]={4,5,6,7};
	printf("x is {%d, %d, %d}\n", x[0],x[1],x[2]);
	printf("y is {%d, %d, %d, %d}\n", y[0],y[1],y[2],y[3]);

	int *z[2];//={x, y};
	z[0] = x; //&x[0];
	z[1] = y; //&y[0];
	z[0][0] = 10;
	printf("x[0] = %d\n", x[0]);


        int matrix[][3] = {{1,2,3},{4,5,6}};
	matrix[0][0] = 9; 

	return 0;
}
