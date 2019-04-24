// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct Qnode {
	element data;
	struct Qnode *next;
} Qnode;

typedef struct {
	Qnode *front, *rear;
}LQtype;


LQtype* create() {
	LQtype *LQ;
	LQ = (LQtype*)malloc(sizeof(LQtype));

	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;
}


int isEmpty(LQtype *LQ) {
	if (LQ->front == NULL) {
		printf("%Empty!\n");
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue(LQtype *LQ,element item) {
	
	Qnode *new_node = (Qnode *)malloc(sizeof(Qnode));
	new_node->data = item;
	new_node->next = NULL;

	if (LQ->front == NULL) {
		LQ->front = new_node;
		LQ->rear = new_node;
	}
	else {
		LQ->rear->next = new_node;
		LQ->rear = new_node;
	}

}


element dequeue(LQtype *LQ) {
	Qnode *old = LQ->front;
	element item;
	if (isEmpty(LQ)) {
		return 0;
	}
	else {
		item = old->data;
		LQ->front = LQ->front->next;
		if (LQ->front == NULL) {
			LQ->rear = NULL;
		}
		free(old);
		return item;
	}
}

void printLQ(LQtype *LQ) {
	Qnode *tmp;
	tmp = (Qnode*)malloc(sizeof(Qnode));

	tmp = LQ->front;
	printf("[ ");
	while (tmp != NULL) {
		printf("%c ", tmp->data);
		tmp = tmp->next;
	}
	printf("]");

}



int main()
{
	LQtype *LQ = create();
	element data;

	printf("\n ************Queue ***********\n");

	printf("\n enqueue J>>"); enqueue(LQ, 'J'); printLQ(LQ);
	printf("\n enqueue A>>"); enqueue(LQ, 'A'); printLQ(LQ);
	printf("\n enqueue G>>"); enqueue(LQ, 'G'); printLQ(LQ);
	printf("\n enqueue U>>"); enqueue(LQ, 'U'); printLQ(LQ);
	printf("\n enqueue U>>"); enqueue(LQ, 'U'); printLQ(LQ);


	printf("\n dequeue >>"); data=dequeue(LQ); printLQ(LQ);
	printf("\t dequeue data: %c", data);
	
	printf("\n dequeue >>"); data = dequeue(LQ); printLQ(LQ);
	printf("\t dequeue data: %c", data);

	printf("\n dequeue >>"); data = dequeue(LQ); printLQ(LQ);
	printf("\t dequeue data: %c", data);

	printf("\n dequeue >>"); data = dequeue(LQ); printLQ(LQ);
	printf("\t dequeue data: %c", data);

	printf("\n dequeue >>"); data = dequeue(LQ); printLQ(LQ);
	printf("\t dequeue data: %c", data);
	getchar();

	element value;


	return 0;
}
