#include <stdio.h>

struct testCases {
	char * a, *b, *r;
} cases[] = {
	{
		"123456789", "1", "123456790"
	},
	{
		"45415616464464", "6", "45415616464470"
	},
	{
		"9999999999", "1", "10000000000"
	},
	{
		"123", "0", "123"
	},
	{
		"0", "123", "123"
	},
	{
		"0", "0", "0"
	},
	{
		"12345", "54321", "66666"
	}
};


void add1(char * a, char  * b, char * r) {
	int lenA, lenB, lenR, i, sum, carry = 0;
	// calculating lengths of strings
	for (lenA = 0; a[lenA]; lenA++);
	for (lenB = 0; b[lenB]; lenB++);
	// calculating length of result
	lenR = lenA > lenB ? lenA : lenB;
	// adding each digit from ending to result
	for (i = 0; i < lenR; i++) {
		int num1 = i < lenA ? a[lenA - i - 1] - '0' : 0;
		int num2 = i < lenB ? b[lenB - i - 1] - '0' : 0;
		sum = num1 + num2 + carry;
		carry = 0;
		if (sum > 9) {
			carry = 1;
			sum -= 10;
		}
		r[i] = sum + '0';
	}
	// adding final carry if any
	if (carry) r[lenR++] = '1';
	// terminating string
	r[lenR] = '\0';
	// invertingthe resulting string
	for (i = 0; i < lenR / 2; i++) {
		char t = r[i];
		r[i] = r[lenR - i - 1];
		r[lenR - i - 1] = t;
	}
}

void add2(char * a, char  * b, char * r) {
	int lenA, lenB, i, sum, carry = 0;
	// calculating lengths of strings
	for (lenA = 0; a[lenA]; lenA++);
	for (lenB = 0; b[lenB]; lenB++);
	// making sure A is longer string
	if (lenA < lenB) {
		char * temp = a;
		a = b;
		b = temp;
		lenA += lenB;
		lenB = lenA - lenB;
		lenA -= lenB;
	}
	r[lenA] = 0;
	// adding each digit from ending to result
	for (i = lenA - 1; i >= lenA - lenB; i --) {
		sum = a[i] + b[i - (lenA - lenB)] + carry - 2 * '0';
		carry = 0;
		if (sum > 9) {
			carry = 1;
			sum -= 10;
		}
		r[i] = sum + '0';
	}
	while (i >= 0) {
		// exiting by copying a if there's no carry!
		if (!carry) {
			i++;
			while (i --) {
				r[i] = a[i];
			}
			return;
		}
		sum = a[i] + carry - '0';
		carry = 0;
		if (sum > 9) {
			carry = 1;
			sum -= 10;
		}
		r[i] = sum + '0';
		i--;
	}
	// adding final carry if any by shifting all digits to right!
	if (carry) {
		for (i = lenA; i >= 0; i--)
			r[i + 1] = r[i];
		r[0] = '1';
	}
}

void tester(int n) {
	int i, j;
	char r[1002];
	for (i = 0; i < n; i++) {
		add1(cases[i].a, cases[i].b, r);
		for (j = 0; !(cases[i].r[j] - r[j]); j++);
		printf(r[j - 1] || cases[i].r[j - 1] ? "FAIL FUN:1\n" : "PASS\n");
	}
	for (i = 0; i < n; i++) {
		add2(cases[i].a, cases[i].b, r);
		for (j = 0; !(cases[i].r[j] - r[j]); j++);
		printf(r[j - 1] || cases[i].r[j - 1] ? "FAIL FUN:1\n" : "PASS\n");
	}
}

int main(void) {
	tester(7);
	getchar();
}