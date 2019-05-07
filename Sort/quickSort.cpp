// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void swap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int partition(int *arr, int left, int right) {

	int pivot =arr[left];

	int low = left+1;

	int high = right;


	while (low < high) {


		while (arr[low] < pivot && low<=right) {
			low++;
		}
		while(arr[high]>pivot && low >=left){
			high--;
		}

		if (low < high) {
			swap(&arr[low], &arr[high]);
		}

	}
	for (int i = left; i <= right; i++) {
		printf("%d ", arr[i]);
	}

	if (low != high) {
		swap(&arr[left], &arr[high]);
	}

	printf("\n");

	for (int i = left; i <= right; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return high;
}


void quickSort(int *arr, int left, int right) {
	if (left < right) {
		int q = partition(arr, left, right);
		quickSort(arr, left, q-1);
		quickSort(arr, q+1, right);
		printf("\n");
	}
}




int main()
{
	int n;
	scanf("%d", &n);
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	quickSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}




	return 0;
}
