#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void RegoleRec(const char *r, size_t n, int *vcurr, size_t i) {

	for (int j = 1; j <= (int)n; j++) {

		if (i == n) {

			for (size_t k = 0; k < n; k++) {
				if (r[k] == 'D' || r[k] == 'd') {
					if (vcurr[k] < vcurr[k + 1]) {
						return;
					}
				}
				if (r[k] == 'I' || r[k] == 'i') {
					if (vcurr[k] > vcurr[k + 1]) {
						return;
					}
				}
				for (size_t l = k + 1; l < n; l++) {
					if (vcurr[k] == vcurr[l]) {
						return;
					}
				}
			}

			for (size_t k = 0; k < n; k++) {
				printf("%d ", vcurr[k]);
			}
			printf("\n");
			return;
		}

		vcurr[i] = j;
		RegoleRec(r, n, vcurr, i + 1);
	}

}

void Regole(const char* r) {

	size_t n = strlen(r);
	if (n == 0) {
		printf("1");
		return;
	}

	int* vcurr = calloc(n + 1, sizeof(int));

	RegoleRec(r, n + 1, vcurr, 0);

	free(vcurr);
}