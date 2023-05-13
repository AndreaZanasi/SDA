#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

Item* AppendMod(Item* i1, Item* i2) {

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return NULL;
	}
	else if (ListIsEmpty(i1)) {
		return i2;
	}
	else if (ListIsEmpty(i2)) {
		return i1;
	}

	Item* tmp = i1;
	Item* prec = i1;

	while (true) {

		prec = tmp;
		tmp = ListGetTail(tmp);
		
		if (ListIsEmpty(tmp)) {
			prec->next = i2;
			break;
		}
	}

	return i1;
}