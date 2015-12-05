#include <stdio.h>

struct testCases {
	unsigned int a[10], b[5], alen, blen, c[15];
} cases[] = {
	{
		{ 0, 2147483648 }, { 1 }, 2, 1,{ 0, 2147483648, 0 }
	},
	{
		{ 0, 2147483648 }, { 2 }, 2, 1,{ 0, 0, 1 }
	},
	{
		{ 5 }, { 2 }, 1, 1, { 10 }
	},
	{
		{ 10 }, { 5 }, 1, 1, {50}
	}
};

int * multiply(unsigned int * a, unsigned  int * b, int alen, int blen) {
	char abin[321], bbin[321];
	int i, j;
	// converting both inputs into binary strings
	for (i = 0, j = 0; i < alen; i++) {
		if (!a[i]) {
			do {
				abin[j++] = '0';
			} while (j % 32);
			continue;
		}
		while (a[i]) {
			abin[j] = a[i] & 1 ? '1' : '0';
			a[i] >>= 1;
			j++;
		}
		while (i < alen - 1 && j % 32)
			abin[j++] = '0';
	}
	abin[j] = 0;
	for (i = 0, j = 0; i < blen; i++) {
		if (!b[i]) {
			do {
				bbin[j++] = '0';
			} while (j % 32);
			continue;
		}
		while (b[i]) {
			bbin[j] = b[i] & 1 ? '1' : '0';
			b[i] >>= 1;
			j++;
		}
		while (i < blen - 1 && j % 32)
			bbin[j++] = '0';
	}
	bbin[j] = 0;
	// taking 480 bit resultant arrray
	char res[481];
	for (i = 0; i < (alen + blen) * 32; i++)
		res[i] = '0';
	res[i] = 0;
	// multiplying bbin with abin
	for (i = 0; abin[i]; i++) {
		// adding number to itslef when there is one,
		// like traditional multiplication in reverse manner
		if (abin[i] - '0') {
			int carry = 0;
			for (j = 0; bbin[j]; j++) {
				res[i + j] += (char)(carry + (bbin[j] - '0'));
				if (res[i + j] == '3') res[i + j] = '1'; 
				else if (res[i + j] == '2') {
					res[i + j] = '0';
					carry = 1;
				}
				else if (res[i + j] == '1') carry = 0;
			}
			if (carry) {
				res[i + j + 1] = '1';
			}
		}
	}
	// converting resulting string back to input format
	static unsigned int c[15], k;
	for (i = k = 0; i < alen + blen; i++) {
		unsigned int base = 1;
		c[i] = 0;
		do {
			if (res[k++] - '0')
				c[i] += base;
			base *= 2;
		} while (k % 32);
	}
	/* result
	printf("%s\n", abin);
	printf("%s\n", bbin);
	printf("%s\n", res);
	for (i = 0; i < alen + blen; i++) {
		printf("%u ", c[i]);
	}
	*/
	return c;
}

void tester(int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		int * r = multiply(cases[i].a, cases[i].b, cases[i].alen, cases[i].blen);
		for (j = 0; j < cases[i].alen + cases[i].blen; j++)
			if (cases[i].c[j] != r[j])
				printf("FAIL\n");
		if (j == cases[i].alen + cases[i].blen)
			printf("PASS\n");
	}
}

int main() {
	tester(4);
	getchar();
}