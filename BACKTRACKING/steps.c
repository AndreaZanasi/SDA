#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int StepsRec(int n, int* vcurr, int i, int sol, int size) {

	for (int j = 1; j <= 3; j++, size--) {

		if (i == size) {
			
			int sum = 0;

			for (int k = 0; k < size; k++) {
				sum += vcurr[k];
			}
			if (sum != n) {
				return sol;
			}

			sol++;

			printf("[");
			for (int k = 0; k < size - 1; k++) {
				printf("%d, ", vcurr[k]);
			}
			printf("%d], ", vcurr[size - 1]);
			i--;
			return sol;
		}

		vcurr[i] = j;
		sol = StepsRec(n, vcurr, i + 1, sol, size);
	}

	return sol;
}

int Steps(int n) {

	if (n <= 0) {
		return 0;
	}

	int* vcurr = calloc(n, sizeof(int));

	int sol = StepsRec(n, vcurr, 0, 0, n);

	free(vcurr);

	return sol;
}