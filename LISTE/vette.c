#include "elemtype.h"
#include "list.h"

int ContaVette(const Item* i) {

	if (i == NULL) {
		return 0;
	}

	int vette = 0;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (!ListIsEmpty(tmp->next) && ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp->next)) > 0) {
			vette++;
		}
	}
	vette++;

	return vette;
}