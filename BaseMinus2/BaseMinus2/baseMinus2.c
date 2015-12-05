#include <stdio.h>
#include <stdlib.h>

struct testCases {
	int num; char *res;
} cases[] = {
	{
		6, "11010"
	},
	{
		9, "11001"
	},
	{
		11, "11111"
	},
	{
		8, "11000"
	},
	{
		16, "10000"
	},
	{
		65535, "10000000000000011"
	},
	{
		-2, "10"
	},
	{
		-1, "11"
	},
	{
		-16, "110000"
	},
	{
		-4, "1100"
	},
	{
		-6, "1110"
	}
};

char* baseMinusTwo(int n) {
	int i = 0, n1, a[40];
	if (n == 0) {
		return "";
	}
	//  converting in traditional way
	while (n) {
		n1 = n;
		n /= -2;
		// storing remainder
		a[i ++] = n1 - (n * -2);
		//handling -1 remainder as 11( -2^1 * 1 + -2^0 * 1)
		if (a[i - 1] == -1) {
			a[i - 1] = 1;
			n += 1;
		}
	}
	// conveting to string
	char * res = malloc(i);
	res[i] = 0;
	int j = 0;
	while (--i >= 0)
		*(res + (j ++)) = a[i] ? '1' : '0';
	return res;
}

void tester(int size) {
	int i, j;
	char *res;
	for (i = 0; i < size; i++) {
		res = baseMinusTwo(cases[i].num);
		for (j = 0; res[j] && cases[i].res[j]; j++) {
			if (res[j] != cases[i].res[j]) {
				printf("FAIL\n");
				break;
			}
		}
		if(!res[j])
			printf("PASS\n");
	}
}

int main(void) {
	tester(11);
	getchar();
}