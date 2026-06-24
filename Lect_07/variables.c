/* example of global vs. local variables */
/* This is NOT the best practices you should follow */
#include <stdio.h>

int x = 100; /* global x */

int main(){
   printf("value of x is %d\n", x); 
   
   int x = 10; /* local x in main */
   printf("value of x is %d\n", x);

   {
     int x = 1; /* declare another x */
     printf("value of x is %d\n", x); 
   }
   
   printf("value of x is %d\n", x); 

   return 0;
}
