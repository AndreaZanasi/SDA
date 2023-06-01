#include <stdlib.h>
#include <stdio.h>

void Hailstone(int n, int* ris) {

	(*ris)++;

	if (n == 1) {
		printf("%d", n);
		return;
	}

	printf("%d, ", n);
	if (n % 2 != 0) {
		Hailstone(3 * n + 1, ris);
	}
	else {
		Hailstone(n / 2, ris);
	}
}

int main(int argc, char** argv) {

	if (argc != 2) {
		return -1;
	}

	int n = atoi(argv[1]);
	int ris = 0;

	if (n <= 0) {
		return 0;
	}

	Hailstone(n, &ris);

	return ris;
}