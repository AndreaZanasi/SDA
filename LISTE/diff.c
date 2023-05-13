#include "elemtype.h"
#include "list.h"

Item* Diff(const Item* i1, const Item* i2) {

	if (i1 == NULL) {
		return NULL;
	}

	Item* list = ListCreateEmpty();
	bool flag = false;

	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			list = ListInsertBack(list, ListGetHeadValue(tmp1));
		}
		flag = false;
	}

	return list;

}