/**
 * dateprint.c
 * 13-09-2015
 * Mani Kumar Reddy K
 * Program to print date in words
 */

#include <stdio.h>

struct testCases {
	// input
	char * in;
	// String output
	char * res;
} cases[] = {
	{
		// my DOB :P
		"27/01/1997",
		"twenty seventh january of nineteen ninety seven."
	},
	{
		// 29 in non leap year
		"29/02/2015",
		"invalid date"
	},
	{
		// invalid date
		"32/01/1997",
		"invalid date"
	},
	{
		// valid date in non leap year
		"28/02/2015",
		"twenty eighth february of two thousand fifteen."
	},
	{
		// valid date in leap year
		"29/02/2016",
		"twenty ninth february of two thousand sixteen."
	},
	{   // invalid date in non leap year
		"29/02/2100",
		"invalid date"
	},
	{   // valid date in 2100
		"31/10/2100",
		"thirty first october of twenty one hundred."
	},
	{
		"21/1/150",
		"twenty first january of one fifty."
	},
	{
		"19/3/22",
		"nineteenth march of twenty two."
	}
};


//global variables
char * nums[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char * tens[] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "nighty", "ninety" };
char * snums[] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
char * months[] = { "january",
"february",
"march",
"april",
"may",
"june",
"july", 
"august",
"september",
"october",
"november",
"december" };
char * days[] = { "first",
"second",
"third",
"fourth",
"fifth",
"sixth",
"seventh",
"eighth",
"ninth",
"tenth",
"eleventh",
"twelfth",
"thirtheenth",
"fourteenth",
"fifteenth",
"sixteenth",
"seventeenth",
"eighteenth",
"nineteenth",
"twentieth",
"twenty first",
"twenty second",
"twenty third",
"twenty fourth",
"twenty sifth",
"twenty sixth",
"twenty seventh",
"twenty eighth",
"twenty ninth",
"thirtieth",
"thirty first" };

int isLeapYear(int y) {
	// not divisible by 4
	if (y % 4)
		return 0;
	// divisible by 400
	if (!(y % 400))
		return 1;
	// divisible by 100, blocks cases like 2100
	if (!(y % 100))
		return 0;
	// divisible by 100 & not divisble by 400
	return 1;
}

int validate(char * in, int * d, int * m, int * y) {
	int firstSlash = -1, secondSlash = -1, i;
	for (i = 0; in[i]; i++)
		if (in[i] == '/')
			if (firstSlash >= 0)
				if (secondSlash >= 0)
					return 0;
				else
				secondSlash = i;
			else
				firstSlash = i;
	if (firstSlash < 1 || secondSlash - firstSlash < 1)
		return 0;
	*d = in[0] - '0';
	for (i = 1; i < firstSlash; i ++)
		*d = *d * 10 + (in[i] - '0');
	*m = in[firstSlash + 1] -'0';
	for (i = firstSlash + 2; i < secondSlash; i++)
		*m = *m * 10 + (in[i] - '0');
	*y = in[secondSlash + 1] - '0'; 
	for (i = secondSlash + 2; in[i]; i++)
		*y = *y * 10 + (in[i] - '0');
	// checking month and year
	if (*m < 1 || *m > 12 || *y < 1 || *y > 9999)
		return 0;
	// initializing maximum days in a month
	int maxDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// increasing max days in feb for leap years
	if (isLeapYear(*y))
		maxDays[1] ++;
	// checing date
	if (*d < 1 || *d > maxDays[*m - 1])
		return 0;

	// validated
	return 1;
}

// string comparision
int stringCompare(const char* s1, const char* s2) {
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

// string concatenation
char * concat(char *dest, const char *src) {
	char *ret = dest;
	while (*dest)
		dest++;
	while (*dest++ = *src++)
		;
	return ret;
}

//string copy
char * copy(char *dest, const char *src) {
	char *save = dest;
	while (*dest++ = *src++);
	return save;
}

// functionality
void printDate(char * in, char res[]) {
	int d, m, y;
	if (!validate(in, &d, &m, &y)) {
		copy(res, "invalid date");
		return;
	}
	int tFlag = 0, hFlag = 0, tnFlag = 0;
	sscanf_s(in, "%d/%d/%d", &d, &m, &y);
	res[0] = '\0';
	concat(res, days[d - 1]);
	concat(res, " ");
	concat(res, months[m - 1]);
	concat(res, " of");
	if (y > 999) {
		concat(res, " ");
		if (!((y / 100) % 10)) {
			concat(res, nums[y / 1000 - 1]);
			concat(res, " thousand");
		}
		else {
			if (y / 1000 == 1) {
				concat(res, snums[(y / 100) % 10 - 1]);
			}
			else {
				concat(res, tens[y / 1000 - 1]);
				concat(res, " ");
				concat(res, nums[(y / 100) % 10 - 1]);
			}
		}
		y %= 100;
	}
	else if (y > 99) {
		concat(res, " ");
		concat(res, nums[y / 100 - 1]);
		y %= 100;
	}
	if (y > 9) {
		concat(res, " ");
		if (y / 10 == 1) {
			concat(res, snums[y % 10 - 1]);
			concat(res, ".");
			return;
		}
		concat(res, tens[y / 10 - 1]);
		y %= 10;
		if (y) {
			concat(res, " ");
			concat(res, nums[y - 1]);
		}
		concat(res, ".");
	}
	else {
		concat(res, " hundred.");
	}
}

void tester(int size) {
	int i;
	char res[100];
	for (i = 0; i < size; i++) {
		printDate(cases[i].in, res);
		if (!stringCompare(cases[i].res, res))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}

int main(void) {
	tester(9);
	getchar();
}