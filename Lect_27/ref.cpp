#include<iostream>
using namespace std;

int main(){
   int var = 5;
   int &ref = var; //connection between ref and var is permanent
   		   //syntax: ref is an int, use it like 'var' 
   int &ref2 = ref;

   int *ptr; 
   ptr = &var; //ptr holds the address of var 

   ref = 10; //updating the value of ref, which is the same as updating the value of var
   cout << "ref = " << ref << " var = " << var << endl;

   ref2 = 15;
   cout << "ref = " << ref << " var = " << var << endl;

   *ptr = 20;
   cout << "ref = " << ref << " var = " << var << endl;

   return 0;
}
