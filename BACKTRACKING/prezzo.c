#include "prezzo.h"

void TrovaArticoliRec(const struct Articolo* a, size_t a_size, int sum, size_t i, int* vcurr) {

	if (i == a_size) {

		int tmp = 0;

		for (size_t j = 0; j < a_size; j++) {
			if (vcurr[j] == 1) {
				tmp += a[j].prezzo;
			}
		}

		if (tmp != sum) {
			return;
		}

		for (size_t j = 0; j < a_size; j++) {
			if (vcurr[j] == 1) {
				printf("%s, ", a[j].nome);
			}
		}
		printf("\n");

		return;
	}

	vcurr[i] = 1;
	TrovaArticoliRec(a, a_size, sum, i + 1, vcurr);

	vcurr[i] = 0;
	TrovaArticoliRec(a, a_size, sum, i + 1, vcurr);
}


void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {

	if (a == NULL || a_size == 0) {
		return;
	}

	int* vcurr = calloc(a_size, sizeof(int));

	TrovaArticoliRec(a, a_size, sum, 0, vcurr);

	free(vcurr);
}