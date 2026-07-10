#include <stdio.h>
/*
 * Recursive Fibonacci with look-up table. 
 */

int table[100];

int fib(int n){
	if(table[n]!= -1)
		return table[n];

	if(n < 2)
		table[n] = n;
	else
		table[n] = fib(n-1)+fib(n-2);

	return table[n];
}

int main(){
	int i,num;
	for(i=0;i<100;i++)
		table[i] = -1;

	num = fib(3);
	printf("Print Table: %d, %d, %d, %d\n", table[0], table[1], table[2],table[3]);
	return 0;
}
