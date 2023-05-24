#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ReverseStringRec(const char* str, char* reversed, size_t size) {

	if (size == 0) {
		return;
	}

	ReverseStringRec(str + 1, reversed, size - 1);
	reversed[size - 1] = *str;
}

char* ReverseString(const char* str) {

	if (str == NULL) {
		return NULL;
	}

	char* reversed = calloc(strlen(str) + 1, sizeof(char));

	ReverseStringRec(str, reversed, strlen(str));

	return reversed;
}