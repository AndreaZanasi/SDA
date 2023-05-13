#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"
#include <string.h>
#include <stdlib.h>

Item* Delete(Item* i, const char* name) {

	if (ListIsEmpty(i) || name == NULL) {
		return NULL;
	}

	ElemType str;
	strcpy(str.name, name);

	if (ElemCompare(ListGetHeadValue(i), &str) == 0) {
		free(&i->value);
		return i->next;
	}

	Item *tmp1 = i;
	Item *tmp2 = i;

	while (!ListIsEmpty(tmp1)) {

		if (ElemCompare(ListGetHeadValue(tmp1), &str) == 0) {
			tmp2->next = tmp1->next;
			free(&tmp1->value);
			return i;
		}

		tmp2 = tmp1;
		tmp1 = ListGetTail(tmp1);
	}

	return i;
}