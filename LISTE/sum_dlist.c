#include "sum_dlist.h"

Item* DListCpy(Item* ris, const Item* i) {

	const Item* tmp = i;
	ElemType e;

	while (!DListIsEmpty(tmp)) {
		e = ElemCopy(DListGetHeadValue(tmp));
		ris = DListInsertBack(ris, &e);
		tmp = DListGetTail(tmp);
	}

	return ris;
}

size_t DListGetLen(const Item* i) {

	size_t len = 0;
	const Item* tmp = i;

	while (!DListIsEmpty(tmp)) {
		len++;
		tmp = DListGetTail(tmp);
	}

	return len;
}

Item* DListSum(const Item* i1, const Item* i2) {

	Item* ris = DListCreateEmpty();

	if (i1 == NULL && i2 == NULL) {
		return ris;
	}

	else if (i1 == NULL) {
		ris = DListCpy(ris, i2);
		return ris;
	}
	else if (i2 == NULL) {
		ris = DListCpy(ris, i1);
		return ris;
	}

	const Item* tmp1 = i1;
	const Item* tmp2 = i2;
	bool rip = false;

	size_t len1 = DListGetLen(tmp1), len2 = DListGetLen(tmp2);
	if (len1 >= len2) {
		while (!DListIsEmpty(tmp2)) {
			ElemType sum = *DListGetHeadValue(tmp1) + *DListGetHeadValue(tmp2);
			if (rip == true) {
				sum++;
				rip = false;
			}
			if (sum > 9) {
				rip = true;
				sum = sum % 10;
			}
			else {
				ris = DListInsertBack(ris, &sum);
				tmp1 = DListGetTail(tmp1);
				tmp2 = DListGetTail(tmp2);
				continue;
			}
			ris = DListInsertHead(&sum, ris);
			tmp1 = DListGetTail(tmp1);
			tmp2 = DListGetTail(tmp2);
		}
		while (!DListIsEmpty(tmp1)) {
			ElemType sum = *DListGetHeadValue(tmp1);
			if (rip == true) {
				sum++;
				rip = false;
			}
			if (sum > 9) {
				rip = true;
				sum = sum % 10;
			}
			else {
				ris = DListInsertBack(ris, &sum);
				tmp1 = DListGetTail(tmp1);
				tmp2 = DListGetTail(tmp2);
				continue;
			}
			ris = DListInsertHead(&sum, ris);
			tmp1 = DListGetTail(tmp1);
		}
	}
	else {
		while (!DListIsEmpty(tmp1)) {
			ElemType sum = *DListGetHeadValue(tmp1) + *DListGetHeadValue(tmp2);
			if (rip == true) {
				sum++;
				rip = false;
			}
			if (sum > 9) {
				rip = true;
				sum = sum % 10;
			}
			else {
				ris = DListInsertBack(ris, &sum);
				tmp1 = DListGetTail(tmp1);
				tmp2 = DListGetTail(tmp2);
				continue;
			}
			ris = DListInsertHead(&sum, ris);
			tmp1 = DListGetTail(tmp1);
			tmp2 = DListGetTail(tmp2);
		}
		while (!DListIsEmpty(tmp2)) {
			ElemType sum = *DListGetHeadValue(tmp2);
			if (rip == true) {
				sum++;
				rip = false;
			}
			if (sum > 9) {
				rip = true;
				sum = sum % 10;
			}
			else {
				ris = DListInsertBack(ris, &sum);
				tmp1 = DListGetTail(tmp1);
				tmp2 = DListGetTail(tmp2);
				continue;
			}
			ris = DListInsertHead(&sum, ris);
			tmp2 = DListGetTail(tmp2);
		}
	}

	if (rip == true) {
		ElemType sum = 1;
		ris = DListInsertHead(&sum, ris);
	}

	return ris;
}