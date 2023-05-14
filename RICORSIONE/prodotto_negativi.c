#include <math.h>

int Prodotto(int n, int m) {

	int a = abs(n), b = abs(m);

	if (a == 0 || b == 0) {
		return 0;
	}
	if (a == 1) {
		return b;
	}
	if (b == 1) {
		return a;
	}

	return a + Prodotto(a, b - 1);
}


int ProdottoNegativi(int a, int b) {

	if (a < 0 && b < 0) {
		return Prodotto(a, b);
	}

	if (a < 0 || b < 0) {
		return -Prodotto(a, b);
	}

	return Prodotto(a, b);
}