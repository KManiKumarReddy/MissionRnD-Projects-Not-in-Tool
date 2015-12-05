#include <stdio.h>

void fibSysRep(int num, char string[]) {
	int i = 12;
	string[14] = '1';
	if (num == 1)
		return;
	string[13] = '1';
	if (num == 2)
		return;
	int temp1, temp2 = 1, nthFibonacci = 1, sum = 2;
	while (sum <= num) {
		temp1 = nthFibonacci;
		nthFibonacci += temp2;
		temp2 = temp1;
		sum += nthFibonacci;
		string[i--] = '1';
	}
	sum -= num;
	i += 2;
	temp1 = nthFibonacci;
	nthFibonacci = temp2;
	temp2 = temp1;
	while (sum) {
		if (nthFibonacci <= sum) {
			string[i] = '0';
			sum -= nthFibonacci;
		}
		temp1 = nthFibonacci;
		nthFibonacci = temp2 - nthFibonacci;
		temp2 = temp1;
		i++;
	}
}

int main(void) {
	char string[] = "000000000000000";
	fibSysRep(15, string);
	printf("%s\n", string);
	getchar();
}