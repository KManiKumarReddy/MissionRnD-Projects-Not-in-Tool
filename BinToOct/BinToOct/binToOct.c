#include<stdio.h>
struct testCases
{
	char in[3000], out[1000];
} cases[] = {
	{ "1010010100010", "12242" },
	{ "1000", "10" },
	{ "0", "0" },
	{ "1","1" },
	{ "111", "7" },
	{ "10000", "20" },
};

int stringLength(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}
int stringCompare(char *a, char *b) {
	int i;
	for (i = 0; a[i]; i++) {
		if (a[i] != b[i])
			return 0;
	}
	if (b[i])
		return 0;
	return 1;
}

char* binToOctal(char *binary) {
	int len = stringLength(binary), i = len - 1, j;
	static char octal[1000];
	// calculating length of octal number
	j = len / 3;
	if (len % 3)
		j++;
	octal[j] = 0;
	j--;
	while (i - 1 > 0 && j >= 0) {	
		octal[j] = '0' + ((1 * binary[i] - '0') + (2 * (binary[i - 1] - '0')) + (4 * (binary[i - 2] - '0')));
		j--;
		i -= 3;
	}
	// procesing remaining elements
	octal[j] = i > 0 ? '0' + (1 * (binary[i] - '0')) + (2 * (binary[i - 1] - '0')) : '0' + (1 * (binary[i] - '0'));;
	return octal;
}

void tester(int size) {
	int i;
	for (i = 0; i < size; i++) {
		char * octal = binToOctal(cases[i].in);
		if (stringCompare(octal, cases[i].out))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}

int main(void) {
	tester(9);
	getchar();
}