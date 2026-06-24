/* example of const qualifier */
#include <stdio.h>

int main(){
   int x = 20;
   const int y = 15;

   x = 10;
   y = 1; /* this will cause compiler error */

   return 0;
}
