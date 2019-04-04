// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define max_size (5)

typedef int element;

typedef struct Stack {
	element *contents;
	int top;
	int size;
}Stack;


Stack create() {
	Stack *st;
	st = (Stack*)malloc(sizeof(Stack));
	st->contents = (element*)malloc(sizeof(element)*max_size);

	st->size = 0;
	st->top = -1;
	return *st;
}

int is_full(Stack *st) {

	return (st->size == max_size);
}

int is_empty(Stack *st) {

	return (st->top == -1);
}

void push(Stack *st, element value) {
	if (is_full(st)) {
		printf("Error: Stack is already full!\n");
	}
	else {
		st->size++;
		st->top++;
		st->contents[st->top] = value;
	}
}

element pop(Stack *st) {
	element tmp;
	tmp = st->contents[st->top];
	st->top--;
	st->size--;
	return tmp;
}

element peek(Stack *st) {
	element tmp;
	tmp = st->contents[st->top];
	return tmp;
}

void printSt(Stack *st) {
	for (int i = 0; i < st->size; i++) {
		printf("%d ", st->contents[i]);
	}
	printf("\n");
}





int main()
{
	Stack s = create();

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
		else if (strcmp(command, "isfull") == 0)
		{
			is_full(&s);
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "printall") == 0)
		{
			printSt(&s);
		}
	}

	getchar();
	return 0;
}
