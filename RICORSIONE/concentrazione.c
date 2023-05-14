#include <stdio.h>
#include <stdlib.h>

double Concentrazione(int n) {
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 0.2;
	}
	double ris = (0.3 * (Concentrazione(n - 1))) + (0.2);
	return ris;
}

int main(int argc, char** argv) {

	if (argc < 1) {
		return 1;
	}

	int n = atoi(argv[1]);
	if (n < 1) {
		return 1;
	}

	double ris = Concentrazione(n);
	printf("%lf", ris);

	return 0;
}