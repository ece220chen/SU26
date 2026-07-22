//compile using this command: g++ overload.cpp -o overload

#include <iostream>
using namespace std;
int getmin(int a, int b){
	return (a<b)?a:b;
}

double getmin(double a, double b){
	return (a<b)?a:b;
}

int main(){
	cout << "min of 5 and 7 is " << getmin(5, 7) << endl;
	cout << "min of 1234.5678 and 0.1357 is " << getmin(1234.5678, 0.1357) << endl;
	return 0;
}
