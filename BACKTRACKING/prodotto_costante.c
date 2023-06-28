#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void RisolviProdottoRec(int n, int* vcurr, size_t i, int* ris, bool* isposs) {

	for (size_t j = i; j < n * n; j++) {

		if (i == (n * n) - 1) {

			int prodr = 1, prodc = 1, supp;
			for (int r = 0; r < n; r++) {
				for (int c = 0; c < n; c++) {
					prodr *= vcurr[r * n + c];
					prodc *= vcurr[c * n + r];
				}
				if (prodc != prodr) {
					return;
				}
				if (r > 0 && supp != prodr) {
					return;
				}
				supp = prodc;
				prodc = 1;
				prodr = 1;
			}

			memcpy(ris, vcurr, n * n * sizeof(int));
			*isposs = true;
			return;
		}

		Swap(&vcurr[i], &vcurr[j]);
		RisolviProdottoRec(n, vcurr, i + 1, ris, isposs);
	}

	return;
}

int* RisolviProdotto(int n, const int* s) {

	int* vcurr = malloc(n * n * sizeof(int));
	int* ris = malloc(n * n * sizeof(int));
	bool isposs = false;
	memcpy(vcurr, s, n * n * sizeof(int));

	RisolviProdottoRec(n, vcurr, 0, ris, &isposs);

	if (isposs == false) {
		free(ris);
		free(vcurr);
		return NULL;
	}

	free(vcurr);

	return ris;
}