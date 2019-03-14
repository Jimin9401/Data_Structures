/*

	Recursion (��� �Լ�)

	loop�� ������ Base case�� �ݺ������� ���� �ؾ��ϴ� Recursion Case�� ����.

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int factorial(int n) {

	if (n <= 1) {
		return 1; //base case
	}
	else 
		return n * factorial(n - 1); // recursion case
}

int fibonacci(int n) {

	if (n <= 1) {
		return n;
	}
	else 

		return fibonacci(n - 1) + fibonacci(n - 2);
}



int main()
{
	int number;

	scanf("%d", &number);

	printf("Factorial Example\n");
	printf("%d\n", factorial(number));

	printf("Fibonacci Example\n");
	printf("%d\n", fibonacci(number));


	return 0;
}
