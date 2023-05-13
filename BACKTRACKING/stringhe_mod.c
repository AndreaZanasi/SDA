#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void BacktrackStrModRec(int n, int k, char* vcurr, int i) {

	for (int j = 1; j <= n; j++) {

		if (i == k) {
			char lett = 96;
			printf("{");
			for (int p = 0; p < k; p++) {
				printf("%c", lett + vcurr[p]);
			}
			printf("}, ");

			return;
		}

		vcurr[i] = j;
		BacktrackStrModRec(n, k, vcurr, i + 1);
	}

}

void BacktrackStrMod(int n, int k) {

	if (n <= 0 || n > 26 || k <= 0) {
		return;
	}

	char *vcurr = malloc(k);

	BacktrackStrModRec(n, k, vcurr, 0);

	free(vcurr);
}