#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void CombinaMoneteRec(int b, const int* m, size_t m_size, size_t i, int* vcurr, int* nsol, int sum) {

	if (i == m_size) {

		if (sum > b) {
			return;
		}
		int sum_curr = 0;
		for (size_t j = 0; j < m_size; j++) {
			sum_curr += m[j] * vcurr[j];
		}
		if (sum_curr != b) {
			return;
		}

		(*nsol)++;
		for (size_t j = 0; j < m_size; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}

	for (size_t j = 0; (int)j <= b; j++) {
		vcurr[i] = (int)j;
		if (m[i] * (int)j > b) {
			return;
		}
		CombinaMoneteRec(b, m, m_size, i + 1, vcurr, nsol, sum + m[i] * (int)j);
	}
}

int CombinaMonete(int b, const int* m, size_t m_size) {

	int nsol = 0;
	size_t i = 0;
	if (m_size == 0 || m == NULL || b == 0) {
		return 0;
	}

	int* vcurr = calloc(m_size, sizeof(int));

	CombinaMoneteRec(b, m, m_size, i, vcurr, &nsol, 0);
	free(vcurr);

	return nsol;
}