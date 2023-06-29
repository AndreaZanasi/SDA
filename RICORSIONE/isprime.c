#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int n, int div) {

	if (div == n) {
		return true;
	}

	if (n == 0 || n == 1 || n % div == 0) {
		return false;
	}

	return IsPrime(n, div + 1);
}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}

	bool b = IsPrime(n, 2);

	if (b == true) {
		printf("true");
	}
	else {
		printf("false");
	}

	return 0;
}