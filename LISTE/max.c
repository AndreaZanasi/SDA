#include "elemtype.h"
#include "list.h"

const ElemType* MaxElement(const Item* i) {

	if (i == NULL) {
		return NULL;
	}

	const ElemType* max = ListGetHeadValue(i);
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), max) > 0) {
			max = ListGetHeadValue(tmp);
		}
	}

	return max;
}