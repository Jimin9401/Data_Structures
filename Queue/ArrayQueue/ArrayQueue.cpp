// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


typedef int element;

#define max_size (5)


typedef struct ArrayQueue {
	element *contents;
	element front;
	element rear;

}ArrayQueue;
int is_full(ArrayQueue *q) {

	return (q->front == ((q->rear + 1) % max_size));
}

int is_empty(ArrayQueue *q) {

	return (q->front == q->rear);
}


ArrayQueue create() {

	ArrayQueue q;
	q.contents = (element*)malloc(sizeof(element)*max_size);
	q.front = 0;
	q.rear = 0;

	return q;
}

void enqueue(ArrayQueue *q,element value) {

	if (is_full(q)) {
		printf("Full!!");
	}
	else {
		q->rear++;
		q->contents[q->rear] = value;
	}

}

element dequeue(ArrayQueue *q) {
	element tmp = q->contents[q->front%10];	
	q->front++;
	return tmp;
}

void printQ(ArrayQueue *q) {
	for (int i = q->front+1; i <= q->rear; i++) {
		printf("%d ", q->contents[i]);
	}
	printf("\n");
}

void peek(ArrayQueue *q) {
	printf("%d", q->contents[q->front+1]);
	printf("\n");
}


int main()
{
	ArrayQueue Que;
	
	char command[20];
	int value;
	Que = create();

	while (1) {
		scanf("%s", command);
		if (strcmp("enqueue", command) == 0) {
			scanf("%d", &value);
			enqueue(&Que, value);
			printQ(&Que);
		}
		else if (strcmp("dequeue", command) == 0) {
			dequeue(&Que);
			printQ(&Que);
		}
		else if (strcmp("dequeue", command) == 0) {
			dequeue(&Que);
		}
		else if (strcmp("print", command) == 0) {
			printQ(&Que);
		}
		else if (strcmp("peek", command) == 0) {
			peek(&Que);
		}
	}

	return 0;
}
