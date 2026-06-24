/* example using static qualifier */
#include <stdio.h>

void printx(){
	/* x can only be accessed inside printx,  although its value retains */
	static int x = 0; /* scope is printx */ 

	/* static qualifier retains the variable when it goes out of scope 
  	   try int x = 0; and run the code again. */
	x++; /* increment by 1 */
	printf("value of x is %d \n",x);
}

int main(){
	printx();
	printx();
	printx();
	printx();
	return 0;
}
