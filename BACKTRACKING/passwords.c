#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PasswordRec(int n, int* vcurr, size_t i, int *nsol) {

	for (int j = 0; j < 10; j++) {

		if (i == (size_t)n) {

			bool flag = false;
			

			for (int k = 0; k < n - 1; k++) {
				if (vcurr[k] > vcurr[k + 1]) {
					return;
				}
				if (vcurr[k] == vcurr[k + 1]) {
					flag = true;
				}
			}
			if (flag == true) {
				(*nsol)++;
				printf("%d) ", *nsol);
				for (int k = 0; k < n; k++) {
					printf("%d", vcurr[k]);
				}
				printf("\n");
			}
			return;
		}

		vcurr[i] = j;
		PasswordRec(n, vcurr, i + 1, nsol);
	}
}

void Passwords(int n) {

	if (n <= 1) {
		return;
	}

	int nsol = 0;
	int* vcurr = calloc(n, sizeof(int));

	PasswordRec(n, vcurr, 0, &nsol);

	free(vcurr);

}