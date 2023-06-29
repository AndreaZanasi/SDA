#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, 
	size_t* ret_size, size_t i, char* vcurr, char* vbest, bool* isposs) {

	if ((int)i == n) {

		int poscurr = 0;
		int mossecurr = 0;

		for (size_t j = 0; (int)j < n; j++) {
			for (size_t k = 0; k < f_size; k++) {
				if (poscurr == f[k]) {
					return;
				}
			}
			if (vcurr[j] == 'a') {
				poscurr += a;
				mossecurr++;
			}
			else if (vcurr[j] == 'b') {
				poscurr -= b;
				mossecurr++;
			}
		}

		if (poscurr != h) {
			return;
		}

		if ((size_t)mossecurr < *ret_size) {
			*ret_size = mossecurr;
		}
		else {
			return;
		}

		*isposs = true;
		memcpy(vbest, vcurr, n * sizeof(char));
		return;

	}

	vcurr[i] = 'a';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, i + 1, vcurr, vbest, isposs);

	vcurr[i] = 'b';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, i + 1, vcurr, vbest, isposs);

	vcurr[i] = '0';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, i + 1, vcurr, vbest, isposs);
}

char* GuidaLaPulce(const int* f, size_t f_size, int a, 
	int b, int n, int h, size_t* ret_size) {

	if (f == NULL || h <= 0 || n <= 0 || a <= 0 || b <= 0) {
		*ret_size = 0;
		return NULL;
	}

	char* vbest = calloc(n, sizeof(char));
	char* vcurr = calloc(n, sizeof(char));
	bool isposs = false;

	*ret_size = INT_MAX;

	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, 0, vcurr, vbest, &isposs);

	if (isposs == true) {
		char* ris = malloc(*ret_size * sizeof(char));
		size_t j = 0;
		for (size_t i = 0; (int)i < n; i++) {
			if (vbest[i] != '0') {
				ris[j] = vbest[i];
				j++;
			}
		}
		free(vcurr);
		free(vbest);
		return ris;
	}

	free(vcurr);
	free(vbest);

	*ret_size = 0;
	return NULL;
}