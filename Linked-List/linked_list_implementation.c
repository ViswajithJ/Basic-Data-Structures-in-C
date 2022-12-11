
#include <stdio.h>
#include <stdlib.h>

/*
    head is a pointer to struct node type.
    it points to the first node in the list.

    data part of structure holds the data.
    link part of structure holds the address of the next node.

    +------+           +----+----+           +----+----+            +----+----+
    | head | ------>   |data|link|---------->|data|link|----------->|data|NULL|
    +------+           +----+----+           +----+----+            +----+----+
      head             first node            second node           last node(3rd)

    [+] head = NULL          =>    no nodes
    [+] head->link = NULL    =>    only one node
   

*/

//Define the structure for node
struct node {
	int data;
	struct node *link;
};

struct node *head = NULL;//(struct node *) malloc(sizeof(struct node));

void display() {
	struct node *ptr;
	printf("Elements in the linked list:-\n\n");
	ptr = head;
	if (ptr == NULL) {
		printf("Linked list empty.\n\n");
	} else {
		while (ptr->link != NULL) {
			printf("%d\t", ptr->data);
			ptr = ptr->link;
		}
		printf("%d\n", ptr->data);
	}
	printf("\n");
}

void insert_front() {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	printf("Enter the node data to be inserted: ");
	scanf("%d", &temp->data);
	temp->link = head; //[right side link of node]
	head = temp;	   //[left side link of node]	Always handle/copy the right side link of the new node
}


void insert_end() {
	if (head == NULL) {
		insert_front();
	} else {
	    //create a temp node and obtain data
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		printf("Enter the node data to be inserted: ");
		scanf("%d", &temp->data);
		temp->link = NULL;
		//temp node ready

		struct node *ptr; //temp pointer-to-node to traverse through the list, like an iterator 
		ptr = head;

		while(ptr->link != NULL) {
			ptr = ptr->link;
		}
		//after while loop ends, ptr points to the last node.
		 
		ptr->link = temp;
	}
}


void insert_at_index(int pos) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));

	struct node *ptr;
	struct node *prev_ptr;
	ptr = head;

	if(pos == 0) {
		insert_front();
	} else {
		int index = 0;
		while((ptr->link != NULL) && (index != pos)) {
			prev_ptr = ptr;
			ptr = ptr->link;
			index++;
		}
		if (pos == index) {
			printf("Enter the node data to be inserted: ");
			scanf("%d", &temp->data);
			temp->link = prev_ptr->link; //can it be  temp->link = ptr?
			prev_ptr->link = temp;
		} else if (pos == index+1) {
			insert_end();
		} else {
			printf("Index out of range.\n\n");
		}
	}
}

void delete_front() {
	struct node *ptr;
	ptr = head;
	if(ptr == NULL) {
		printf("Linked list is empty.\nNo elements to be deleted.\n\n");
		return;
	} else {
		head = ptr->link; //left side connection broken

		//before calling free function to release memory, connection at both end is to be severed
		ptr->link = NULL; //right side connection broken
		free(ptr);
	}
}

void delete_end() {
	struct node *ptr;
	struct node *prev_ptr;
	ptr = head;
	if (ptr == NULL){
		printf("Linked list is empty.\nNo elements to be deleted.\n\n");
		return;
	} else if(ptr->link == NULL) {
		ptr = head;
		head = ptr->link;
		free(ptr);
	} else {
		while(ptr->link != NULL) {
			prev_ptr = ptr;
			ptr = ptr->link;
		}
		prev_ptr->link = NULL;
		free(ptr);
	}
}

void delete_at_index(int pos) {
	struct node *ptr;
	struct node *prev_ptr;
	int index = 0;
	//code for length of the list
	int len = 1;
	ptr = head;
	if (ptr == NULL) {
		len = 0;
	} else {
		while(ptr->link != NULL) {
			ptr = ptr->link;
			len++;
		}	
	}
	ptr = head;
	if (ptr == NULL) {
		printf("Linked list is empty.\nNo elements to be deleted.\n\n");
		return;
	} else if(pos > len) {
		printf("Index out of range.\n\n");
	} else if (pos == 0) {
		delete_front();
	} else if (ptr->link == NULL) { //change for the better
		ptr = head;
		head = ptr->link;
		free(ptr);
	} else {
		while((ptr->link != NULL) && (index != pos)) {
			prev_ptr = ptr;
			ptr = ptr->link;
			index++;
		}
		prev_ptr->link = ptr->link;
		ptr->link = NULL;
		free(ptr);
	}
}

int main() {
	int optionNum, pos;

	printf("Single Linked List Implementation.\n\n");
	do {
	 	printf("Available operations:- \n");
		printf("1. Insert at the Beginning.\n");
		printf("2. Insert at the End.\n");
		printf("3. Insert at a specified position.\n");
		printf("4. Delete from specified position.\n");
		printf("5. Delete from Beginning.\n");
		printf("6. Delete from End.\n");
		printf("7. EXIT\n\n");
		printf("Enter the option number: ");
		scanf("%d", &optionNum);

		if (optionNum == 1) {
			insert_front();
			display();
		} else if (optionNum == 2) {
			insert_end();
			display();
		} else if (optionNum == 3) {
			printf("Enter the index at which data is to inserted: ");
			scanf("%d", &pos);
			insert_at_index(pos);
			display();
		} else if(optionNum == 4) {
			printf("Enter the index at which data is to deleted: ");
			scanf("%d", &pos);
			delete_at_index(pos);
			display();
		} else if(optionNum == 5) {
			delete_front();
			display();
		} else if (optionNum == 6) {
			delete_end();
			display();
		} else if (optionNum == 7) {
			break;
		} else {
			printf("Invalid option number.\n\n");
		}
	}while(1);
}
