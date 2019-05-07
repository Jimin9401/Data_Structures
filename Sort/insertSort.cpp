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
		
		for (int j = i; j >= 0; j--) 
		{
			int start_ix = j-1;
			if (arr[j] < arr[start_ix]) 
			{
				int tmp = arr[j];
				arr[j] = arr[start_ix];
				arr[start_ix] = tmp;
			}
		}


		for (int k = 0; k < n; k++) {
			printf("%d ", arr[k]);
		}

		printf("\n");
	}



	return 0;
}
