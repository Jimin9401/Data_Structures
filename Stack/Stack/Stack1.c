// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef int Item; 
//의도.. 저장되는 


 typedef struct Stack_t {
	Item *contents; // 배열내에 들어가는 콘텐츠
	int size; // 스택의 사이즈
	int top; //스택에 가장 위
} *Stack;



Stack create() {
	Stack s;
	s = (Stack)malloc(sizeof(Stack));
	s->contents = (Item*)malloc(sizeof(Item));
	s->size = 100;
	s->top = -1;
	return s;
}
 
void is_empty(Stack s) {
	if (s->top == -1) {
		printf("Empty!\n");
	}
	else {
		printf("Not Empty!\n");
	}
}

void is_full(Stack s) {
	if (s->top == s->size) {
		printf("Full!\n");
	}
	else
		printf("Not Full!\n");
}

void push(Stack s, Item i) {
	s->top++;
	s->contents[s->top] = i;
}

Item pop(Stack s) {
	Item tmp;
	tmp = s->contents[s->top];
	s->top--;
	return tmp;
}

Item peek(Stack s) {
	Item tmp;
	tmp = s->contents[s->top];

	return tmp;
}

void printStack(Stack s) {
	
	for (int i=0; i <= s->top; i++) {
		printf("%d ", s->contents[i]);
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
		if (strcmp(command, "push")==0)
		{
			int i;
			scanf("%d", &i);
			push(s, i);
		}
		else if (strcmp(command, "isempty") == 0)
		{
			is_empty(s);
		}
		else if (strcmp(command, "pop") == 0)
		{
			str=pop(s);
		}
		else if (strcmp(command, "peek") == 0)
		{
			printf("%d\n", peek(s));
		}
		else if (strcmp(command, "isfull") == 0)
		{
			is_full(s);
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "printall") == 0)
		{
			printStack(s);
		}
	}
	
	getchar();
	return 0;
}
