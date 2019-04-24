// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct node {
	element value;
	struct node *next;
}node;

node *top;


int isEmpty() {
	if (top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(element item) {
	node *new_node;
	new_node = (node*)malloc(sizeof(node));

	new_node->value = item;
	new_node->next = top;


	top = new_node;

}

element pop() {
	element item;

	node *tmp = top;

	if (top == NULL) {
		printf("stack is empty");
		return 0;
	}
	else {
		item = tmp->value;
		top = tmp->next;
		free(tmp);
		return item;
	}
}

void printS() {
	node *tmp = (node*)malloc(sizeof(node));

	tmp = top;

	printf("\n[ ");
	while (tmp != NULL) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("] \n");
}




int main()
{

	element value;
	char command[20];

	printS();



	push(4);  printS();
	push(3);  printS();
	push(1);  printS();
	push(7);  printS();
	push(5);  printS();


	value = pop(); printS();
	printf("\t pop=>%d", value);

	value = pop(); printS();
	printf("\t pop=>%d", value);

	value = pop(); printS();
	printf("\t pop=>%d", value);

	value = pop(); printS();
	printf("\t pop=>%d", value);

	value = pop(); printS();
	printf("\t pop=>%d", value);





	return 0;
}
