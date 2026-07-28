#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main(){
	//Create a vector containing ints
	vector<int> intVector {1, 3, 5, 7};
	//Add two new elements to the end of vector
	intVector.push_back(9);
	intVector.push_back(11);
	//Print values of vector
	cout<<"elements in intVector:"<<endl;
	for(int i=0; i<intVector.size(); i++){
		cout<<intVector[i]<<endl;
	}

	//Create a list containing floats
	list<float> l {2.1, 3.2, 4.5, 3.2, 5.6, 5.6};
	//Remove adjacent duplicate elements in list
	l.unique();
	//Remove all elements of list with value '4.5'
	l.remove(4.5);
	cout<<"elements in l:"<<endl;
	//Use iterator to print elements in list
	for(auto it=l.begin(); it!=l.end(); it++){
		cout<<*it<<endl;
	}

	return 0;
}
