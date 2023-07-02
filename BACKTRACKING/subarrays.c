#include <stdlib.h>
#include <stdbool.h>

void OptimalSubarrayRec(const int* v, size_t n, bool* vcurr, int* bst,
	size_t i, size_t cnt) {

	if (i == n) {

		int sum = 0;
		int taken = 0;
		for (size_t j = 0; j < n; j++) {
			if (vcurr[j] == true) {
				taken++;
				if (taken != (int)cnt && vcurr[j + 1] == false) {
					return;
				}
				sum += v[j];
			}
		}

		if (sum > *bst) {
			*bst = sum;
		}

		return;
	}

	vcurr[i] = 1;
	OptimalSubarrayRec(v, n, vcurr, bst, i + 1, cnt + 1);
	vcurr[i] = 0;
	OptimalSubarrayRec(v, n, vcurr, bst, i + 1, cnt);
}

int OptimalSubarray(const int* v, size_t n) {

	if (v == NULL || n == 0) {
		return 0;
	}

	bool* vcurr = calloc(n, sizeof(vcurr));
	int bst = 0;

	OptimalSubarrayRec(v, n, vcurr, &bst, 0, 0);

	if (bst <= 0) {
		free(vcurr);
		return 0;
	}

	free(vcurr);

	return bst;

}