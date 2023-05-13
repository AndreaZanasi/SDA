#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p,
	unsigned int i, bool* vcurr, bool* vbest, int* max, int cnt, int sum) {

	if (i == pacchi_size) {
		for (size_t j = 0; j < pacchi_size; j++) {
			if (vcurr[j]) {
				sum += pacchi[j];
				if (sum > p) {
					break;
				}
			}
		}
		if (sum <= p) {
			if ((*max) < cnt) {
				(*max) = cnt;
				for (size_t j = 0; j < pacchi_size; j++) {
					vbest[j] = vcurr[j];
				}
			}
		}
		return;
	}
	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt, sum);

	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt + 1, sum);

	//vcurr[i] = 0;

}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	int max = 0;
	bool* vcurr = calloc(pacchi_size, sizeof(bool));
	bool* vbest = calloc(pacchi_size, sizeof(bool));

	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, &max, 0, 0);

	for (size_t i = 0; i < pacchi_size; i++) {
		printf("%d ", vbest[i]);
	}

	free(vcurr);
	free(vbest);
}