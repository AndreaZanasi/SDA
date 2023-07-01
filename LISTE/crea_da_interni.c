#include <stdlib.h>
#include <stdbool.h>
#include "elemtype.h"
#include "list.h"
#include <math.h>

Item* CreaDaInterni(const Item* i, double r) {

	if (i == NULL || r == 0) {
		return NULL;
	}

	Item* ris = ListCreateEmpty();

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (sqrt(pow(tmp->value.x, 2) + pow(tmp->value.y, 2)) <= r) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
	}

	return ris;
}