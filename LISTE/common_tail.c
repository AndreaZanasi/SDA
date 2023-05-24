#include "elemtype.h"
#include "list.h"
#include <stdbool.h>

size_t ListGetSize(const Item* i) {

	const Item* tmp = i;
	size_t size = 0;

	while (!ListIsEmpty(tmp)) {

		size++;
		tmp = ListGetTail(tmp);

	}
	return size;
}

const Item* CommonTail(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
		return NULL;
	}

	bool flag = false;

	const Item* tmp1 = i1;
	const Item* tmp2 = i2;

	if (ListGetSize(tmp1) > ListGetSize(tmp2)) {
		while (ListGetSize(tmp1) != ListGetSize(tmp2)) {
			tmp1 = ListGetTail(tmp1);
		}
	}
	else {
		while (ListGetSize(tmp2) != ListGetSize(tmp1)) {
			tmp2 = ListGetTail(tmp2);
		}
	}

	const Item* tmp3 = tmp1;

	while (true) {

		if (ListIsEmpty(tmp1) || ListIsEmpty(tmp2)) {
			break;
		}

		if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
			flag = true;
		}
		else {
			flag = false;
			tmp3 = ListGetTail(tmp3);
		}

		tmp1 = ListGetTail(tmp1);
		tmp2 = ListGetTail(tmp2);
	}
	
	if (flag == true) {
		return tmp3;
	}

	return NULL;
}