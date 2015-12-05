#include <stdio.h>

// test cases
struct testCases {
	// input number
	char p[1001];
	// output result
	int k, res;
} cases[] = {
	{
		"183315", 1, 1
	},
	{
		"121", 1, 1
	},
	{
		"121", 80, 1
	},
	{
		"22", 90, 1
	},
	{
		"0", 1, 1
	},
	{
		"1", 1, 0
	},
	{
		"1", 4, 1
	},
	{
		"12221", 5, 1
	},
	{
		"12", 22, 1
	}
};

int divisibleByEleven1(char * p, int k) {
	long long sum = 0;
	int i, j, even = 0;
	// alternating sum of digits
	for (j = 0; j < k; j++) {
		for (i = 0; p[i]; i++, even = !even)
			if (even)
				sum -= (p[i] - '0');
			else
				sum += (p[i] - '0');
	}
	return !(sum % 11);
}

int divisibleByEleven2(char * p, int k) {
	int sum = 0, i, j, even = 0;
	// calculating num of digits
	for (i = 0; p[i]; i++);
	// if odd num of digits and even repitions, then true coz alternate sum is 0
	if (i & 1 && !(k & 1))
		return 1;
	// calculating alternate sum for p
	for (i = 0; p[i]; i++, even = !even)
		if (even)
			sum -= (p[i] - '0');
		else
			sum += (p[i] - '0');
	// true if sum is divisible by 11 or k is divisible by 11
	// because sum * k should be divisible in case of even digits or sum should be divisible in case of odd digits
	return !(sum % 11 && k % 11);
}

// tester function
void tester(int size) {
	int i;
	for (i = 0; i < size; i++)
		printf(divisibleByEleven1(cases[i].p, cases[i].k) == cases[i].res ? "PASS\n" : "FAIL FUN:1\n");
	for (i = 0; i < size; i++)
		printf(divisibleByEleven2(cases[i].p, cases[i].k) == cases[i].res ? "PASS\n" : "FAIL FUN:2\n");
}

int main(void) {
	tester(9);
	// That's all! :)
	getchar();
}