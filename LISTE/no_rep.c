#include "elemtype.h"
#include "list.h"

Item* IntersectNoRep(const Item* i1, const Item* i2) {

	if (i1 == NULL || i2 == NULL) {
		return NULL;
	}
	Item* list = ListCreateEmpty();
	bool flag = false;

	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				for (const Item* tmp3 = list; !ListIsEmpty(tmp3); tmp3 = ListGetTail(tmp3)) {
					if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp3)) == 0) {
						flag = true;
					}
				}
				if (flag != true) {
					list = ListInsertBack(list, ListGetHeadValue(tmp1));
					break;
				}
			}
		}
		flag = false;
	}

	return list;

}
Item* DiffNoRep(const Item* i1, const Item* i2) {

	if (i1 == NULL) {
		return NULL;
	}

	Item* list = ListCreateEmpty();
	bool flag = false;
	bool flag2 = false;

	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			for (const Item* tmp3 = list; !ListIsEmpty(tmp3); tmp3 = ListGetTail(tmp3)) {
				if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp3)) == 0) {
					flag2 = true;
				}
			}
			if (flag2 == false) {
				list = ListInsertBack(list, ListGetHeadValue(tmp1));
			}
		}
		flag = false;
		flag2 = false;
	}

	return list;

}