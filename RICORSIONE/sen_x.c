#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Fact(int n) {

	if (n == 0 || n == 1) {
		return 1;
	}

	return n * Fact(n - 1);
}

double Sin_X(double x, int i, int n) {

	double ris = ((pow(-1, n)) / (Fact(2 * n + 1))) * pow(x, 2 * n + 1);

	if (n == i) {
		return ris;
	}

	return ris + Sin_X(x, i, n + 1);
}

int main(int argc, char** argv) {

	if (argc != 3) {
		return 1;
	}
	
	double x = atof(argv[1]);
	int i = atoi(argv[2]);

	if (i < 0) {
		return 1;
	}

	double ris = Sin_X(x, i, 0);
	printf("%lf", ris);

	return 0;
}