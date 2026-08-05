#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode node;
struct ListNode{
        int data;
        node* next;
};

/* remove nodes with a particular value in the linked list */
void remove_nodes(node **list, int value){
	if(*list == NULL)
		return;

	if((*list)->data == value){
		node *temp = (*list)->next;
		free(*list);
		*list = temp;
		remove_nodes(list, value);
	}
	else
		remove_nodes(&((*list)->next), value);
}

/* split a linked list into two smaller linked lists */
void split(node *head, node **front, node **back){
	node *slow, *fast;
	if((head == NULL) || (head->next == NULL)){
		*front = head;
		*back = NULL;
	}
	else{
		slow = head;
		fast = head->next;

		while((fast!= NULL) && (fast->next!=NULL)){
			slow = slow->next;
			fast = fast->next->next;
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

/* assume nodes are sortd, remove duplicates */
void remove_duplicate(node *head){
	if(head == NULL)
		return;

	node* current=head;
	while(current->next != NULL){
		if(current->data == current->next->data){
			node *temp = current->next;
			current->next = current->next->next;
			free(temp);
		}
		else
			current = current->next;	
	}
}

/* left rotate a linked list by n nodes */
int rotate_list(node **list, int n){
	node *current;

	if(n==0 || list == NULL || *list == NULL)
		return 1;

	current = *list;
	/* traverse the list to find the tail */
	while(current->next != NULL){	
		current = current->next;
	}

	/* set tail node to point to head node */
	current->next = *list;

	/* find the node to set as the new tail */
	while(n != 0){
		current = current->next;
		n--;
	}

	/* update *head and update new tail node's next ptr */
	*list = current->next;
	current->next = NULL;
	return 0;	
}

/* insert nodes at head */
void insert(node **list, int data){
        node *current;
        current = malloc(sizeof(node));
        current->data = data;
        current->next = *list;
        *list = current;
}

void printlist(node *head){
        if(head != NULL){
                printf("data: %i\n", head->data);
                printlist(head->next);
        }
}

void deletelist(node *head){
        if(head != NULL){
                node *temp = head->next;
                free(head);
                deletelist(temp);
        }
}

int main(){
	node *head = NULL;
	insert(&head, 9);
	insert(&head, 2);
	insert(&head, 1);
	insert(&head, 7);
	insert(&head, 4);
	insert(&head, 1);
	insert(&head, 10);
	insert(&head, 8);

	printf("Original List\n");
	printlist(head);

	printf("\n");

	remove_nodes(&head, 1);
	printf("List after removing 1s\n");
	printlist(head);
	printf("\n");


	rotate_list(&head, 2);
	printf("List after n=2 rotations\n");
	printlist(head);
	printf("\n");


	node *front, *back;
	split(head, &front, &back);
	printf("Front Half of List\n");
	printlist(front);
	printf("\n");
	printf("Back Half of List\n");
	printlist(back);
	deletelist(front);
	deletelist(back);

/*
	printlist(head);
	printf("\n");

	rotate_list(&head, 2);
	printlist(head);
	
	deletelist(head);
*/
	return 0;
}
