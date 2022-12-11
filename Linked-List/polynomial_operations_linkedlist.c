#include <stdio.h>
#include <stdlib.h>

//Define the structure for node
struct node {
	int coeff;
	int exp;
	struct node *link;
};

struct node *phead = NULL;        //polynomial 1
struct node *qhead = NULL;        //polynomial 2
struct node *sumhead = NULL;      //sum polynomial
struct node *producthead = NULL;  //product polynomial

void display_poly(struct node *head) {
	struct node *ptr;
	printf("Polynomial:-\n\n");
	ptr = head;
	if (ptr == NULL) {
		printf("There are no terms in the polynomial.\n\n");
	} else {   
		while (ptr->link != NULL) {
			printf("%dx^%d + ", ptr->coeff, ptr->exp);
			ptr = ptr->link;
		}
		printf("%dx^%d\n", ptr->coeff, ptr->exp);
	}
	printf("\n");
}

struct node* insert_term(struct node *head, struct node *temp) {
	if (head == NULL) {
		temp->link = head; 
		head = temp;
		return head;
	} else {
		struct node *ptr; //temp pointer-to-node to traverse through the list, like an iterator 
		ptr = head;
		while(ptr->link != NULL) {			
			ptr = ptr->link;
		}
		//after while loop ends, ptr points to the last node.
		ptr->link = temp;
		return head;
	}
}

void input_poly() {
	int i = 0, len1, len2;
	printf("\nEnter the number of terms in the first polynomial: ");
	scanf("%d", &len1);

	printf("\nEnter the coefficients and exponents of each term, in decreasing order of exponents:- \n ");
	for(i=0; i < len1; i++) {
		//create a temp node and obtain data
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		printf("\nEnter the coefficient: ");
		scanf("%d", &temp->coeff);
		printf("\nEnter the exponent: ");
		scanf("%d", &temp->exp);
		temp->link = NULL;
		//temp node ready
		phead = insert_term(phead, temp);
	}
	printf("Enter the number of terms in the second polynomial: ");
	scanf("%d", &len2);

	printf("\nEnter the coefficients and exponents of each term, in decreasing order of exponents:- \n ");
	for(i=0; i < len2; i++) {
		//create a temp node and obtain data
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		printf("\nEnter the coefficient: ");
		scanf("%d", &temp->coeff);
		printf("\nEnter the exponent: ");
		scanf("%d", &temp->exp);
		temp->link = NULL;
		//temp node ready
		qhead = insert_term(qhead, temp);
	}
}

struct node* add_poly(struct node *head1, struct node *head2, struct node *head3) {
	struct node *ptr1, *ptr2;

	ptr1 = head1;
	ptr2 = head2;
	head3 = NULL;

	while((ptr1 != NULL) && (ptr2 != NULL)) {
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		if(ptr1->exp == ptr2->exp) {
			temp->coeff = ptr1->coeff + ptr2->coeff;
			temp->exp = ptr1->exp;
			temp->link = NULL;
			ptr1 = ptr1->link, ptr2 = ptr2->link;

		} else if(ptr1->exp < ptr2->exp) {
			temp->coeff = ptr2->coeff;
			temp->exp = ptr2->exp;
			temp->link = NULL;
			ptr2 = ptr2->link;
		} else {
			temp->coeff = ptr1->coeff;
			temp->exp = ptr1->exp;
			temp->link = NULL;
			ptr1 = ptr1 ->link;
		}
		head3 = insert_term(head3, temp);
	}

	while(ptr1 != NULL) {
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		temp->coeff = ptr1->coeff;
		temp->exp = ptr1->exp;
		temp->link = NULL;
		ptr1 = ptr1 ->link;
		head3 = insert_term(head3, temp);
	}

	while(ptr2 != NULL) {
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		temp->coeff = ptr2->coeff;
		temp->exp = ptr2->exp;
		temp->link = NULL;
		ptr2 = ptr2 ->link;
		head3 = insert_term(head3, temp);
	}
	return head3;
}

struct node* multiply_poly(struct node* ahead, struct node* bhead, struct node* chead) {
	struct node *ptr1;
	struct node *ptr2;

	ptr1 = ahead;
	ptr2 = bhead;

	while (ptr1 != NULL) {        // iterates thru. first polynomial
		if (ptr2 != NULL) {       // takes each element of second polynomial
            // make a new node with product of ptr1 term and ptr2 term.
			struct node *temp = (struct node *) malloc(sizeof(struct node));
			temp->coeff = ((ptr1->coeff) * (ptr2->coeff));
			temp->exp = ((ptr1->exp) + (ptr2->exp));
			temp->link = NULL;

            //add that node to the product polynomial. It will automatically sorted.
			chead = add_poly(chead, temp, chead);
			ptr2 = ptr2->link;
		} else {
			ptr2 = bhead;
			ptr1 = ptr1->link;
			
		}
	}
	return chead;
}

int main() {
	int optionNum;
	printf("\t\tPolynomial Addition and Multipilication using LinkedList\n\n");

	input_poly();

	do {	

		printf("Options\n");
		printf("1. Polynomial Multipilication\n");
		printf("2. Polynomial Addition\n");
		printf("3. EXIT\n");
		printf("\nEnter your option number: ");
		scanf("%d", &optionNum);

		if (optionNum == 1) {
			producthead = multiply_poly(phead, qhead, producthead);
			display_poly(producthead);
		} else if(optionNum == 2) {
			sumhead = add_poly(phead, qhead, sumhead);
			display_poly(phead);
			display_poly(qhead);
			display_poly(sumhead);
		} else if (optionNum == 3) {
			break;
		} else {
			printf("Invalid option number.\n");
		}
	} while(1);
}
