#include <stdio.h>
#include <stdlib.h>

/* 
Implementation of Queue using Doubly linked list

A doubly linked list, with operations restricted to insert at rear, and delete at front, act as a Queue.
Two pointers front and rear, is used. 
At first, front = rear = NULL, 
Then, as each element is inserted, rear pointer updates, so as to point to the last node entered.
*/

//Define the structure for node
struct node {
	struct node *llink;
	int data;
	struct node *rlink;
};


struct node *front = NULL;
struct node *rear = NULL;



void display() {
	struct node *ptr;
	printf("Elements in the Queue:-\n\n");
	ptr = front;
	if (ptr == NULL) {
		printf("Queue Underflow.\n\n");
	} else {
		while (ptr->rlink != NULL) {
			printf("%d\t", ptr->data);
			ptr = ptr->rlink;
		}
		printf("%d\n", ptr->data);
	}
	printf("\n");
}

void enqueue() {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
    //create a temp node, and input data to it, then insert temp node as the first node
	printf("Enter the element to be inserted to the queue: ");
	scanf("%d", &temp->data);
	temp->rlink = NULL;

	if (rear == NULL) {       // rear = NULL  => No nodes. i.e., first node is yet to be inserted.
		temp->llink = NULL;
		rear = temp;	      // when there is only one node, both front, and rear points to it.
		front = temp;
	} else {
		rear->rlink = temp;   // temp is added at the end of list
		temp->llink = rear;
		rear = temp;          // and rear is updated to point to temp
	}
	display();
}


void dequeue() {
	struct node *ptr;
	ptr = front;
	if(ptr == NULL) {
		printf("Queue Underflow\n\n");
		return;
	} else {
		int data = ptr->data;
		printf("Deleted element : %d\n", data);
		front = ptr->rlink;   // front is updated to point to the second node, while first one is about to be deallocated.

		ptr->rlink = NULL; 
		ptr->llink = NULL;
		free(ptr);            //deallocates the memory address that was allocated to ptr.
	}
	display();
}


int main() {
	int optionNum;

	printf("\t\tQueue Implementation using Linked List.\n\n");
	do {
	 	printf("Available operations:- \n");
		printf("\n1. Insert an element into the queue.\n");
		printf("2. Delete an element from the Queue.\n");
		printf("3. Display the elements of the Queue.\n");
		printf("4. EXIT\n\n");
		printf("Enter the option number: ");
		scanf("%d", &optionNum);

		if (optionNum == 1) {
			enqueue();
		} else if (optionNum == 2) {
			dequeue();
		} else if (optionNum == 3) {
			display();
		} else if (optionNum == 4) {
			break;
		} else {
			printf("Invalid option number.\n\n");
		}
	}while(1);
}
