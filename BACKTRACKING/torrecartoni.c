#include "torrecartoni.h"

void TorreCartoniRec(const Cartone* c, size_t n, int* vcurr, int* vbest, 
	size_t i, unsigned* h, unsigned sum, unsigned hcurr) {
	for (size_t j = 0; j < n; j++) {
		if (i == n) {
			for (size_t k = 0; k < n; k++) {
				for (size_t d = k + 1; d < n; d++) {
					if (vcurr[k] == vcurr[d]) {
						vcurr[d] = -1;
					}
				}
			}
			for (size_t k = 0; k < n; k++) {
				for (size_t d = k + 1; d < n; d++) {
					if (vcurr[k] == -1 && vcurr[d] != -1) {
						return;
					}
				}
			}
			int x = 0;
			for (int k = n - 1; k >= 0; k--) {
				if (c[vcurr[x]].l >= sum && vcurr[k] != -1) {
					sum += c[k].p;
					hcurr += c[k].a;
					x++;
				}
			}
			if (hcurr > *h) {
				for (int k = n - 1; k >= 0; k--) {
					*h = hcurr;
					vbest[k] = vcurr[k];
				}
			}
			return;
		}
		vcurr[i] = j;
		TorreCartoniRec(c, n, vcurr, vbest, i + 1, h, sum, hcurr);
	}


}

void TorreCartoni(const Cartone* c, size_t n) {

	int h = 0;
	int* vcurr = calloc(n, sizeof(int));
	int* vbest = calloc(n, sizeof(int));

	TorreCartoniRec(c, n, vcurr, vbest, 0, &h, 0, 0);

	for (size_t j = 0; vbest[j] != -1 && j < n; j++) {
		printf("%d cm\n", vbest[j]);
	}
	printf("Altezza: %d\n", h);

	free(vcurr);
	free(vbest);
}