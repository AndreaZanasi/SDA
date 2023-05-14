#include <stdlib.h>
#include <stdio.h>

int DividEnConquer(int n) {

	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return DividEnConquer(n / 2) + DividEnConquer((n / 2) + (n % 2 != 0)) + n;
}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);

	if (n < 0) {
		return 1;
	}

	int ris = DividEnConquer(n);

	printf("%d", ris);

	return 0;
}