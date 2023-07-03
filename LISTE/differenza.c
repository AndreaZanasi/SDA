#include "differenza.h"

Item* ListCopy(const Item* i) {

	const Item* tmp = i;
	Item* r = ListCreateEmpty();

	while (!ListIsEmpty(tmp)) {

		r = ListInsertBack(r, ListGetHeadValue(tmp));
		tmp = ListGetTail(tmp);

	}

	return r;
}

Item* Differenza(const Item* i1, const Item* i2) {

	Item* r = ListCreateEmpty();

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {

		return r;

	}

	else if (ListIsEmpty(i2)) {

		r = ListCopy(i1);
		return r;

	}

	ElemType p = 0;
	const Item* tmp1 = i1;
	const Item* tmp2 = i2;

	while (!ListIsEmpty(tmp2)) {

		ElemType e = *ListGetHeadValue(tmp1) - p;
		p = 0;

		if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) < 0) {

			p = 1;
			e += 10;

		}

		e = e - *ListGetHeadValue(tmp2) + '0';
		r = ListInsertBack(r, &e);
		tmp1 = ListGetTail(tmp1);
		tmp2 = ListGetTail(tmp2);

	}

	if (!ListIsEmpty(tmp1) && ListIsEmpty(tmp1->next)) {
		ElemType e = *ListGetHeadValue(tmp1) - p;
		if (e == '0') {
			return r;
		}
	}

	while (!ListIsEmpty(tmp1)) {

		ElemType e = *ListGetHeadValue(tmp1) - p;
		p = 0;
		r = ListInsertBack(r, &e);
		tmp1 = ListGetTail(tmp1);

	}

	return r;
}