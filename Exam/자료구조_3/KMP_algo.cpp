// Data_structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>


int failure[50] = { 0, };

void fail(char *pat) 
{
	int i, j;
	int n = strlen(pat);
	failure[0] = -1;
	for (j = 1; j < n; j++) {
		i = failure[j - 1];
		while (pat[j] != pat[i + 1] && i >= 0) {
			i = failure[i];
		}
		if (pat[j] == pat[i + 1]) {
			failure[j] = i + 1;
		}
		else {
			failure[j] = -1;
		}
	}
	for (int i = 0; i < sizeof(failure); i++) {
		if (i < n) {
			printf("%d ", failure[i]);
		}
	}
	printf("\n");
}

int pmatch(char *string, char *pat)
{
	int i = 0;
	int j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	while (i < lens && j < lenp) {
		if (string[i] == pat[j]) {
			i++;
			j++;
		}
		else if (j == 0) {
			i++;
		}
		else {
			j = failure[j - 1] + 1;
		}
	}

	return j = lenp ? i - lenp : -1;
}


int main()
{
	char string[] = "ABBABAABC";
	char pat[] = "ABC";

	fail(pat);

	int matched_cnt = pmatch(string, pat);
	
	if (matched_cnt == -1) {
		printf("NO pattern found\n");
	}
	else {
		printf("index of the first pattern found %d\n", matched_cnt);
	}


	getchar();

	return 0;
}
