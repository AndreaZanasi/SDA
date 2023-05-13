#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

Item* Append(const Item* i1, const Item* i2){

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return NULL;
	}

	Item* append = ListCreateEmpty();

	while (!ListIsEmpty(i1)) {

		append = ListInsertBack(append, ListGetHeadValue(i1));
		i1 = ListGetTail(i1);

	}
	while (!ListIsEmpty(i2)) {

		append = ListInsertBack(append, ListGetHeadValue(i2));
		i2 = ListGetTail(i2);

	}

	return append;
}