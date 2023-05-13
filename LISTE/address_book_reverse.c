#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

Item* Reverse(const Item* i) {

	if (ListIsEmpty(i)) {
		return NULL;
	}

	Item* reversed = ListCreateEmpty();

	while (!ListIsEmpty(i)) {

		reversed = ListInsertHead(ListGetHeadValue(i), reversed);

		i = ListGetTail(i);
	}

	return reversed;
}