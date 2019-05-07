// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);

	int *arr;
	arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n-1; j++) {
			if (arr[j+1] < arr[j]) {
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
				for (int k = 0; k < n; k++) {
					printf("%d ", arr[k]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
