#include <stdio.h>

int fib(int n){ /* assume n is non-negative */
	if(n<2)
		return n;
	else 
		return fib(n-1) + fib(n-2);
}

int main(){
	int n=4;
	printf("fibonacci(%d)=%d \n",n,fib(n));

	return 0;
}
