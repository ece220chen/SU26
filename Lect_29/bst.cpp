#include <iostream>
using namespace std;

// tree node definition 
typedef struct btNode node;
struct btNode{
	int data;
	node *left;
	node *right;
};

// tree traversal
void preorder(node *root){ //root, L, R
	if(root!=NULL){	
		cout<<root->data<<endl; //visit root node
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node *root){ //L, root, R
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}

void postorder(node *root){ //L, R, root
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<endl;
	}
}

// find a particular node in a BST
node *search(node *root, int data){
	//base cases: 1)"root" is NULL; 2) found node
	if(root==NULL || root->data==data) //the order of the check must be correct!
		return root;
	// recursive cases: search left and right subtrees 
	if(data<root->data)
		return search(root->left, data);
	else
		return search(root->right, data);
}

// find the smallest node in a BST 
node *find_min(node *root){
	//base caes: 1)"root" is NULL; 2) current node has no left subtree
	if(root==NULL || root->left==NULL)
		return root;
	else
		return find_min(root->left);
}

// find the largest node in a BST 
node *find_max(node *root){
	//base cases: 1)"root" is NULL; 2) current node has no right subtree
	if(root==NULL || root->right==NULL)
		return root;
	else
		return find_max(root->right);
}

// count the number of leaf nodes in a BST
int leaf_count(node *root){
	// base cases: 1) "root" is NULL; 2)"root" is a leaf node
	if(root==NULL)
		return 0;
	else if (root->left==NULL && root->right==NULL)
		return 1;
	// recursive cases: count the leaf nodes on the left and right subtrees;
	// total leaf count = left_count + right_count
	else
		return leaf_count(root->left)+leaf_count(root->right);
}

// calculate the height of a BST
int height(node *root){
	// base cases: 1)"root" is NULL; 2)"root" is a leaf node
	if(root==NULL)
		return -1;
	else if(root->left==NULL && root->right==NULL)
		return 0;
	// recursive cases: calculate the height of the left and right subtrees;
	// height = 1 + max(left_height, right_height)
	int LH = height(root->left); //height of the left subtree
	int RH = height(root->right); //height of the right subtree
	if(LH>RH)
		return LH+1;
	else
		return RH+1;
}

void insert(node **pptr, int data){
	if(*pptr==NULL){
		*pptr = new node;
		(*pptr)->data = data;
		(*pptr)->left = NULL;
		(*pptr)->right = NULL;
		return;
	}
	else if (data == (*pptr)->data)
		return;
	else if(data < (*pptr)->data)
		insert(&((*pptr)->left), data);
	else
		insert(&((*pptr)->right), data);

}

void deletetree(node *root){
	if(root!=NULL){
		deletetree(root->left);
		deletetree(root->right);
		delete(root);
	}	
}

int main(){
	node *root = NULL;
	insert(&root, 50);
	insert(&root, 30);
	insert(&root, 70);
	insert(&root, 20);
	insert(&root, 40);
	insert(&root, 35);
	insert(&root, 45);
	insert(&root, 60);
	insert(&root, 80);
	
	cout<<"preorder traversal:"<<endl;
	preorder(root);
	cout<<"inorder traversal:"<<endl;
	inorder(root);
	cout<<"postorder traversal:"<<endl;
	postorder(root);

	node *temp = search(root, 60);
	if(temp != NULL)
		cout<<"found node with data: "<<temp->data<<" in bst"<<endl;

	node *min = find_min(root);
	if(min != NULL)
		cout<<"smallest node in bst is: "<<min->data<<endl;
	node *max = find_max(root);
	if(max != NULL)
		cout<<"largest node in bst is: "<<max->data<<endl;

	int count = leaf_count(root);
	cout<<"there are "<<count<<" leaf nodes in bst"<<endl;
		
	deletetree(root);

	return 0;
}
