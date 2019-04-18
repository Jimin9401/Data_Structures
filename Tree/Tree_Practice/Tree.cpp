// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;


typedef struct node {
	element data;
	struct node *left, *right;
};


node *create() {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));

	
	tmp->right = NULL;
	tmp->left = NULL;
	
	return tmp;
}

void link(node *Tree,element number) {
	node *new_node;
	if (Tree->data > number) {
		if (Tree->left == NULL) {
			new_node = (node*)malloc(sizeof(node));
			new_node->data = number;

			new_node->left = NULL;
			new_node->right = NULL;

			Tree->left = new_node;
		}
		else {
			link(Tree->left, number);
		}

	}
	else {
		if (Tree->right == NULL) {
			new_node = (node*)malloc(sizeof(node));
			new_node->data = number;

			new_node->left = NULL;
			new_node->right = NULL;

			Tree->right = new_node;
		}
		else {
			link(Tree->right, number);
		}
	}
}

void pre(node *tree) {

	if (tree != NULL) {
		printf("%d\t", tree->data);
		pre(tree->left);
		pre(tree->right);
	}	
}

void mid(node *tree) {

	if (tree != NULL) {
		mid(tree->left);
		printf("%d\t", tree->data);
		mid(tree->right);
	}
}

void post(node *tree) {

	if (tree != NULL) {
		post(tree->left);
		post(tree->right);
		printf("%d\t", tree->data);
		
	}
}

void is_empty(node *tree, element value) {
	if (tree == NULL) {
		tree = create();
		tree->data = value;
	}

}


int main()
{
	node *a;
	
	a = create();
	a->data = 5;
	char command[20];

	element value;

	while (1) {
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {
			scanf("%d", &value);
			is_empty(a, value);
			link(a, value);
		}
		else if (strcmp(command, "pre") == 0) {
			pre(a);
		}
		else if (strcmp(command, "mid") == 0) {
			mid(a);
		}
		else if (strcmp(command, "post") == 0) {
			post(a);
		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
	}

	return 0;
}
