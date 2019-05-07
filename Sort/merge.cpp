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

int sort[1000];

void merge(int *arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			sort[k] = arr[i];
			k++;
			i++;
		}
		else {
			sort[k] = arr[j];
			k++;
			j++;
		}
	}
	if (i > mid) {
		for (int l = j; l <= right; l++) {
			sort[k] = arr[l];
			k++;
		}
	}
	else{
		for (int l = i; l <= mid; l++) {
			sort[k] = arr[l];
			k++;
		}
	}
	for (int l = left; l <= right; l++) {
		arr[l] = sort[l];
	}
}




void merge_sort(int *arr,int left, int right) {
	
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}





int main() {
	int n;
	scanf("%d", &n);
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
