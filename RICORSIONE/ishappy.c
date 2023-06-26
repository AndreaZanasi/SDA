#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int SumSqr(int n) {

	int ris = 0;
	while (n != 0) {
		ris += (n % 10) * (n % 10);
		n /= 10;
	}

	return ris;
}

void IsHappy(int n, bool* ishappy) {

	int ris = SumSqr(n);
	if (ris == 1) {
		*ishappy = true;
		return;
	}
	if (ris == 4) {
		*ishappy = false;
		return;
	}

	IsHappy(ris, ishappy);
}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);

	if (n < 0) {
		return 1;
	}
	if (n == 0) {
		printf("Infelice");
		return 0;
	}

	bool ishappy = false;

	IsHappy(n, &ishappy);

	if (ishappy == true) {
		printf("Felice");
	}
	else {
		printf("Infelice");
	}

	return 0;
}