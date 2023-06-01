#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ParentesiRec(int n, int* cnt, char* vcurr, size_t i) {

	if ((int)i == n) {

		if (vcurr[0] == ')' || vcurr[n - 1] == '(') {
			return;
		}

		char* supp = calloc(n, sizeof(char));
		memcpy(supp, vcurr, n * sizeof(char));

		for (int j = 0; j < n; j++) {

			if (supp[j] == 0) {
				continue;
			}
			if (supp[j] == ')') {
				return;
			}
			bool isopen = true;
			supp[j] = 0;

			for (int k = j + 1; k < n; k++) {
				if (supp[k] == ')') {
					supp[k] = 0;
					isopen = false;
					break;
				}
			}
			if (isopen == true) {
				return;
			}
		}

		free(supp);

		for (int j = 0; j < n; j++) {
			printf("%c", vcurr[j]);
		}
		printf("\n");

		(*cnt)++;

		return;
	}

	vcurr[i] = '(';
	ParentesiRec(n, cnt, vcurr, i + 1);

	vcurr[i] = ')';
	ParentesiRec(n, cnt, vcurr, i + 1);
}

int Parentesi(int n) {

	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return 0;
	}

	char* vcurr = calloc(n * 2, sizeof(char));
	int cnt = 0;

	ParentesiRec(n * 2, &cnt, vcurr, 0);

	free(vcurr);

	return cnt;
}
