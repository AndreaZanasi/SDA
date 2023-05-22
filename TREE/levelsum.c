#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>

void Iterate(const Node* t, int liv, int* liv_min) {

	if (liv > *liv_min) {
		*liv_min = liv;
	}

	if (TreeIsLeaf(t)) {
		return;
	}

	if (TreeLeft(t) != NULL) {
		Iterate(TreeLeft(t), liv + 1, liv_min);
	}
	if (TreeRight(t) != NULL) {
		Iterate(TreeRight(t), liv + 1, liv_min);
	}

	return;
}

void LevelSumRec(const Node* t, size_t level, int* ris, size_t liv_curr) {

	if (liv_curr == level) {
		*ris += (int)*TreeGetRootValue(t);
		return;
	}
	if (TreeLeft(t) != NULL) {
		LevelSumRec(t->left, level, ris, liv_curr + 1);
	}
	if (TreeRight(t) != NULL) {
		LevelSumRec(t->right, level, ris, liv_curr + 1);
	}
	return;
}

int LevelSum(const Node* t, size_t level) {

	if (TreeIsEmpty(t)) {
		return 0;
	}

	if (level == 0) {
		ElemType e = *TreeGetRootValue(t);
		return (int)e;
	}

	int liv_min = 0;
	Iterate(t, 0, &liv_min);
	if ((int)level > liv_min) {
		return 0;
	}

	int ris = 0;

	LevelSumRec(t, level, &ris, 0);

	return ris;
}