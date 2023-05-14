#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool IsPalindromo(const char* str) {

	if (str == NULL) {
		return false;
	}

	if (str[0] == '\0') {
		return true;
	}

	size_t size = strlen(str) - 1;

	if (str[0] == str[size]) {
		char* supp = calloc(size, sizeof(char));
		supp = strcpy(supp, str);
		supp++;
		supp[size - 1] = 0;
		return IsPalindromo(supp);
	}
	else {
		return false;
	}
}