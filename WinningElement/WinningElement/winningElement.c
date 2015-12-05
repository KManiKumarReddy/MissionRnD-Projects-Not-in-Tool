#include <stdio.h>
#include <limits.h>
#define MAX 15

struct testCases {
	int arr[MAX], len, seek, adjacent, result;
} cases[] = {
	{
		{1, 2, 3, 4, 5, 4, 3, 2, 1}, 9, 3, 0, 4
	}
};

int winningElement1(int arr[], int len, int seek, int adjacent) {
	int incr = 1 + adjacent, maxSum = INT_MIN, sum, i, j, winningIndex = -1;
	for (i = seek / 2; i < len - (seek - 1) / 2; i++) {
		sum = 0;
		for (j = 0; j <= seek / 2 && (i - j) >= 0; j += incr)
			sum += arr[i - j];
		for (j = 1; j <= (seek - 1) / 2 && (i + j) < len; j += incr)
			sum += arr[i + j];
		if (sum > maxSum) {
			winningIndex = i;
			maxSum = sum;
		}
	}
	return winningIndex;
}

int winningElement2(int arr[], int len, int seek, int adjacent) {
	if (len < seek)
		return -1;
	int incr = 1 + adjacent, maxSum = INT_MIN, sum, i, j, winningIndex = 0;
	for (i = 0; i < seek; i += incr) {
		sum += arr[i];
	}
	maxSum = sum;
	for (i = 1; i <= len - seek; i++) {
		sum -= arr[i];
		sum += arr[i + seek];
		if (sum > maxSum) {
			maxSum = sum;
			winningIndex = i;
		}
	}
	return winningIndex;
}

int main(void) {
	printf("%d", winningElement2(cases[0].arr, cases[0].len, cases[0].seek, cases[0].adjacent));
	getchar();
}