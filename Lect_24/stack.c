#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct nodeStruct node;
struct nodeStruct{       
        int data;
        node *next;
};

node *top;

void push(int new_data){
	//allocate a new node to hold data
	node *new_node = (node *)malloc(sizeof(node));
	if(new_node == NULL){
		printf("stack is full\n");
		return;
	}
	new_node->data = new_data;
	//set new node's next pointer to point to current stack top
	new_node->next = top;
	//update stack top pointer
	top = new_node;
}

int pop(){
	//if stack is empty, exit function
	if(top == NULL){
	       	printf("stack is empty\n");	
		return INT_MAX;
	}
	//use a temp pointer to point to stack top and save data
	node *temp = top;
	int value = temp->data;
	//update stack top pointer
	top = top->next;
	//delete original top node
	free(temp);
	return value;
}



void print_stack(){
        node *current = top;
        int i = 0;
        while(current!= NULL){
                printf("Node %d: %d\n", i, current->data);
                i++;
                current = current->next;
        }
}


int main(){
	top = NULL;
	push(1);
	push(3);
	push(5);
        print_stack();
	printf("data pop from stack: %d \n",pop());
	print_stack();
	printf("data pop from stack: %d \n",pop());
	print_stack();
	printf("data pop from stack: %d \n",pop());
	print_stack();
	printf("data pop from stack: %d \n",pop());
	return 0;
}
