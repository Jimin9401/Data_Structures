// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char ch = 'c';
	char *chptr = &ch;

	int i = 20;
	int *intptr = &i;

	char *ptr = "I am a string";

	printf("%c %d %c %d %d %c %s\n",
		*chptr, intptr, *ptr, ptr, ptr + 5, *(ptr + 5), ptr);



	return 0;
}
