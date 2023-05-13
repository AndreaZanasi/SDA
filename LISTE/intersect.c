#include "list.h"
#include "elemtype.h"

Item* Intersect(const Item* i1, const Item* i2) {

	if (i1 == NULL || i2 == NULL) {
		return NULL;
	}
	Item* list = ListCreateEmpty();

	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				list = ListInsertBack(list, ListGetHeadValue(tmp1));
				break;
			}
		}
	}

	return list;

}