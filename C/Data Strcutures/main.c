/*
 * main.c
 *
 *  Created on: 08-Sep-2018
 *      Author: Dzilva
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* link;
};

void print(struct Node* head);
void insertAtbeg(struct Node** head, int value);
void insertAtn(struct Node** head, int value, int position);
void deletePos(struct Node** head, int position);
void deleteVal(struct Node** head, int value);

int main(int argc, char **argv) {
	struct Node* head = NULL;
	printf(" %d \n",sizeof(struct Node));
	insertAtbeg(&head, 10);
	insertAtbeg(&head, 20);
	insertAtbeg(&head, 30);
	insertAtbeg(&head, 50);
	insertAtbeg(&head, 40);
	insertAtn(&head, 22, 1);
	insertAtn(&head, 33, 5);
	print(head);
	insertAtn(&head, 44, 3);
	print(head);
	deletePos(&head, 4);
	print(head);
	deleteVal(&head, 11); //wrong value
	print(head);
}

void insertAtbeg(struct Node** head, int value) {
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node*));
	(*temp).data = value;
	temp->link = *head;
	*head = temp;
}

void print(struct Node* head) {
	printf("\n list is : ");
	while(head != NULL) {
		printf("%d ", head->data);
		head = head->link;
	}
}

void insertAtn(struct Node** head, int value, int position) {
	struct Node* tempValue = malloc(sizeof(struct Node*));
	struct Node* temp1 = NULL;
	tempValue->data = value;
	temp1 = *head;
	if(position == 1) {
		tempValue->link = *head;
		*head = tempValue;
		return;
	}
	for (int i = 0; i < position-2; ++i) {
		temp1 = temp1->link;
	}
	tempValue->link = temp1->link;
	temp1->link = tempValue;
}

void deletePos(struct Node** head, int position) {
	struct Node* temp1 = *head;
	if(position == 1) {
		*head = temp1->link;
		free(temp1);
		return;
	}
	for (int i = 0; i < position-2; ++i) {
		temp1 = temp1->link;
	}
	struct Node* temp2 = temp1->link;
	temp1->link = temp2->link;
	free(temp2);
}

void deleteVal(struct Node** head, int value) {
	struct Node* temp1 = *head;
	if(temp1->data == value) {
		*head = temp1->link;
		free(temp1);
		return;
	}
	struct Node* prev = NULL;
	while(temp1->link != NULL && temp1->data != value) {
		prev = temp1;
		temp1 = temp1->link;
	}
    // If key was not present in linked list
    if (temp1->link == NULL) {
    	return;
    }
	prev->link = temp1->link;
	free(temp1);
}
