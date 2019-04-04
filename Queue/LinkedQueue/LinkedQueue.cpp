// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef int element;

typedef struct Queue_type *Queue;

typedef struct node {
	element value;
	struct node *next;
} node;

struct Queue_type {
	node *front;
	node *rear;
	element size;
} ;

Queue create() {
	Queue q  ; 
	q=(Queue)malloc(sizeof(struct Queue_type));

	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}

void enqueue(Queue q, int value) {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp->value = value;
	tmp->next = NULL;
	if (q->front == NULL && q->rear==NULL) {
		q->front = tmp;
		q->rear = tmp;
	}
	else {
		q->rear->next = tmp;
		q->rear = tmp;
	}
}

void printQ(Queue q) {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp = q->front;
	while (tmp!= NULL) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

element dequeue(Queue q) {
	element tmp;
	tmp = q->front->value;
	q->front = q->front->next;
	return tmp;
}

void peek(Queue q) {
	printf("%d\n", q->front->value);
}

int main() {
	char command[20];
	int value;

	Queue Que;
	
	Que = create();

	while (1) {
		scanf("%s", command);
		if (strcmp("enqueue", command) == 0) {
			scanf("%d", &value);
			enqueue(Que, value);
			printQ(Que);
		}
		else if (strcmp("dequeue", command) == 0) {
			dequeue(Que);
			printQ(Que);
		}
		else if (strcmp("dequeue", command) == 0) {
			dequeue(Que);
		}
		else if (strcmp("print", command) == 0) {
			printQ(Que);
		}
		else if (strcmp("peek", command) == 0) {
			peek(Que);
		}
	}
	return 0;
}

