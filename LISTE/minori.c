#include "elemtype.h"
#include "list.h"

Item* CreaDaMinori(const Item* i, int v) {

	Item* ris = ListCreateEmpty();
	if (i == NULL) {
		return ris;
	}

	const Item* tmp = i;
	ElemType e = v;
	for (; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if(ElemCompare(&e, ListGetHeadValue(tmp)) >= 0){
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
	}

	return ris;
}