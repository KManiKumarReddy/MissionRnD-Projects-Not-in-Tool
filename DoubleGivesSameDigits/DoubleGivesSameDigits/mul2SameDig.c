#include <stdio.h>


int digitsMatch(unsigned int num1, unsigned int num2) {
	int digits[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	while (num1) {
		digits[num1 % 10] ++;
		num1 /= 10;
	}
	while (num2) {
		if (!digits[num2 % 10])
			return 0;
		digits[num2 % 10] --;
		num2 /= 10;
	}
	int i;
	for (i = 0; i < 10; i++)
		if (digits[i])
			return 0;
	return 1;
}

int digitsMatch1(unsigned int num1, unsigned int num2) {
	int digits[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int i;
	long long product1 = 0, product2 = 0;
	for (i = 0; i < 6; i++, num1 /= 10)
		product1 *= digits[(num1 % 10)];
	for (i = 0; i < 6; i++, num2 /= 10)
		product2 *= digits[num2 % 10];
	return product1 == product2;
}


int main(void) {
	printf("%d", digitsMatch1(123, 321));
	/*
	unsigned int i, j, flag;
	for (i = 100000; i < 500000; i++) {
		flag = 1;
		for (j = 2; j < 7 && flag; j ++)
			flag = digitsMatch(i, i * j);
		if (j == 7)
			printf("%u", i);
	}
	getchar(); */
}
