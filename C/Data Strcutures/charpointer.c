/*
* charpointer.c
*
*  Created on: 11-Sep-2018
*      Author: Dzilva
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	char* name;
	char* mail;
	int number;
	struct Node* link;
};

void print(struct Node* head);
void insertAtbeg(struct Node** head, char* name, char* mail, int value);

int main(int argc, char **argv) {
	struct Node* head = NULL;
	//printf(" %d \n",sizeof(struct Node));
	insertAtbeg(&head, "john", "john@cn.com", 979988);
	insertAtbeg(&head, "jz", "jz@cn.com", 9798);
	insertAtbeg(&head, "dj", "dj@cn.com", 9788);
	insertAtbeg(&head, "jc", "jc@cn.com", 9798);
	print(head);
	return 0;
}

void insertAtbeg(struct Node** head, char* name, char* mail, int value) {
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node*));
	(*temp).name = name;
	temp->mail = mail;
	temp->number = value;
	temp->link = *head;
	*head = temp;
}

void print(struct Node* head) {
	printf("\n list is : ");
	while(head != NULL) {
		printf("\nName : %s ", head->name);
		printf("\nMail : %s ", head->mail);
		printf("\nNumber : %d ", head->number);
		head = head->link;
	}
}
