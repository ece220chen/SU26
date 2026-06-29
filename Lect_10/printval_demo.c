#include <stdio.h>
/*function prototype*/
void print_val(int x, int y);

int main(){
	int val = 20;
	print_val(val, val++); 
	printf("final value of val = %d \n", val);
	return 0;
}

/*function implementation*/
void print_val(int x, int y){
	printf("x = %d, y = %d\n", x, y);
}
