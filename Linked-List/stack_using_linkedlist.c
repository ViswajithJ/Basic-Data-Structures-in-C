#include <stdio.h>
#include <stdlib.h>

/* 
Implementation of Stack using linked list

A linked list, with operations restricted to insert at front, and delete at front, act as a Stack.
Here, top points to the first node at all times.
 
*/


//Define the structure for node
struct node {
	int data;
	struct node *link;
};

//top is the pointer to first node
struct node *top = NULL;

void display() {
	struct node *ptr;
	printf("Elements in the stack:-\n\n");
	ptr = top;
	if (ptr == NULL) {
		printf("Stack Underflow.\n\n");      //top is NULL => no nodes
	} else {
		while (ptr->link != NULL) {
			printf("%d\t", ptr->data);
			ptr = ptr->link;
		}
		printf("%d\n", ptr->data);
	}
	printf("\n");
}


void push() {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	//create a temp node, and input data to it, then insert temp node as the first node
	printf("Enter the element to be pushed to the stack: ");
	scanf("%d", &temp->data);
	temp->link = top; 
	top = temp;	  
	display();
}


void pop() {
	struct node *ptr;
	ptr = top;
	if(ptr == NULL) {
		printf("Stack Underflow\n\n");
		return;
	} else {
		int data = ptr->data;
		printf("Deleted element : %d\n", data);
		top = ptr->link; 
		ptr->link = NULL; 
		free(ptr);        //deallocates the memory address that was allocated to ptr.
	}
	display();
}

int main() {
	int optionNum;

	printf("\t\tStack Implementation using Linked List.\n\n");
	do {
	 	printf("Available operations:- \n");
		printf("\n1. Push an element into the stack.\n");
		printf("2. Pop an element from the stack.\n");
		printf("3. Display the elements of the stack.\n");
		printf("4. EXIT\n\n");
		printf("Enter the option number: ");
		scanf("%d", &optionNum);

		if (optionNum == 1) {
			push();
		} else if (optionNum == 2) {
			pop();
		} else if (optionNum == 3) {
			display();
		} else if (optionNum == 4) {
			break;
		} else {
			printf("Invalid option number.\n\n");
		}
	}while(1);
}

