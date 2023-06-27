#include "sum_dlist.h"

void DListCpy(Item* ris, const Item* i) {

	const Item* tmp = i;
	ElemType e;

	while (!DListIsEmpty(tmp)) {
		e = ElemCopy(DListGetHeadValue(tmp));
		ris = DListInsertBack(ris, &e);
	}
}

ElemType Sum(const Item* i1, const Item* i2) {

	ElemType n1 = 0, n2 = 0;
	const Item* tmp1 = i1;
	const Item* tmp2 = i2;

	while (true) {
		n1 += *DListGetHeadValue(tmp1);
		tmp1 = DListGetTail(tmp1);
		if (DListIsEmpty(tmp1)) {
			break;
		}
		n1 *= 10;
	}
	while (!DListIsEmpty(tmp2)) {
		n2 += *DListGetHeadValue(tmp2);
		tmp2 = DListGetTail(tmp2);
		if (DListIsEmpty(tmp2)) {
			break;
		}
		n2 *= 10;
	}

	return  n1 + n2;
}

Item* DListSum(const Item* i1, const Item* i2) {

	Item* ris = DListCreateEmpty();

	if (i1 == NULL && i2 == NULL) {
		return ris;
	}

	else if (i1 == NULL) {
		DListCpy(ris, i2);
		return ris;
	}
	else if (i2 == NULL) {
		DListCpy(ris, i1);
		return ris;
	}

	ElemType sum = Sum(i1, i2);

	while (sum != 0) {
		ElemType element = sum % 10;
		sum /= 10;
		ris = DListInsertHead(&element, ris);
	}

	return ris;
}