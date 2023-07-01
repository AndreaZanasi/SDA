#include "elemtype.h"
#include "list.h"
#include <stdbool.h>

int ContaVette(const Item* i) {

	if (i == NULL) {
		return 0;
	}

	int vette = 0;

	for (const Item* tmp1 = i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		bool isvetta = false;
		for (const Item* tmp2 = tmp1->next; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (!ListIsEmpty(tmp1->next) && ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) > 0) {
				isvetta = true;
			}
			else {
				isvetta = false;
				break;
			}
		}
		if (isvetta == true) {
			vette++;
		}
	}
	vette++;

	return vette;
}