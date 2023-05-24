#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void SubsetEqualRec(int n, int s, bool* vcurr, size_t i) {

	if ((int)i == n) {

		int sum = 0;
		int* tmp = calloc(n, sizeof(int));
		size_t k = 0, l = 1;

		for (int j = 0; j < n; j++) {
			if (vcurr[j] == true) {
				tmp[k] = (int)l;
				sum += (int)l;
				k++;
			}
			l++;
		}

		if (sum != s) {
			free(tmp);
			return;
		}

		printf("{ ");
		for (size_t j = 0; j < k; j++) {
			printf("%d ", tmp[j]);
		}
		printf("}, ");
		free(tmp);

		return;
	}

	vcurr[i] = 1;
	SubsetEqualRec(n, s, vcurr, i + 1);

	vcurr[i] = 0;
	SubsetEqualRec(n, s, vcurr, i + 1);
}

void SubsetEqual(int n, int s) {

	if (n <= 0 || s <= 0) {
		return;
	}

	bool* vcurr = calloc(n, sizeof(bool));

	SubsetEqualRec(n, s, vcurr, 0);

	free(vcurr);
}