#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode node;
struct treeNode{
	int data;
	node *left;
	node *right;
};

node *newnode(int new_data){
	node *new = (node*)malloc(sizeof(node));
	new->data = new_data;
	new->left = new->right = NULL;
	return new;
}

void insert(node **node, int new_data){
	if(*node == NULL){
		*node = newnode(new_data);
		return;
	}

	if(new_data > (*node)->data)
		insert(&(*node)->right, new_data);
	else
		insert(&(*node)->left, new_data);	

}

void deleteTree(node *root){
	if(root == NULL)
		return;

	deleteTree(root->left);
	deleteTree(root->right);
	
	printf("%d \n",root->data);
	free(root);
}

int leaf_count(node *root){
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL){
		printf("leaf node:%d \n", root->data);
		return 1;}
	else 
		{return leaf_count(root->left) + leaf_count(root->right);}
}

void leaf_nodes(node *root){
	if(root == NULL)
		return;
	if(root->left == NULL && root->right == NULL)
		printf("leaf node:%d \n", root->data);

	leaf_nodes(root->left);
	leaf_nodes(root->right);
}

int smallest(node *root){
	if(root == NULL)
		return -1;
	if(root->left == NULL)
		return root->data;
	else
		return smallest(root->left);
}

int largest(node *root){
	if(root == NULL)
		return -1;
	if(root->right == NULL)
		return root->data;
	else
		return largest(root->right);
}
void print_left_boarder(node *root){
        if(root == NULL)
                return;

        if(root->left != NULL){
                printf("Left Boarder Node is: %d \n", root->data);
                print_left_boarder(root->left);
        }
        else if(root->right != NULL){
                printf("Left Boarder Node is: %d \n", root->data);
                print_left_boarder(root->right);
        }
}

void print_right_boarder(node *root){
	if(root == NULL)
                return;

        if(root->right != NULL){
                print_right_boarder(root->right);
                printf("Right Boarder Node is: %d \n", root->data);
        }
        else if(root->left != NULL){
                print_right_boarder(root->left);
                printf("Right Boarder Node is: %d \n", root->data);
        }
}

void print_boarder(node *root){
	print_left_boarder(root);

	leaf_nodes(root);

	print_right_boarder(root->right);
}

bool path_sum(node *root, int target){
	if(root == NULL)
		return false;
	if(root->left==NULL && root->right==NULL)
		return (target == root->data);

	bool left = path_sum(root->left, target - root->data);
	bool right = path_sum(root->right, target - root->data);
	return left||right;
}

int main(){
        FILE *in_file;
	node *root = NULL;
	int new_data;

        in_file = fopen("bst.txt", "r");
        if(in_file == NULL){
                printf("Cannot open file.\n");
                return -1;
        }

        while(fscanf(in_file, "%d", &new_data) == 1){
                insert(&root, new_data);
        }
        fclose(in_file);

	printf("Leaf count is: %d \n", leaf_count(root));

	printf("Smallest node is: %d \n", smallest(root));

	printf("Largest node is: %d \n", largest(root));

	print_boarder(root);

	int target = 100;
	bool path = path_sum(root, target);
	printf("Is there a path from root to leaf with sum of %d exist in this BST? Yes(1)/No(0): %d\n", target, path);

	printf("Delete BST: \n");
	deleteTree(root);

	return 0;
}
