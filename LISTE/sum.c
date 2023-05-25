#include "elemtype.h"
#include "list.h"
#include <stdbool.h>

Item* Sum(const Item* i1, const Item* i2) {

	Item* sum = ListCreateEmpty();
	ElemType value = 0;

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return sum;
	}

	if (!ListIsEmpty(i1) && ListIsEmpty(i2)) {
		for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			sum = ListInsertBack(sum, ListGetHeadValue(tmp));
		}
		return sum;
	}

	if (ListIsEmpty(i1) && !ListIsEmpty(i2)) {
		for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			sum = ListInsertBack(sum, ListGetHeadValue(tmp));
		}
		return sum;
	}

	bool rip = false;
	const Item* tmp1 = i1;
	const Item* tmp2 = i2;

	while (true) {

		if (!ListIsEmpty(tmp1) && !ListIsEmpty(tmp2)) {
			value = *ListGetHeadValue(tmp1) + *ListGetHeadValue(tmp2);
			if (rip == true) {
				value++;
				rip = false;
			}
			if (value > 9) {
				value -= 10;
				rip = true;
			}
			sum = ListInsertBack(sum, &value);
		}
		else if (ListIsEmpty(tmp1) && !ListIsEmpty(tmp2)) {
			value = *ListGetHeadValue(tmp2);
			if (rip == true) {
				value++;
				rip = false;
			}
			sum = ListInsertBack(sum, &value);
		}
		else if (!ListIsEmpty(tmp1) && ListIsEmpty(tmp2)) {
			value = *ListGetHeadValue(tmp1);
			if (rip == true) {
				value++;
				rip = false;
			}
			sum = ListInsertBack(sum, &value);
		}
		else {
			break;
		}

		if (!ListIsEmpty(tmp1)) {
			tmp1 = ListGetTail(tmp1);
		}

		if (!ListIsEmpty(tmp2)) {
			tmp2 = ListGetTail(tmp2);
		}

	}

	value = 0;

	if (rip == true) {
		value++;
		rip = false;

		if (value > 9) {
			value -= 10;
			rip = true;
		}

		sum = ListInsertBack(sum, &value);
	}

	return sum;
}