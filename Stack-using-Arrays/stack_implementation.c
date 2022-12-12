#include <stdio.h>
#define MAX 10

/*

Stack - Like a rack of stuff, placed one above other, and can be accessed from only one end.

Eg:- 

  +   +
  | 4 |
  | 5 |
  | 6 |
  +---+

  if you have to access 6, you have to take 4 out, then take 5 out, and then only access the 6.

[+] LIFO data structure - Last in - First out

[+] There's only one pointer, top, which always points to the top most element.
    You can only access the element at the top, at any time.

[+] Mainly two functionalities in a stack- Push and Pop.
	push => add an element to the top of stack.
	pop => delete the element from the top of the stack.

Below is a basic implementation of stack using arrays in C.

*/

int stack[MAX];
int top = -1;

int isFull() {
	if (top == MAX - 1)
		return 1;
	else
		return 0;
}

int isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}


void push(int item) {
	if (isFull()) 
		printf("\nStack Overflow\n");
	else
		stack[++top] = item;
}

int pop() {
	if (isEmpty())
		printf("\nStack Underflow\n");
	else {
		int poppedItem = stack[top--];
		return poppedItem;
	}
	return 0;

}

void display() {
	if (isEmpty())
		printf("\nStack Underflow\n");
	else {
		printf("\nElements of the stack\n");
		for(int i = top; i >= 0; i--) 
			printf("%d\n", stack[i]);
	}
	printf("\n************************\n");
}

char choice() {
	char choice;
	printf("Do you want to perform stack operations again? (y/n): ");
	scanf(" %c", &choice);
	return choice;
}

int main() {
	int optionNum, item;
	char repeat = 'y';

	printf("\t\t\t\tSTACK IMPLEMENTATION\n");
	do {
		
		printf("\nMAX Stack size = %d\n", 10);
		printf("\n************************\n");
		printf("\nOperations\n");
		printf("\n1. Push an element into the stack.\n2. Pop an element from the stack.\n3. Display the elements of the stack.\n");
		printf("\nEnter your option number to perform that operation: ");
		scanf("%d", &optionNum);
		if (optionNum == 1) {
			printf("\nEnter the element to be pushed to the stack: ");
			scanf("%d", &item);
			push(item);
			display();
		} else if (optionNum == 2) {
			item = pop();
			display();
		} else if (optionNum == 3) {
			display();
		} else {
			printf("Invalid option number.\n");
		}
		repeat = choice();
	} while(repeat == 'y');

}