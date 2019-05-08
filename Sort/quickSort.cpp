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
	
	int pivot = arr[left];
	int low = left;
	int high = right + 1;

	do {
		do {
			low++;

		} while (arr[low] < pivot && low <= right);
		do {
			high--;
		} while (arr[high] > pivot && high >= left);
		if (low < high) {
			swap(&arr[high], &arr[low]);
		}
	} while (low < high);

	swap(&arr[left], &arr[high]);

	return high;
}


void quickSort(int *arr, int left, int right) {
	
	if (left < right) {
		int p = partition(arr, left, right);

		quickSort(arr, left, p-1);
		quickSort(arr, p+1, right);
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
