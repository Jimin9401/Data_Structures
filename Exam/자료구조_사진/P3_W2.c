// 팩토리얼 예제

//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


long long fact(n) {
	
	long long value;
	if (n < 1) {
		printf("fact<%d> called!\n", n);
		return 1;
	}
	else {
		printf("fact<%d> called!\n", n);
		value = n * fact(n - 1);
		printf("fact<%d> return value: %lld !!\n", n, value);
		return value;
	}	
}




int main()
{
	int num;
	scanf("%d", &num);
	printf("%d", fact(num));
	return 0;
}
