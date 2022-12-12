#include <stdio.h>
#define MAX 3

int queue[MAX];

int front = -1;
int rear = -1;

/*

Queue - Imagine a real life queue. Insertion from rear, Removal from front.
        irl, first person to be in a queue inserts from rear, but goes on to the front,
        becuz no body in front of him/her.

        EG :- 
                        +-----------+
           front-end--> | 5 | 4 | 6 | <--rear-end
                        +-----------+

                        5 entered the queue first, it will leave the queue first.
                        6 will leave the queue last, as its at the rear end.


[+] FIFO data structure - First in - First out
[+] two pointers, front and rear, pointing to front-end and rear-end of the queue.
[+] mainly two functionalities, enqueue and dequeue
    Enqueue => Inserting an element to queue from the rear-end.
    Dequeue => Deleting an element from the queue, from the front-end.

irl, first person to be in a queue inserts from rear, but goes on to the front,
        becuz no body in front of him/her.
that's y rear = 0 at front. then people comes from rear and stand behind first person.
therefore, r: 0 -> MAX-1
*/

void display() {
	if (front == rear) {
		printf("Queue Underflow.\n");
	} else {
		printf("\nElements of the Queue:-\n");
		int i;
		for(i = front+1; i <= rear; i++) {
			printf("%d ", queue[i]);
		}
		printf("\n");
		printf("\n************************\n");
	}
}

void enqueue(int item) {
	if (rear == MAX-1) {     
		printf("Queue Overflow.\n");
	} else {
		queue[++rear] = item;
	}
	display();
}

int dequeue() {
	int item;
	if (front == rear) {
		printf("Queue Underflow.\n");
	} else {
		item = queue[++front];
		display();
		return item;
	}
}

char choice() {
	char choice;
	printf("\nDo you want to perform queue operations again? (y/n): ");
	scanf(" %c", &choice);
	return choice;
}


int main() {
	int optionNum, item;
	char repeat = 'y';

	printf("\t\t\tQueue Implementation\n");
	do {
		
		printf("\nMAX Queue size = %d\n", MAX);
		printf("\n************************\n");
		printf("\nQueue Operations\n");
		printf("\n1. Insert element to the queue.\n2. Delete an element from the queue.\n3. Display the elements of the queue.\n");
		printf("\nEnter your option number to perform that operation: ");
		scanf("%d", &optionNum);
		if (optionNum == 1) {
			printf("\nEnter the element to be inserted to the queue: ");
			scanf("%d", &item);
			enqueue(item);
		} else if (optionNum == 2) {
			item = dequeue();
		} else if (optionNum == 3) {
			display();
		} else {
			printf("Invalid option number.\n");
		}
		repeat = choice();
	} while(repeat == 'y');
}