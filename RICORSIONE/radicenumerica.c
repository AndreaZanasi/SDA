#include <stdlib.h>
#include <stdio.h>

int RadiceNumerica(long long n) {

	if ((n / 10) <= 0) {
		return (int)n;
	}
	int ris = n % 10;
	ris += RadiceNumerica(n/10);
	if (ris < 10) {
		return ris;
	}
	ris = RadiceNumerica(ris);
	return ris;
}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}

	long long n = atoi(argv[1]);

	if (n < 0) {
		return 1;
	}

	int ris = RadiceNumerica(n);
	printf("%d", ris);

	return 0;
}