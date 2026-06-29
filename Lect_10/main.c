/* 
 * Example with more than one source file
 * To compile: gcc main.c print.c -o print 
 * */

#include "print.h"

int main(){
	float radius=2.11;
	print_area(radius);

	return 0;
}
