#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include "elemtype.h"

Item* ListLoad(const char* filename) {

	if (filename == NULL) {
		return NULL;
	}

	FILE* f = fopen(filename, "r");

	if (f == NULL) {
		return NULL;
	}

	Item* list = ListCreateEmpty();

	while (true) {

		ElemType tmp = 0;
		if (ElemRead(f, &tmp) != 1) {
			break;
		}
		list = ListInsertHead(&tmp, list);
	}
	fclose(f);
	return list;
}