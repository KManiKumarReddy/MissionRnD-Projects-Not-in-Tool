/**
 * minrank.c
 * 13-09-2015
 * Mani Kumar Reddy K
 * Program to find rank of a number in sorted array of all its permutations
 */

#include <stdio.h>

struct testcases {
	int n, r;
} cases[] = {
	{ 231, 3 },
	{ 120, 3 },
	{ 102, 2 },
	{ 100, 2},
	{ 12345, 0 },
	{ 54321, 119 },
	{ 112, 0 },
	{ 211, 2 },
	{ 9, 0 },
	{ 0, 0 },
	{ 1111111111, 0},
	{ 23922, 8 }
};

//descending order sort
void sort(int *arr, int n) {
	int swap;
	while (n > 0) {
		for (int i = 0; i < n - 1; i++)
			if (arr[i] < arr[i + 1]) {
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
			}
		n--;
	}
}

int isMatch(long int *a, long int *b, int i) {
	while (i-- > 0)
		if (a[i] != b[i])
			return 0;
	return 1;
}

int breakValueIntoDigits(int value, int *a) {
	int size = 0;
	while (value != 0) {
		a[size++] = (value % 10);
		value /= 10;
	}
	sort(a, size);
	return size;
}

int minrank1(int n) {
	int count = 0, digitCount, i, min = 0, max = 0, digits[100], tempDigits[100], tempCount;

	digitCount = breakValueIntoDigits(n, digits);

	// calculating max possible prmutation
	for (i = 0; i < digitCount; i++) {
		max *= 10;
		max += digits[i];
	}
	for (i = digitCount - 1; i >= 0; i --) {
		min *= 10;
		min += digits[i];
	}
	for (i = min; i <= max; i ++) {
		tempCount = breakValueIntoDigits(i, tempDigits);
		while (tempCount < digitCount)
			tempDigits[tempCount++] = 0;
		if (isMatch(digits, tempDigits, digitCount)) {
			if (i == n)
				break;
			++ count;
		}
	}
	return count;
}


int fact(int n) {
	if (n < 2)
		return 1;
	else
		return n * fact(n - 1);
}

int minrank2(int n) {
	int a[15], numDigits = 0, i, j, minRank = 0;
	while (n > 0) {
		a[numDigits++] = n % 10;
		n /= 10;
	}
	for (i = numDigits - 1; i > 0; i--) {
		int count = 0, redun = 1, repCount[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		// counting diits less than current digits after it appears
		for (j = i - 1; j >= 0; j--)
			if (a[j] < a[i])
				count++;
		// counting repeated values in it
		for (j = i; j >= 0; j--)
			repCount[a[j]] ++;
		// calculating redunadncy
		for (j = 0; j < 10; j++)
			if (repCount[j] > 1)
				redun *= fact(repCount[j]);
		minRank += count * fact(i) / redun;
	}
	return minRank;
}

void tester(int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (minrank1(cases[i].n) == cases[i].r)
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 1);
		if (minrank2(cases[i].n) == cases[i].r)
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 2);
	}
}

int main(void) {
	tester(12);
	getchar();
}