#include <stdlib.h>
#include <stdio.h>

double LogisticMap(double x0, double r, int n) {

	if (n == 0) {
		return x0;
	}
	LogisticMap((r * x0) * (1 - x0), r, n - 1);
}

int main(int argc, char** argv) {

	if (argc != 4) {
		return 1;
	}

	double x0 = atof(argv[1]);
	double r = atof(argv[2]);
	int n = atoi(argv[3]);

	if (x0 < 0 || x0 > 1 || r < 0 || n < 0) {
		return 1;
	}

	double ris = LogisticMap(x0, r, n);
	printf("%lf", ris);

	return 0;
}