#include <stdio.h>
#include <limits.h>

// test cases
struct testCases {
	// input number
	char n[1001];
	// output result
	int res;
} cases[] = {
	// some random big 11 multiple with even digits
	{
		"183315", 1
	},
	// some random big 11 multiple with even digits
	{
		"121", 1
	},
	// some random big 11 multiple with even digits
	{
		"22", 1
	},
	// test case for 0
	{
		"0", 1
	},
	// test case for 1
	{
		"1", 0
	},
	// some random big 11 multiple with odd digits
	{
		"12221", 1
	},
	{
		"132", 1
	},
	{
		"546412", 0
	}
};

/*
int divisibleByEleven1(char * n) {
	int num = 0, i;
	for (i = 0; n[i]; i++)
		num = num * 10 + (n[i] - 48);
	return !(num % 11);
}*/

int divisibleByEleven1(char * n) {
	int sum = 0, i;
	// alternating sum of digits
	for (i = 0; n[i]; i ++)
		if(i % 2)
			sum -= (n[i] - '0');
		else
			sum += (n[i] - '0');
	return !(sum % 11);
}

int sumAlternateDigits(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 100;
	}
	return sum;
}

// Solution without using modulus
int divisibleByEleven2(char * n) {
	int sum = 0, i;
	// alternating sum of digits
	for (i = 0; n[i]; i++)
		if (i % 2)
			sum -= (n[i] - '0');
		else
			sum += (n[i] - '0');
	if (sum < 0)
		sum = -sum;
	while (sum >= 11) {
		sum = sumAlternateDigits(sum) - sumAlternateDigits(sum / 10);
		if (sum < 0)
			sum = -sum;
	}
	if (sum)
		return 0;
	return 1;
}

// tester function
void tester(int size) {
	int i;
	for (i = 0; i < size; i++)
		printf(divisibleByEleven1(cases[i].n) == cases[i].res ? "PASS\n" : "FAIL FUN:1\n");
	for (i = 0; i < size; i++)
		printf(divisibleByEleven2(cases[i].n) == cases[i].res ? "PASS\n" : "FAIL FUN:2\n");
}

int main(void) {
	tester(8);
	// That's all! :)
	getchar();
}