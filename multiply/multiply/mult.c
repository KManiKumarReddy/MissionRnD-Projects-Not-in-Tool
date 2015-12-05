/**
 * mult.c
 * 31-09-2015
 * Mani Kumar Reddy K
 * Multiply two numbers without using * and +
 */

#include <stdio.h>

struct testcases {
	int a, b, r;
} cases[] = {
	{2, 3, 6},
	{2, -3, -6},
	{-2, 3, -6},
	{-2, -3, 6}
};

int add(int a, int b)
{
	int c;
	while (b) {
		c = a & b;
		a = a ^ b;
		b = c << 1;
	}
	return a;
}

int mult1(int a, int b) {
	int negFlag = 0;
	if (a < 0) {
		a = -a;
		negFlag = !negFlag;
	}
	if (b < 0) {
		b = -b;
		negFlag = !negFlag;
	}
	int i, res = a;
	for (i = 2; i <= b; i = -(~i))
		res = add(res, a);
	return negFlag ? -res : res;
}

int mult2(int a, int b) {
	int res = 0, negFlag = 0;
	if (a < 0) {
		a = -a;
		negFlag = !negFlag;
	}
	if (b < 0) {
		b = -b;
		negFlag = !negFlag;
	}
	while (b) {
		if (b & 1)
			res = add(a, res);
		a <<= 1;
		b >>= 1;
	}
	return negFlag ? -res : res;
}

void tester(int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (mult1(cases[i].a, cases[i].b) == cases[i].r)
			printf("PASS\n");
		else
			printf("FAIL case: %d fun: %d\n", i, 1);
		if (mult2(cases[i].a, cases[i].b) == cases[i].r)
			printf("PASS\n");
		else
			printf("FAIL case: %d fun: %d\n", i, 2);
	}
}
int main(void) {
	tester(4);
	getchar();
}