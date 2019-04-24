// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void printHanoi(int n, char start, char work, char target) {
	if (n == 1){
		printf("disk %d from %c to %c\n",n, start,target);
	}
	else {
		printHanoi(n - 1, start, target, work);
		printf("disk %d from %c to %c\n", n,start, target);
		printHanoi(n - 1, work, start, target);
	}
}

int main()
{
	char start, work, target;
	int num_disk;

	start = 'S';
	work = 'W';
	target = 'T';

	printHanoi(4,start, work, target);
	return 0;
}

