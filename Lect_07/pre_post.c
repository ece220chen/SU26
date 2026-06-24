/* example using pre vs. post increment */

#include <stdio.h>
int main(){
   /* pre-increment */
   int x, y;
   x = 4;
   printf("x = %d \n", x);
   y = ++x;
   printf("after pre-increment (y = ++x): x = %d, y = %d\n", x,y);

   /* post-increment */
   x = 4;
   printf("x = %d \n", x);
   y = x++;
   printf("after post-increment (y = x++): x = %d, y = %d\n", x,y);

   return 0;
}
