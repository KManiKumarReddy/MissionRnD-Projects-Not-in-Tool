/*
Author			:			Panchmahalkar Pritheesh
Description		:			Given two really really long numbers, this program finds the product of those two numbers.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void array_mult(int*, int*, int, int);
char* stringcat(char*, char*);
//void stringcat2(char*, int);
void stringrev(char*, int);
void stringcopy(char*, char*);
void addBitStrings(char*, char*, int, int);
char* binary(char*, int);


int main()
{
	int a[10], b[5];
	int alen, blen;
	printf("Enter length of array a(<= 10): ");
	scanf("%d", &alen);
	printf("Enter the numbers in array a: ");
	for (int i = 0; i < alen; i++)
		scanf("%d", &a[i]);

	printf("Enter length of array b(<= 5): ");
	scanf("%d", &blen);
	printf("Enter the numbers in array b: ");
	for (int i = 0; i < blen; i++)
		scanf("%d", &b[i]);

	array_mult(a, b, alen, blen);
	getchar();
	getchar();
}

void array_mult(int a1[], int a2[], int a1len, int a2len)
{
	char a[321], b[321];
	int i = 0, j = 0;
	a[0] = '\0';
	b[0] = 0;
	while (i < a1len)
	{
		int n = a1[i];
		binary(a, n);
		i++;
	}
	a[32 * i] = 0;
	int alen = 32 * i;

	i = 0;
	while (i < a2len)
	{
		int n = a2[i];
		binary(b, n);
		i++;
	}
	b[32 * i] = 0;
	int blen = 32 * i;

	char *c = malloc(alen + blen);

	c[alen + blen] = 0;

	for (i = 0; i < alen + blen; i++)
		c[i] = '0';

	for (i = alen - 1; i >= 0; i--)
	{
		/*char temp[] = "0";
		stringcat(b, temp);*/
		if (a[i] == '1')
		{
			addBitStrings(c, b, blen, blen + i);
		}
	}
	printf("a is %s\n", a);
	printf("b is %s\n", b);
	printf("c is %s\n", c);
	int k = i = 0;
	unsigned int res[15];
	while (i < a1len + a2len)
	{
		unsigned int temp = 2147483648;
		unsigned int sum = 0;
		while (temp)
		{
			if (c[k] == '1')
				sum += temp;
			temp /= 2;
			k++;
		}
		res[i++] = sum;
	}
	for (i = 0; i < a1len + a2len; i++) {
		printf("%d ", res[i]);
	}
}

void addBitStrings(char * a, char * b, int blen, int i) {
	int carry = 0;
	while (--blen >= 0) {
		int sum = (a[i] - '0') + (b[blen] - '0') + carry;
		if (sum == 1) {
			carry = 0;
			a[i] = '1';
		}
		if (sum == 2) {
			a[i] = '0';
			carry = 1;
		}
		if (sum == 3) {
			a[i] = '1';
		}
		i--;
	}
	if (carry) {
		a[i] = '1';
	}
}

/*void adder(char *a, char *b)
{
int i = 0, j = 0;
while (*a++)
i++;
while (*b++)
j++;

printf("i = %d, j = %d", i, j);
int carry = 0;
while (j >= 0)
{
if (a[i] == '0' && b[j] == '0')
{
a[i] = carry + '0';
carry = 0;
}
else if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1'))
{
if (carry == 0)
a[i] = '1';
else
{
carry = 1;
a[i] = '0';
}
}
else
{
if (carry == 1)
a[i] = '1';

else
a[i] = '0';

carry = 1;
}
i--;
j--;
}
if (a[0] == '1' && carry == 1)
{
a[0] = '0';
a = stringcat("1", a);
}
}
*/


char* binary(char a[], int n)
{
	char arr[33];
	int i = 31;
	arr[32] = '\0';
	while (n)
	{
		arr[i--] = n % 2 + '0';
		n /= 2;
	}
	for (int j = 0; j <= i; j++)
		arr[j] = '0';

	stringcat(a, arr);
	return arr;
}

char *stringcat(char *s1, char *s2)
{
	int i, j;
	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		s1[i++] = s2[j];
	s1[i] = '\0';
	return s1;
}
