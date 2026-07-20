#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Record;
struct studentStruct{
	char Name[100];
	int UIN;
	float GPA;
	Record *next;
};



Record *find_node(Record *head, int UIN){
	Record *current = head;

	//keep traversing the list while 1)not at the end of the list AND 
	//				 2)current record's UIN < UIN we are looking for
	while((current != NULL) && (current->UIN <= UIN)){
		if(current->UIN == UIN){
			printf("Student Found, UIN: %d.\n", current->UIN);
			return current;
		}
		current = current->next; //go to the next node
	}
	printf("Student Not Found.\n");
	return NULL;
}

void add_node(Record **list, int new_UIN, float new_GPA){
	Record *temp = (Record *)malloc(sizeof(Record)); //allocate memory for the new node
	if(temp == NULL)
		return;
	temp->UIN = new_UIN; //initialize UIN for the new node
	temp->GPA = new_GPA;

	//case 1: insert at head
	if((*list == NULL) || ((*list)->UIN > new_UIN)){
		temp->next = *list;
		*list = temp;
		return;
	}

	//case 2: insert in the middle or at the end
	Record *current = *list;
	//keep traversing the list until we find the correct place to insert node
	while(current->next != NULL && current->next->UIN <= new_UIN){
		current = current->next;
	}
	
	//handle duplicate node
	if(current->UIN == new_UIN)
		return;

	//redirect pointer to insert node before current->next node
	temp->next = current->next;
	current->next = temp;
}


void remove_node(Record **list, int old_UIN){
	Record *current = *list;
	Record *temp;
	//case 1: remove head node, update list
	if((*list)->UIN == old_UIN){
		temp = *list;
		*list = (*list)->next;
	}

	//case 2: find node in the middle or at the end
	while(current->next != NULL){
		if(current->next->UIN == old_UIN)
			break;
		else if(current->next->UIN > old_UIN){ //past the range
			printf("Record not found.\n");
			return;
		}
		current = current->next;
	}

	//record not found after traversing the entire llist
	if(current->next == NULL){
		printf("Record not found.\n");
		return;
	}
	else{//record found - redirect pointers
		temp = current->next;
		current->next = current->next->next;
	}
	
	free(temp);
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
		Record *temp = head;
		free(temp);
		delete_list(head->next);
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
	find_node(head, 12349);

	//add a new node
	int new_UIN = 12355;
 	printf("Insert record with UIN: %d.\n", new_UIN);
	add_node(&head, new_UIN, 4.0);
	print_list(head);

 	printf("Insert record with UIN: %d.\n", new_UIN);
	add_node(&head, new_UIN, 3.0);
	print_list(head);

	//remove a node
	int old_UIN = 12352;
	printf("Delete record with UIN: %d.\n", old_UIN);
	remove_node(&head, old_UIN);
	print_list(head);

	delete_list(head);
	return 0;
}
