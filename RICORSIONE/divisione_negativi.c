#include <limits.h>
#include <math.h>

int Divisione(int n, int m) {
	if (m == 0) {
		return INT_MAX;
	}

	int a = abs(n);
	int b = abs(m);

	if (a == 0 || a < b) {
		return 0;
	}

	return Divisione(a - b, b) + 1;
}

int DivisioneNegativi(int a, int b) {

	if (a < 0 && b < 0) {
		return Divisione(a, b);
	}

	if (a < 0 || b < 0) {
		return -Divisione(a, b);
	}

	return Divisione(a, b);

}