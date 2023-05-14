#include <stdlib.h>
#include <stdio.h>

int Triangular(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 3;
	}
	else {
		return (3 * Triangular(n - 1)) - (3 * Triangular(n - 2)) + (Triangular(n - 3));
	}

}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}
	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}
	int ris = Triangular(n);
	printf("%d", ris);

	return 0;
}