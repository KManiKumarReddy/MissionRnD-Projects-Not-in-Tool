#include <stdio.h>

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

void sortChar(char *arr, int n) {
	char swap;
	while (n > 0) {
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1]) {
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

void numPermut1(unsigned int n) {
	int digitCount, i, min = 0, max = 0, digits[100], tempDigits[100], tempCount;

	digitCount = breakValueIntoDigits(n, digits);

	for (i = 0; i < digitCount; i++) {
		max *= 10;
		max += digits[i];
	}
	for (i = digitCount - 1; i >= 0; i--) {
		min *= 10;
		min += digits[i];
	}
	for (i = min; i <= max; i++) {
		tempCount = breakValueIntoDigits(i, tempDigits);
		while (tempCount < digitCount)
			tempDigits[tempCount++] = 0;
		if (isMatch(digits, tempDigits, digitCount)) {
			printf("%d\n", i);
		}
	}
}

void permute(char s[], int first, int last) {
	int i;
	char swap;
	if (first == last) 
		printf("%s\n", s);
	else {
		for (i = first; i <= last; i++) {
			swap = s[i];
			s[i] = s[first];
			s[first] = swap;
			permute(s, first + 1, last);
			swap = s[i];
			s[i] = s[first];
			s[first] = swap;
		}
	}
}

void numPermut2(unsigned int n) {
	char num[9];
	int i = 0, j;
	num[i] = 0;
	i++;
	while (n) {
		for (j = i + 1; j > 0; j--)
			num[j] = num[j - 1];
		num[0] = n % 10 + '0';
		n /= 10;
		i++;
	}
	sortChar(num, i - 1);
	permute(num, 0, i - 2);
}

int main(void) {
	numPermut2(87654321);
	getchar();
}