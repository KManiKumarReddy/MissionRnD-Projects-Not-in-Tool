#include <stdio.h>

struct testCases {
	int arr[10000], n;
} cases[] = {
	{
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 90,100,199,226,235,16, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 14
	},
	{
		{ 1, 2, 1, 0 }, 1
	},
	{
		{ 1, 2, 3, 1, 0, 0 }, 2
	},
	{
		{ 1, 2, 24, 36, 2, 0, 0, 0 }, 3
	}
};

int findN1(int * arr) {
	int i;
	for (i = 0;; i++)
		if (arr[i + 1] < arr[i])
			return i;
}

int findN2(int * a) {
	int n = 1;
	while (1) {
		if (a[n] > a[n + 1] && a[n + 1])
			return (n);
		else if (!a[n + 1]) {
			n -= n / 4;
		}
		else
			n *= 2;
	}
}

void tester(int n) {
	int i;
	for (i = 0; i < n; i++)
		printf(findN2(cases[i].arr) == cases[i].n ? "PASS\n" : "FAIL\n");
}

int main(void) {
	tester(4);
	getchar();
}