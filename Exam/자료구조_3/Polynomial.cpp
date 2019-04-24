// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_DEGREE 50

typedef struct polynomial {
	int degree;
	float value[MAX_DEGREE];
}Poly;


int max(int a,int b) {
	if (a > b) {
		return a;
	}
	else
		return b;
}

Poly addPoly(Poly a, Poly b) {

	Poly c;

	int a_index = 0, b_index = 0, c_index = 0;

	int a_degree = a.degree, b_degree = b.degree;

	c.degree = max(a.degree, b.degree);

	while (a_index <= a.degree&& b_index <= b.degree)
	{
		if (b_degree == a_degree) {
			c.value[c_index] = a.value[a_index] + b.value[b_index];
			a_index++;
			b_index++;
		}
		else if (a_degree > b_degree) {
			c.value[c_index] = a.value[a_index];
			a_index++;
			a_degree--;
		}
		else if (a_degree < b_degree) {
			c.value[c_index] = b.value[b_index];
			b_index++;
			b_degree--;
		}
		c_index++;

	}

	return c;
}
void printpoly(Poly p) {
	int degree;
	int i;
	degree = p.degree;

	for (i = 0; i <= p.degree; i++)
	{
		printf(" %3.0fx^%d", p.value[i],degree--);
	}
}
int main()
{
	Poly a = { 3,{4,3,5,0} };
	Poly b = { 4,{3,1,0,2,1} };

	Poly c;

	c = addPoly(a, b);

	printf("\n a(x)="); printpoly(a);
	printf("\n b(x)="); printpoly(b);
	printf("\n c(x)="); printpoly(c);

	getchar();
	return 0;
}
