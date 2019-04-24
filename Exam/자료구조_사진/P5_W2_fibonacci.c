/*
	피보나치 예제
*/
#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include <stdio.h>
#include<stdlib.h>

unsigned long long recursive_fibonacci(int number){
	if (number <= 1)
	{
		return number;
	}
	else
		return recursive_fibonacci(number - 1) + recursive_fibonacci(number - 2);

}

unsigned long long iterative_fibonacci(int n) {
	long *arr;
	arr = (long*)malloc(sizeof(long)*(n));
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < n+1; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}


int main()
{
	int num;

	unsigned int length;
	double begin, end;
	double t1, t2;
	unsigned long long val;
	printf("학번 201321479 홍지민\n");

	int MAX_LENGTH = 61;

	for (length = 1; length<=MAX_LENGTH ; length += 5)
	{
		begin = clock();
		val = recursive_fibonacci(length);
		end = clock();
		t1 = (end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		val = iterative_fibonacci(length);
		end = clock();
		t2 = (end - begin) / CLOCKS_PER_SEC;
		printf("length : %d\n Recursive: %.3lf sec\nIterative : %.3lf sec\n", length, t1, t2);
	}
	scanf("%d", &num);

	return 0;
}
