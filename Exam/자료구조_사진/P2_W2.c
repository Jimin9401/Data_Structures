// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct st {
	int a;
	char ch;
}st;
int main()
{

	st obj;  //object�̱⿡ ���� �޸� �Ҵ��� �ʿ䰡 ����.
	
	st *stobj = &obj;

	stobj->a = 5;
	stobj->ch = 'a';


	printf("\n %d %c\n", stobj->a, stobj->ch);
	printf("\n %d %c\n", obj.a, obj.ch);

	getchar();








	return 0;
}
