/* use the following commands to compile and use valgrind to check for memory errors
gcc -g free.c -o free
valgrind ./free
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
	/* incorrect use of free, gcc will flag a warning since it will cause run-time error */
	/*	
	  int x=5;
	  int *ptr = &x;
	  free(ptr); 
	 */

	char *ptr2 = (char *)calloc(100, sizeof(char));
	if(ptr2 == NULL)
		return 0;
	strncpy(ptr2, "Here is an example using calloc & realloc", 100);
	printf("%s\n %p\n",ptr2, ptr2);
	
	char *ptr3 = realloc(ptr2, 50*sizeof(char));
	if(ptr3 == NULL)
		free(ptr2);
	else{
		printf("%s\n %p\n",ptr3, ptr3);
		free(ptr3);
	}

	/* technically we can still access the memory location although the 
	 * memory block has been freed, valgrind will flag this as an error */
	/*	
	  *ptr3 = 65;
	  printf("%c \n", *ptr3);
	 */

	return 0;
}
