// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define MAX_DEGREE 101;

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct poly {
	int degree;
	float coef;
};


void sum_2_functions(struct poly *arr,int starta, int finisha, int startb, int finishb, int avail, int highest_degree)
{

}





int main()
{
	int starta, finisha, startb, finishb, avail, highest_degree;

	struct poly func[100];

	printf("insert the highest degree in A\n");
	printf("degree coef\n");

	for (int i = 0; i <2; i++) {
		scanf("%d %d", func[i].coef, func[i].degree);
	}

	printf("insert the highest degree in B\n");
	printf("degree coef\n");

	for (int i = 2; i < 6; i++) {
		scanf("%d %d", func[i].coef, func[i].degree);
	}


	printf("Let's sum two functions\n");


	return 0;
}
