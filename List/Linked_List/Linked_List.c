// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node {
	int value;
	struct node *after;
}node;

void add_first(node **ptr_head, node *new_node) {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));

	tmp->after = new_node;
	new_node->after = *ptr_head;
	*ptr_head = tmp;
}

void add_last(node **ptr_head,node *new_node) {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp = *ptr_head;

	while(tmp->after!=NULL){
	tmp = tmp->after;
	}
	tmp->after = new_node; // ¤µ¤² ¹¹Áö? ÀÌ°Ô ¿ÖµÊ?????????
}

void status(node **ptr_head) {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp = *ptr_head;
	while (tmp!= NULL) {
		printf(" %d", tmp->value);
		tmp = tmp->after;
	}
	printf("\n");
}

void modify(node **ptr_head, int ix, int value4modify) {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp = *ptr_head;
	for (int i = 0; i < ix; i++) {
		tmp = tmp -> after;
	}
	tmp->value = value4modify;
}

void eliminate(node **ptr_head, int ix) {
	node *prev;
	prev = (node*)malloc(sizeof(node));
	prev = *ptr_head;
	node *skip;
	skip = (node*)malloc(sizeof(node));
	skip = *ptr_head;

	for (int i = 0; i < ix-1; i++) {
		 prev= prev->after;
	}
	for (int i = 0; i < ix +1; i++) {
		skip= skip->after;
	}
	prev->after = skip;
}

int main()
{
	node *head;

	int initial_state;
	int ix;
	int value4modify;

	
	head = (node*)malloc(sizeof(node));
	head->after = NULL;
	
	printf("Initial State: ");
	scanf("%d", &initial_state);

	head->value = initial_state;

	char command[20];

	while (1) {
		scanf("%s", command);
		if (strcmp(command, "append") == 0) {
			node *new_node;
			new_node = (node*)malloc(sizeof(node));
			new_node->after = NULL;
			scanf("%d", &(new_node->value));
			add_last(&head, new_node);
		}
		else if (strcmp(command, "first") == 0) {
			node *new_node;
			new_node = (node*)malloc(sizeof(node));
			new_node->after = NULL;
			scanf("%d", &(new_node->value));
			add_first(&head, new_node);
		}
		else if (strcmp(command, "modify") == 0) {
			printf("index:");
			scanf("%d",&ix);
			printf("to which value?:");
			scanf("%d", &value4modify);
			modify(&head, ix, value4modify);
		}
		else if (strcmp(command, "status") == 0) {
			status(&head);			
		}

		else if (strcmp(command, "eliminate") == 0) {
			scanf(" %d", &ix);
			eliminate(&head, ix);
		}
	}
	return 0;
}
