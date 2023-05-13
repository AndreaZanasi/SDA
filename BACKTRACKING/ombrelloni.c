#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void OmbrelloniRec(int k, int n, int i, bool* vcurr, int cnt, int* nsol) {

	if (cnt == k) {
		for (int j = 1; j < n; j++) {
			if (vcurr[j - 1] == 1 && vcurr[j] == 1) {
				return;
			}
		}
		(*nsol)++;
		printf("%d) ", *nsol);
		for (int j = 0; j < n; j++) {
			printf("%1d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	if (i == n) {
		return;
	}

	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt, nsol);

	vcurr[i] = 1;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt + 1, nsol);
	vcurr[i] = 0;

}

int Ombrelloni(int k, int n) {

	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	if (k > 0 && n > 0) {
		OmbrelloniRec(k, n, 0, vcurr, 0, &nsol);
	}

	free(vcurr);
	return nsol;
}