#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void CacciatorePredaRec(const char* v, size_t v_size, int u, 
	int i, int* vcurr, int* vbest, int* prede_catturate) {

	if (i == (int)v_size) {

		int prede = 0;
		for (size_t j = 0; j < v_size; j++) {
			if (v[j] == 'C' || v[j] == 'c') {
				if (v[vcurr[j]] != 'P' && v[vcurr[j]] != 'p') {
					if (vcurr[j] != -1) {
						return;
					}
				}
				if (vcurr[j] != -1) {
					vcurr[vcurr[j]] = -2;
					prede++;
				}
			}
		}
		for (size_t j = 0; j < v_size; j++) {
			if (v[j] == 'P' || v[j] == 'p') {
				if (vcurr[j] == 0) {
					vcurr[j] = -1;
				}
			}
			for (size_t k = j + 1; k < v_size - 1; k++) {
				if (vcurr[j] > 0  && vcurr[j] == vcurr[k]) {
					return;
				}
			}
		}

		if (prede > *prede_catturate) {
			*prede_catturate = prede;
			memcpy(vbest, vcurr, v_size * sizeof(int));
		}

		return;
	}

	if (v[i] == 'C' || v[i] == 'c') {
		for (int j = 1; j <= u; j++) {

			vcurr[i] = i + j;
			CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest, prede_catturate);

			if (i != 0) {
				vcurr[i] = i - j;
				CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest, prede_catturate);
			}

			vcurr[i] = -1;
			CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest, prede_catturate);
		}
	}
	else {
		CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest, prede_catturate);
	}

}

int* CacciatorePreda(const char* v, size_t v_size, int u) {

	if (v == NULL || v_size == 0 || u == 0) {
		return NULL;
	}

	int* ris = calloc(v_size, sizeof(int));

	int p = 0, c = 0;
	for (size_t i = 0; i < v_size; i++) {
		if (v[i] == 'c' || v[i] == 'C') {
			c++;
		}
		if (v[i] == 'p' || v[i] == 'P') {
			p++;
		}
	}

	if (p == (int)v_size || c == (int)v_size) {
		for (size_t i = 0; i < v_size; i++) {
			ris[i] = -1;
		}
		return ris;
	}

	int* vcurr = calloc(v_size, sizeof(int));
	int* vbest = calloc(v_size, sizeof(int));
	int prede_catturate = 0;

	CacciatorePredaRec(v, v_size, u, 0, vcurr, vbest, &prede_catturate);

	memcpy(ris, vbest, v_size * sizeof(int));

	free(vcurr);
	free(vbest);

	return ris;
}