#include "elemtype.h"
#include "list.h"

Item* CopiaDaN(const Item* i, int n) {

	if (i == NULL) {
		return NULL;
	}

	Item* ris = ListCreateEmpty();
	const Item* tmp = i;
	int j = 1;

	for (; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j >= n) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
		j++;
	}

	return ris;
}
