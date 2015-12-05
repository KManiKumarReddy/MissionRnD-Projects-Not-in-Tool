/**
 * multiplyothers.c
 * 13-09-2015
 * Mani Kumar Reddy K
 * Output an array with all product of all elements in array except its own index
 */

#include <stdio.h>
#define MAX 15

struct testCases {
	int input[MAX], size, output[MAX];
} cases[] = {
	{
		{ 1, 2, 3, 4, 5 },
		5,
		{ 120, 60, 40, 30, 24 }
	},
	{
		{ 1, 2, 0, 4, 5 },
		5,
		{ 0, 0, 40, 0, 0 }
	},
	{
		{ 1, 0, 1, 0, 1 },
		5,
		{ 0, 0, 0, 0, 0 }
	},
	{
		{ 11, 11, 11, 11, 11, 11 },
		6,
		{ 161051, 161051, 161051, 161051, 161051, 161051 }
	},
	{
		{0, 0, 0},
		3,
		{0, 0, 0}
	},
	{
		{ 1, 1, 1, 1 },
		4,
		{ 1, 1, 1, 1 }
	},
	{
		{ 1, 1, 1, 65536 },
		4,
		{ 65536, 65536, 65536, 1 }
	},
	{
		{ 12334 },
		1,
		{ 12334 }
	},
	{
		{ 0 },
		1,
		{ 0 }
	}
};


void productOthers1(int a[], int b[], int n) {
	if (n == 1) {
		b[0] = a[0];
		return;
	}
	int i, j;
	for (i = 0; i < n; i++) {
		b[i] = 1;
		for (j = 0; j < n; j++)
			if (i != j)
				b[i] *= a[j];
	}
}

void productOthers2(int a[], int b[], int n) {
	if (n == 1) {
		b[0] = a[0];
		return;
	}
	int i, j;
	for (i = 0; i < n; i++)
		b[i] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j)
				b[j] *= a[i];
}

void productOthers3(int a[], int b[], int n) {
	if (n == 1) {
		b[0] = a[0];
		return;
	}
	int i, index0 = -1;
	long product = 1;
	for (i = 0; i < n; i++)
		if (a[i])
			product *= a[i];
		else {
			if (index0 == -1)
				index0 = i;
			else {
				for (i = 0; i < n; i++)
					b[i] = 0;
				return;
			}
		}
		if (index0 == -1)
			for (i = 0; i < n; i++)
				b[i] = product / a[i];
		else {
			for (i = 0; i < n; i++)
				b[i] = 0;
			b[index0] = product;
		}
}

void productOthers4(int a[], int b[], int n) {
	if (n == 1) {
		b[0] = a[0];
		return;
	}
	int i;
	long product = 1;
	b[n - 1] = a[n - 1];
	for (i = n - 2; i > 0; i--)
		b[i] = b[i + 1] * a[i];
	b[0] = b[1];
	for (i = 1; i < n - 1; i++) {
		product *= a[i - 1];
		b[i] = product * b[i + 1];
	}
	b[i] = product * a[i - 1];
}

int arrCmp(int a[], int b[], int n) {
	int i;
	for (i = 0; i < n; i++)
		if (a[i] != b[i])
			return 0;
	return 1;
}

void tester(int n) {
	int temp[MAX], i;
	for (i = 0; i < n; i++) {
		productOthers1(cases[i].input, temp, cases[i].size);
		if (arrCmp(temp, cases[i].output, cases[i].size))
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 1);
		productOthers2(cases[i].input, temp, cases[i].size);
		if (arrCmp(temp, cases[i].output, cases[i].size))
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 2);
		productOthers3(cases[i].input, temp, cases[i].size);
		if (arrCmp(temp, cases[i].output, cases[i].size))
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 3);
		productOthers4(cases[i].input, temp, cases[i].size);
		if (arrCmp(temp, cases[i].output, cases[i].size))
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 4);
	}
}

int main(void) {
	tester(9);
	getchar();
}