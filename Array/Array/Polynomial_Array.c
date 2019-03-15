// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*a

A(x) = 3x^6+ 2x^5+ 4

B(x)= x^4 + 10x^3 + 3x^2 +5



*/

typedef struct Polynomial_matrix {
	int exp;
	float coef;
} ;

void add_2Array(struct Polynomial_matrix *a, struct Polynomial_matrix *b,struct Polynomial_matrix *d, int a_ix,int b_ix,int ix)
{
	if (a_ix < 3 || b_ix < 4)
	{
		if (a[a_ix].exp > b[b_ix].exp)
		{
			d[ix].exp = a[a_ix].exp;
			d[ix].coef = a[a_ix].coef;
			add_2Array(a, b, d, a_ix + 1, b_ix, ix + 1);
		}
		else if (a[a_ix].exp == b[b_ix].exp)
		{
			d[ix].exp = a[a_ix].exp;
			d[ix].coef = a[a_ix].coef + b[b_ix].coef;
			add_2Array(a, b, d, a_ix + 1, b_ix + 1, ix + 1);
		}
		else if (a[a_ix].exp < b[b_ix].exp)
		{
			d[ix].exp = b[b_ix].exp;
			d[ix].coef = b[b_ix].coef;
			add_2Array(a, b, d, a_ix, b_ix + 1, ix + 1);
		}

	}
}

int main()
{
	struct Polynomial_matrix a[100];

	a[0].exp = 6;
	a[0].coef = 3;
	a[1].exp = 5;
	a[1].coef = 2;
	a[2].exp = 0;
	a[2].coef = 4;

	struct Polynomial_matrix b[100];

	b[0].exp = 4;
	b[0].coef = 1;
	b[1].exp = 3;
	b[1].coef = 10;
	b[2].exp = 2;
	b[2].coef = 3;
	b[3].exp = 0;
	b[3].coef = 1;

	struct Polynomial_matrix d[100];

	add_2Array(a, b, d, 0, 0, 0);
	for (int i=0; i < 5;i++) {
		printf("%d %f \n", d[i].exp, d[i].coef);
	}


	return 0;
}
