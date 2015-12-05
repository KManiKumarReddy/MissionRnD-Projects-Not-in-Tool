#include <stdio.h>
#define MAX 15
struct testCases {
	short arr[MAX], len;
	int k;
	short result;
} cases[] = {
	{
		{ 1, 1, 1, 2, 2, 2, 3, 4 }, 8, 3, 1
	},
	{
		{ 1, 1, 1, 2, 2, 2, 3, 4 }, 8, 4, 1
	}
};

