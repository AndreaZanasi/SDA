#include <stdlib.h>
#include <stdio.h>

int Pow(int n) {

	int ris = 1;

	for (int i = 0; i < n; i++) {
		ris *= -1;
	}

	return ris;
}

double Pi(int n) {

	if (n == 0) {
		return 4;
	}

	double num = (4 * Pow(n)) / (2.000000 * (double)n + 1);

	double ris = num + Pi(n - 1);

	return ris;
}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);

	if (n < 0) {
		return 1;
	}

	double ris = Pi(n);
	printf("%lf", ris);

	return 0;
}