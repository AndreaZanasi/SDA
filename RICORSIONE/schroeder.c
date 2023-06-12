#include <stdlib.h>
#include <stdio.h>

int Schroeder(int n) {

	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}

	int a = Schroeder(n - 1);
	int b = Schroeder(n - 2);
	return (((6 * n - 3) * a) / (n + 1)) - (((n - 2) * b) / (n + 1));

}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);

	if (n < 0) {
		return 1;
	}

	int ris = Schroeder(n);
	printf("%d", ris);

	return 0;
}