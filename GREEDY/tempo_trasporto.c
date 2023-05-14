#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <string.h>

int TempoTrasporto(int n, const int* t, int p) {

	int m = 0;
	int* fermate = calloc(sizeof(int), n * sizeof(int));
	int* vcurr = calloc(sizeof(int), n * sizeof(int));
	fermate[0] = p;
	int passeggeri_spostati = 0;

	for (; fermate[n - 1] != p; m++) {

		for (int i = 0; i < n - 1; i++) {

			if (fermate[i] > 0) {

				if (fermate[i] >= t[i]) {
					passeggeri_spostati = t[i];
					vcurr[i] = passeggeri_spostati;
				}
				else{
				
					passeggeri_spostati = fermate[i];
					vcurr[i] = passeggeri_spostati;

				}

			}
		}
		for (int i = 0; i < n - 1; i++) {
			fermate[i] -= vcurr[i];
			fermate[i + 1] += vcurr[i];
			vcurr[i] = 0;
		}
		passeggeri_spostati = 0;

	}

	free(fermate);
	free(vcurr);

	return m;
}