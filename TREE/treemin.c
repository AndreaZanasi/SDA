#include "elemtype.h"
#include "tree.h"

const ElemType* TreeMinRec(const Node* n, const ElemType* min, int liv, int* liv_min) {

	if (ElemCompare(min, TreeGetRootValue(n)) >= 0 && liv >= *liv_min) {
		*liv_min = liv;
		min = TreeGetRootValue(n);
	}
	if (n->left == NULL && n->right == NULL) {
		return min;
	}
	if (n->left != NULL) {
		min = TreeMinRec(n->left, min, liv + 1, liv_min);
	}
	if (n->right != NULL) {
		min = TreeMinRec(n->right, min, liv + 1, liv_min);
	}
	return min;
}

const ElemType* TreeMin(const Node* n) {

	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType* minl = TreeGetRootValue(n);
	const ElemType* minr = TreeGetRootValue(n);
	int il = 0;
	int ir = 0;
	minl = TreeMinRec(n->left, minl, 0, &il);
	minr = TreeMinRec(n->right, minr, 0, &ir);

	if (ElemCompare(minr, minl) <= 0) {
		if (ElemCompare(minl, minr) == 0) {
			if (ir == il) {
				return minr;
			}
			else if (ir > il) {
				return minr;
			}
			else if (il > ir) {
				return minl;
			}
		}
		return minr;
	}
	else {
		return minl;
	}

}

void BstTreeMinRec(const Node* n, const ElemType** min) {
	if (n == NULL) {
		return;
	}

	*min = TreeGetRootValue(n);
	BstTreeMinRec(n->left, min);

}

const ElemType* BstTreeMin(const Node* n) {

	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType* min = TreeGetRootValue(n);

	BstTreeMinRec(n, &min);

	return min;
}