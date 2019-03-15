/*

Polynomial Representation(1)

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Sparse_mat {
	int x_coordinate;
	int y_coordinate;
	int value;
};

void convert_2_dense(int **arr1,struct Sparse_mat *arr2,int w,int h,int *k)
{
	int i = 0;
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			if (arr1[x][y] != 0) {
				arr2[i].x_coordinate = x;
				arr2[i].y_coordinate = y;
				arr2[i].value = arr1[x][y];
				i++;
			}
		}
	}
	*k = i;
}

int main()
{
	int **arr;

	struct Sparse_mat s_matrix[100];

	int w, h;

	scanf("%d %d", &w,&h);
	arr = (int**)malloc(sizeof(int*)*w);
	for (int i = 0; i < w; i++) {
		arr[i] = (int*)malloc(sizeof(int)*h);
	}
	printf("insert coordinates\n");

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int k = 0;
	convert_2_dense(arr, s_matrix, w, h, &k);
	printf("x\ty\tvalue\n\n");
	for (int i = 0; i < k; i++) 
	{
		printf("%d\t%d\t%d\n", s_matrix[i].y_coordinate, s_matrix[i].x_coordinate, s_matrix[i].value);
	}
	return 0;
}
