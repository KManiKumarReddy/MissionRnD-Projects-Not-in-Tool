#include <stdio.h>

struct testCases {
	char num1[101], num2[100], result[101];
}cases[] = {
	{"1234", "5668", "6902"},
	{"999", "999", "1998"},
	{"999", "001", "1000"}
};

char * addLtoR(char * a, char * b) {
	int i = 0, locLess9 = 0, j;
	char next, sum;
	next = b[0];
	b[0] = '0';
	while (next) {
		sum = next + a[i] - '0';
		next = b[i + 1];
		if (sum > '9') {
			b[i + 1] = sum - 10;
			// making all 9s as 0s
			for (j = i; j > locLess9; j--)
				b[j] = '0';
			// incrementing value before 9s
			b[locLess9] += 1;
			locLess9 = i + 1;
		}
		else if (sum < '9') {
			b[i + 1] = sum;
			locLess9 = i + 1;
		}
		else
			b[i + 1] = '9';
		i++;
	}
	b[i + 1] = 0;
	if (*b == '0')
		return b + 1;
	return b;
}


void tester(int size) {
	int i, j;
	char *result;
	for (i = 0; i < size; i++) {
		result = addLtoR(cases[i].num1, cases[i].num2);
		for (j = 0; result[j] != '\0'; j ++) {
			if (result[j] != cases[i].result[j])
				printf("FAIL\n");
		}
		if (cases[i].result[j])
			printf("FAIL\n");
		else printf("PASS\n");

	}
}

int main(void) {
	tester(3);
	getchar();
	return 0;
}