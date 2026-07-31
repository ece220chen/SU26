// compile using the following command:
// g++ main.cpp bst.cpp -o bst
// run the code using the following command:
// ./bst

#include <iostream>
#include "bst.hpp"
using namespace std;

int main(){
	cout<<"build a binary search tree"<<endl;
	bst<int> tree1;
	tree1.insert(30);
	tree1.insert(20);
	tree1.insert(10);
	tree1.insert(15);
	tree1.insert(40);

	cout<<"total number of nodes in this tree: "<<tree1.countnodes()<<endl;
	tree1.inorder();
	return 0;
}
