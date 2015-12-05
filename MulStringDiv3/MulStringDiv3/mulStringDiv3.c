#include <stdio.h>

// test cases
struct testCases {
	// input number
	char p[1001];
	// output result
	int k, res;
} cases[] = {
	{
		"0", 66664644, 1
	},
	{
		"123", 1, 1
	},
	{
		"122", 1, 0
	},
	{
		"122", 3, 1
	},
	{
		"10000220202020202020202222022022020202222545454545545454545452545845487841945498574544854845484654545685481843198461684549841634986514651848641651986541464165415684545849849646584494968464964749674986487487874874865465845845346484646146846464641321321464335486454543454534354534354", 65535, 1
	},
	{
		"100002202020202020202022220220220202022225454545455454545454525458454878419454985745448548454846545456854818431984616845498416349865146518486416519865414641654156845458498496465844949684649647496749864874878748748654658458453464846461468464646413213214643354864545434545343545343541", 65534, 0
	},
	{
		"39639639639696396396369063696360963060306063636636963963963696369636963696369636963690609060090696369636963", 65534, 1
	}
};

int divisibleByThree1(char * p, int k) {
	int sum = 0, i, j;
	// adding digits k times
	for (j = 0; j < k; j++)
		// adding digits of a number
		for (i = 0; p[i]; i++) {
			sum += (p[i] - '0');
			// handling big numbers
			if (sum > 2)
				sum %= 3;
		}
	// returning true if sum is zero
	return !sum;
}

int divisibleByThree2(char * p, int k) {
	// if a number is added to itself in multiple of 3 times then its surely divisible
	if (!(k % 3))
		return 1;
	// else checking if sum of digits of number is divisible by 3
	int i, sum = 0;
	for (i = 0; p[i]; i++)
		sum += (p[i] - '0');
	return !(sum % 3);
}

// tester function
void tester (int size) {
	int i;
	for (i = 0; i < size; i++)
		printf(divisibleByThree1(cases[i].p, cases[i].k) == cases[i].res ? "PASS\n" : "FAIL FUN:1\n");
	for (i = 0; i < size; i++)
		printf(divisibleByThree2(cases[i].p, cases[i].k) == cases[i].res ? "PASS\n" : "FAIL FUN:2\n");
}

int main(void) {
	tester(7);
	// That's all! :)
	getchar();
}