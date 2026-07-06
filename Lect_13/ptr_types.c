#include <stdio.h>

int main(){
	char arr[8]; /* once an array is declared, we need to set each element individually */
	arr[0]= 'C';
	arr[1]= 'O';
	arr[2]= 'M';
	arr[3]= 'P';
	arr[4]= 'U';
	arr[5]= 'T';
	arr[6]= 'E';
	arr[7]= 'R';
	char *c_ptr = arr;
	int *i_ptr = (int *)arr;
        double *d_ptr = (double *)arr;	

	printf("c_ptr=%p, i_ptr=%p, d_ptr=%p\n", c_ptr, i_ptr, d_ptr);

	c_ptr++, i_ptr++, d_ptr++;

	printf("c_ptr+1=%p, i_ptr+1=%p, d_ptr+1=%p\n", c_ptr, i_ptr, d_ptr);
	return 0;
}
