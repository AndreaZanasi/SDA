#include <stdio.h>
#include <stdlib.h>

int Power4(double n) {

	if (n < 4 && n != 1) {
		return -100000;
	}
	if (n == 1) {
		return 0;
	}
	if (n == 4) {
		return 1;
	}

	return Power4(n / 4) + 1;

}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);

	int ris = Power4(n);
	if (ris < 0) {
		printf("!p4");
		return 0;
	}
	printf("4^%d = %d", ris, n);

	return 0;
}