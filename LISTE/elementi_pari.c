#include "elemtype.h"
#include "list.h"
#include <stdlib.h>

Item* ElementiPari(const Item* i) {

	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}

	Item* ris = ListCreateEmpty();
	size_t j = 0;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j % 2 == 0) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
		j++;
	}

	return ris;
}