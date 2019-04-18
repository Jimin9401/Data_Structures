
#define _CRT_SECURE_NO_WARNINGS

#define max_size (129)

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct heap {
	element data[max_size] = { INT_MAX };
	element key;
}heap;

heap *create() {
	heap *tmp;
	tmp = (heap*)malloc(sizeof(heap));
	tmp->key = 0;

	return tmp;
}

void push(heap *arr, element value) {
	arr->key++;
	element i = arr->key;
	arr->data[arr->key] = value;
	element tmp;

	while ((i/2  !=0) && (arr->data[i] > arr->data[i / 2]))
	{
		tmp = arr->data[i];
		arr->data[i] = arr->data[i / 2];
		arr->data[i / 2] = tmp;
		i /= 2;
	}
}

element pop(heap *arr) {
	element pop_value;
	pop_value = arr->data[1];

	arr->data[1] = arr->data[arr->key];
	arr->key--;

	element i = 1;
	element tmp;

	while ((arr->data[i] < arr->data[i * 2]) || (arr->data[i] < arr->data[i * 2 + 1])) {
		if (i * 2 <= arr->key && (arr->data[i * 2] > arr->data[i * 2 + 1])) {
			tmp = arr->data[i];
			arr->data[i] = arr->data[i * 2];
			arr->data[i * 2] = tmp;
			i *= 2;
		}
		else if (i * 2 + 1 <= arr->key && (arr->data[i * 2] <= arr->data[i * 2 + 1])) {
			tmp = arr->data[i];
			arr->data[i] = arr->data[i * 2 + 1];
			arr->data[i * 2 + 1] = tmp;
			i = i * 2 + 1;
		}
		else {
			break;
		}
	}
	return pop_value;
}

void print(heap *arr)
{
	for (int i = 1; i <= arr->key; i++)
	{
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

void sort(heap *arr) {
	heap *a = arr;
	element k = a->key;
	for (int i = 0; i < k; i++) {
		printf("%d ", pop(a));
	}
	printf("\n");
}

int main()
{
	char command[20];

	heap *heapnode;
	heapnode = create();
	element value;
	while (1) {
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {

			scanf("%d", &value);
			push(heapnode, value);
		}
		else if (strcmp(command, "print") == 0) {
			print(heapnode);

		}

		else if (strcmp(command, "pop") == 0) {

			printf("%d\n", pop(heapnode));
		}
		else if (strcmp(command, "sort") == 0) {
			sort(heapnode);
		}
	}
	return 0;
}