/**
 * sort01.c
 * 13-09-2015
 * Mani Kumar Reddy K
 * Sorting array of only 0s and 1s
*/


#include <stdio.h>
#define MAX 15

struct testCases {
	int input[MAX], size, output[MAX];
} cases[] = {
	{
		{ 0, 0, 0, 0 },
		4,
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 1 },
		4,
		{ 1, 1, 1, 1 }
	},
	{
		{ 1, 0, 1, 0, 1 },
		5,
		{ 0, 0, 1, 1, 1 }
	},
	{
		{ 0, 0, 0, 1, 1, 1 },
		6,
		{ 0, 0, 0, 1, 1, 1 }
	},
	{
		{ 0, 0, 0, 0 },
		4,
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 },
		4,
		{ 0, 1, 1, 1 }
	},
	{
		{ 1, 0, 0, 0 },
		4,
		{ 0, 0, 0, 1 }
	}
};


void sort1(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				arr[j] = 0;
				arr[j + 1] = 1;
			}
}

void sort2(int arr[], int n) {
	int count0 = 0, i;
	for (i = 0; i < n; i++)
		if (!arr[i])
			count0++;
	for (i = 0; i < count0; i++)
		arr[i] = 0;
	for (; i < n; i++)
		arr[i] = 1;
}

void sort3(int arr[], int n) {
	int count = 0, i;
	for (i = 0; i < n; i++)
		count += arr[i];
	while (count--)
		arr[--i] = 1;
	while (i--)
		arr[i] = 0;
}

void sort4(int arr[], int n) {
	int i = 0, j = n;
	while (1) {
		while (!arr[i])
			i++;
		while (arr[j])
			j--;
		if (i < j) {
			arr[i] = 0;
			arr[j] = 1;
		}
		else break;
	}
}

int arrCmp(int a[], int b[], int n) {
	int i;
	for (i = 0; i < n; i++)
		if (a[i] != b[i])
			return 0;
	return 1;
}

void tester(int n) {
	int a[MAX], i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < cases[i].size; j++)
			a[j] = cases[i].input[j];
		sort1(a, cases[i].size);
		if (arrCmp(a, cases[i].output, cases[i].size))
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 1);
		for (j = 0; j < cases[i].size; j++)
			a[j] = cases[i].input[j];
		sort2(a, cases[i].size);
		if (arrCmp(a, cases[i].output, cases[i].size))
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 2);
		for (j = 0; j < cases[i].size; j++)
			a[j] = cases[i].input[j];
		sort3(a, cases[i].size);
		if (arrCmp(a, cases[i].output, cases[i].size))
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 3);
		for (j = 0; j < cases[i].size; j++)
			a[j] = cases[i].input[j];
		sort4(a, cases[i].size);
		if (arrCmp(a, cases[i].output, cases[i].size))
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 4);
	}
}

int main(void) {
	tester(7);
	getchar();
}