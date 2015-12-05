/** 
 * modulo.c
 * 13-09-2015
 * Mani Kumar Reddy K
 * Program to find (x^y)%a
 */

#include <stdio.h>

struct testcases {
	unsigned int x, y, a, r;
} cases[] = {
	{ 5, 4, 3, 1 },
	{ 87, 1, 23, 18 },
	{ 100, 99, 3, 1 },
	{ 5, 0, 3, 1 },
	{ 17, 23, 11, 7 },
	{ 4294967295, 4294967294, 4294967295, 0 }
};

// solving using (x*y)%a = ((x%a)*(y%a))%a
unsigned int modulo1(unsigned int x, unsigned int y, unsigned int a) {
	if (y == 0)
		return 1; 
	unsigned int i, res = x % a;
	for (i = 1;i < y; i ++)
		res = ((res % a) * (x % a)) % a;
	return res;
}

// implementing above using recursion
unsigned int modulo2(unsigned int x, unsigned int y, unsigned int a) {
	if (y == 0)
		return 1; 
	if (y == 1)
		return x % a;
	return (modulo2(x, y - 1, a) * (x % a)) % a;
}

// improvising above code for faster calculation
unsigned int modulo3(unsigned int x, unsigned int y, unsigned int a) {
	if (y == 0)
		return 1; 
	if (y == 1)
		return x % a;
	// dividing problem into two parts
	if (y % 2)
		return (modulo3(x, y / 2, a) * modulo3(x, y / 2 + 1, a)) % a;
	return (modulo3(x, y / 2, a) * modulo3(x, y / 2, a)) % a;
}

// optimize solution by using above recursion
unsigned int modulo4(unsigned int x, unsigned int y, unsigned int a) {
	int totalMod = x % a;
	int res = 1;
	while (y)
	{
		// performing modulo with totalMod only when power is odd(bit 1 in binary rep)
		if (y % 2)
			res = (res * totalMod) % a;
		y /= 2;
		// keep calculating totalMod value till this iteration
		totalMod = (totalMod * totalMod) % a;
	}
	return(res);
}

void tester(int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (modulo1(cases[i].x, cases[i].y, cases[i].a) == cases[i].r)
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 1);
		if (modulo2(cases[i].x, cases[i].y, cases[i].a) == cases[i].r)
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 2);
		if (modulo3(cases[i].x, cases[i].y, cases[i].a) == cases[i].r)
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 3);
		if (modulo4(cases[i].x, cases[i].y, cases[i].a) == cases[i].r)
			printf("Pass\n");
		else
			printf("Fail Case : %d fun : %d\n", i, 4);
		}
}

int main(void) {
	tester(6);
	getchar();
}