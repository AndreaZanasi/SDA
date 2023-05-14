#include <stdlib.h>
#include <stdio.h>

long long Catalan(n) {

	long long ris = 0;

	if (n == 0 || n == 1) {
		return 1;
	}

	for (int i = 0; i < n; i++) {
		ris += (Catalan(i)) * (Catalan((n - 1) - i));
	}

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

	long long ris = Catalan(n);
	printf("%lld", ris);

	return 0;
}