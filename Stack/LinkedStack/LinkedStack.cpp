// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef int element;

typedef struct node {
	element value;
	node *next;
}node;


typedef struct LinkedStack {
	node *top;

}Lstack;

Lstack create() {
	Lstack *tmp;
	tmp = (Lstack*)malloc(sizeof(Lstack));

	tmp->top = NULL;

	return *tmp;
}

int is_empty(Lstack *ls) {
	return (ls->top == NULL);
}

void push(Lstack *ls,element i) {
	node *next_node;
	next_node = (node*)malloc(sizeof(node));
	next_node->value = i;
	next_node->next = NULL;
	if (is_empty(ls)) {
//		ls->head = next_node;
		ls->top = next_node;

	}
	else {
//		ls->top->next = next_node;
		next_node->next = ls->top;

		ls->top = next_node;
	}
}

element pop(Lstack *ls) {
	int i;
	node *tmp;
	
	tmp = ls->top;
	i = tmp->value;

	ls->top = ls->top->next;
	free(tmp);
	return i;
}
element peek(Lstack *ls) {
	int i;
	node *tmp;

	tmp = ls->top;
	i = tmp->value;

	return i;
}

void printS(Lstack *ls) {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));

	tmp = ls->top;
	
	while (tmp!=NULL) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}

	printf("\n");
}





int main()
{
	Lstack s = create();

	char command[20];
	int str;

	while (1) {
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			int i;
			scanf("%d", &i);
			push(&s, i);
		}
		else if (strcmp(command, "isempty") == 0)
		{
			is_empty(&s);
		}
		else if (strcmp(command, "pop") == 0)
		{
			str = pop(&s);
		}
		else if (strcmp(command, "peek") == 0)
		{
			printf("%d\n", peek(&s));
		}
		
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "printall") == 0)
		{
			printS(&s);
		}
	}


	return 0;
}
