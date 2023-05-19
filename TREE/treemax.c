#include "elemtype.h"
#include "tree.h"

const ElemType* TreeMaxRec(const Node* n, const ElemType* max, int liv, int* liv_max) {

	if (ElemCompare(max, TreeGetRootValue(n)) < 0) {
		*liv_max = liv;
		max = TreeGetRootValue(n);
	}
	if (n->left == NULL && n->right == NULL) {
		return max;
	}
	if (n->left != NULL) {
		max = TreeMaxRec(n->left, max, liv + 1, liv_max);
	}
	if (n->right != NULL) {
		max = TreeMaxRec(n->right, max, liv + 1, liv_max);
	}
	return max;
}

const ElemType* TreeMax(const Node* n) {

	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType *maxl = TreeGetRootValue(n);
	const ElemType *maxr = TreeGetRootValue(n);
	int il = 0;
	int ir = 0;
	maxl = TreeMaxRec(n->left, maxl, 0, &il);
	maxr = TreeMaxRec(n->right, maxr, 0, &ir);

	if (ElemCompare(maxl, maxr) >= 0) {
		if (ElemCompare(maxl, maxr) == 0) {
			if (ir == il) {
				return maxl;
			}
			else if(ir < il){
				return maxr;
			}
			else if (il < ir) {
				return maxl;
			}
		}
		return maxl;
	}
	else {
		return maxr;
	}

}

void BstTreeMaxRec(const Node* n, const ElemType** max) {
	if (n == NULL) {
		return;
	}

	*max = TreeGetRootValue(n);
	BstTreeMaxRec(n->right, max);

}

const ElemType* BstTreeMax(const Node* n) {

	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType* max = TreeGetRootValue(n);

	BstTreeMaxRec(n, &max);

	return max;
}