#include<iostream>
using namespace std;

void swap_ref(int &x, int &y){
   int temp = x;
   x = y;
   y = temp;
}

int main(){
   int a = 1;
   int b = 2;
   cout << "before swap: " << "value of a = " << a << ", value of b = " << b << endl;
   swap_ref(a,b);
   cout << "after swap: " << "value of a = " << a << ", value of b = " << b << endl;
   return 0;
}
