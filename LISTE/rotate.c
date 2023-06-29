#include "elemtype.h"
#include "list.h"
#include <stdlib.h>

size_t ListGetLen(Item* i) {
	Item* tmp = i;
	size_t len = 0;

	while (!ListIsEmpty(tmp)) {
		tmp = ListGetTail(tmp);
		len++;
	}

	return len;
}

Item* Rotate(Item* i, int n) {

	if (ListIsEmpty(i)) {
		return NULL;
	}
	Item* start = i;
	Item* prec = i;
	for (size_t i = 0; (int)i < n - 1; i++) {
		prec = ListGetTail(prec);
	}
	Item newstart = { .next = i };
	size_t len = ListGetLen(i);
	Item* tmp = i;

	for (size_t j = 0; j < len; j++) {

		if ((int)j == n) {
			prec->next = NULL;
			newstart.next = tmp;
		}
		if (j == len - 1) {
			tmp->next = start;
		}
		tmp = ListGetTail(tmp);
	}

	return newstart.next;
}