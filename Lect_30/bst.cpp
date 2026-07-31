#include <iostream>
#include <vector>
#include "bst.hpp"
//using namespace std;

template <class T>
bst<T>::bst(){
	root = NULL;
}

template <class T>
bst<T>::~bst(){
	cout<<"delete a binary search tree "<<endl;
	delete_tree(root);
}

template <class T>
void bst<T>::insert(T data){
	if(root == NULL){//empty tree, insert node as root
		root = new node<T>;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	else 
		insert(data, root);
}

template <class T>
node<T> * bst<T>::search(T data){
	if (root == NULL || root->data == data)
		return root;
	else
		return search(data, root);
}

template <class T>
void bst<T>::inorder(){
	if (root == NULL)
		cout<<"empty tree"<<endl;
	else{//use a vector to store traversal sequence
		cout<<"inorder traversal of this binary search tree"<<endl;
		vector<T> v;
		inorder(root, v);
		for(auto it=v.begin(); it!=v.end(); it++){
			cout<<"node:"<<*it<<endl;
		}
	}
}

template <class T>
int bst<T>::countnodes(){
	if (root == NULL)
		return 0;
	else
		return countnodes(root);
}

template <class T>
void bst<T>::delete_tree(node<T> *root){
	if(root != NULL){
		delete_tree(root->left);
		delete_tree(root->right);
		cout<<"node deleted: "<<root->data<<endl;
		delete root;
	}
}

template <class T>
void bst<T>::insert(T data, node<T> *root){
	if(data == root->data) //data already exists in BST
		return;
	else if(data < root->data){ //data should be in the left subtree
		if(root->left == NULL){ //insert as left child
			root->left = new node<T>;
			root->left->data = data;
			root->left->left = root->left->right = NULL;
			return;
		}
		else
			return insert(data, root->left);
	}
	else{ //data should be in the right subtree
		if(root->right == NULL){ //insert as right child
			root->right = new node<T>;
			root->right->data = data;
			root->right->left = root->right->right = NULL;
			return;
		}
		else
			return insert(data, root->right);
	}
}

template <class T>
node<T> * bst<T>::search(T data, node<T> *root){
	if((root == NULL) || (data == root->data))
		return root;
	else if(data < root->data)
		return search(data, root->left);
	else
		return search(data, root->right);
}

template <class T>
void bst<T>::inorder(node<T> *root, vector<T> &v){
	if(root != NULL){
		inorder(root->left, v);
		v.push_back(root->data); //add data at the end of vector
		inorder(root->right, v);
	}	
}

template <class T>
int bst<T>::countnodes(node<T> *root){
	if(root == NULL)
		return 0;
	else //1 + nodes on the left subtree + nodes on the right subtree 
		return 1+countnodes(root->left)+countnodes(root->right);
}

template class bst<int>;
