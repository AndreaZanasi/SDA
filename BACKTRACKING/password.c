#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void PasswordRec(const char* str, int n, size_t i, char* vcurr, int* cnt, size_t len) {

	for (size_t p = 0; p < len; p++) {
		if (i == (size_t)n) {

			(*cnt)++;
			printf("%s\n", vcurr);
			return;
		}

		vcurr[i] = str[p];
		PasswordRec(str, n, i + 1, vcurr, cnt, len);
	}
}

int Password(const char* str, int n) {

	if (str == NULL) {
		return 0;
	}

	char* vcurr = calloc(n + 1, sizeof(char));
	int cnt = 0;
	size_t len = strlen(str);

	PasswordRec(str, n, 0, vcurr, &cnt, len);
	free(vcurr);

	return cnt;
}