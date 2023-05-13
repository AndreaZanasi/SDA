#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"
#include <string.h>

const ElemType* Find(const Item* i, const char* name) {

	if (i == NULL) {
		return NULL;
	}


	const ElemType* ptr = NULL;
	const Item* tmp = i;

	for (; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		ElemType e1;
		strcpy(e1.name, name);
		if (ElemCompare(ListGetHeadValue(tmp), &e1) == 0) {
			ptr = &tmp->value;
			break;
		}
	}

	return ptr;
}