#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Record;
struct studentStruct{
	int UIN;
	float GPA;
	Record *next;
};


Record *find_node(Record *head, int S_UIN){
	//base case 1: if list is empty/reach the end OR UIN is past the range
	if((head == NULL) || (S_UIN < head->UIN)){
		printf("Record %d Not Found.\n", S_UIN);
		return NULL;
	}
	//base case 2: if found matching record
	if(head->UIN == S_UIN){
		printf("Record Found, UIN: %d.\n", head->UIN);
		return head;
	}

	return find_node(head->next, S_UIN);
}


void add_node(Record **list, int new_UIN, int new_GPA){
	Record *current = *list;
	Record *temp;
	//base case 1: insert before current node
	if((current == NULL) || (new_UIN < current->UIN)){
		//allocate memory for the new node
		temp = (Record *)malloc(sizeof(Record)); 
		if(temp == NULL)
			return;
		//set members in node
		temp->UIN = new_UIN; 
		temp->GPA = new_GPA;
		temp->next = current;
		//update "head"
		*list = temp;
		return;
	}

	//base case 2: duplicate node
	if(current->UIN == new_UIN)
		return;

	//recursive case
	add_node(&(current->next), new_UIN, new_GPA);
}


void remove_node(Record **list, int old_UIN){
	Record *current = *list;
	//base case 1: empty list OR record not in list -> record not found
	if((current == NULL) || (current->UIN > old_UIN)){
		printf("Record %d not found.\n", old_UIN);
		return;
	}

	//base case 2: update "head" pointer, remove node
	if(current->UIN == old_UIN){
		*list = (*list)->next;
		free(current);
		return;
	}

	//recursive case
	remove_node(&(current->next), old_UIN);
}


void print_list(Record *head){
	if(head == NULL)
		return;
	else{
		printf("UIN: %d\n", head->UIN);
		print_list(head->next);
	}
}


void delete_list(Record *head){
	if(head != NULL){
		Record *temp = head->next;
		// deallocate node
		printf("delete list: node=%d\n", head->UIN);
		free(head);
		delete_list(temp);
	}
}



int main(){
	Record *head = NULL;

	int i;
	for(i=0;i<9;i=i+2){
		//create a linked list
		add_node(&head, 12345+i, 4.0);
	}
	print_list(head);

	//find a node 
	find_node(head, 12353);

	//add a new node
	int new_UIN = 12343;
 	printf("Insert record with UIN: %d.\n", new_UIN);
	add_node(&head, new_UIN, 4.0);
	print_list(head);

 	printf("Insert record with UIN: %d.\n", new_UIN);
	add_node(&head, new_UIN, 4.0);
	print_list(head);

	//remove a node
	int old_UIN = 12349;
	printf("Delete record with UIN: %d.\n", old_UIN);
	remove_node(&head, old_UIN);
	print_list(head);

	//deallocate the list
	delete_list(head);
	return 0;
}
