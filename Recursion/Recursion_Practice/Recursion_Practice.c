/*
	Recursion 쉬운 예제들

	출처: http://blog.naver.com/PostView.nhn?blogId=fewus28&logNo=220966348725

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int sum(n){
	if (n == 0)
		return 0;
	else
		return n + sum(n - 1);

}

void print_number(int n) {

	if (n < 10)
		printf("%d\n", n % 10);

	else {
		print_number(n / 10);
		printf("%d\n", n % 10);
	}
}


int print_max(int *arr) {

	if (*arr > *(arr + 1)){
		print_max(arr+1);
		return *arr;
	}
	else {
		print_max(arr+1);
		return *(arr + 1);
	}
}



int main()
{
	int number;

	scanf("%d", &number);

	printf("1.Summation Example\n");
	printf("%d\n\n", sum(number));


	printf("2.print Large number\n");
	print_number(number);

	printf("3.Summation Example\n");
	printf("%d\n\n", sum(number));

	int array_size;
	int *arr1;

	scanf("%d", &array_size);

	arr1 = (int*)malloc(sizeof(int)*array_size);
	printf("%d", sizeof(arr1));
	for (int i = 0; i < array_size; i++) {
		scanf("%d", (arr1 + i));
	}

	printf("%i", print_max(arr1));

	return 0;
}
