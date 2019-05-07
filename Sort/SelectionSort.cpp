// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <stdio.h>
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
		int start_index = i;
		for (int j = i+1; j < n; j++) {
			if (arr[start_index] > arr[j]) {
				start_index = j;
			}
		}
		int tmp= arr[start_index];
		arr[start_index]= arr[i];
		arr[i]= tmp;
		
		for (int k = 0; k < n; k++) {
			printf("%d ", arr[k]);
		}
		
		printf("\n");
	}
	



	return 0;
}
