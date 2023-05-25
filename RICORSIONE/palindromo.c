#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void IsPalindromoRec(const char* start, const char* end, bool* res, size_t size) {

	if (size == 0) {
		return;
	}

	if (*start == *end) {
		*res = true;
	}
	else {
		*res = false;
		return;
	}

	IsPalindromoRec(start + 1, end - 1, res, size - 1);
	return;
}

bool IsPalindromo(const char* str) {

	if (str == NULL) {
		return false;
	}

	if (str[0] == '\0') {
		return true;
	}

	size_t size = strlen(str);

	bool res = true; 
	IsPalindromoRec(str, str + size - 1, &res, size);
	return res;
}