#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>

void Iterate(const Node* t, int n, bool* res, const ElemType* value, bool isvleft, size_t vlvl, bool issleft, size_t slvl) {

	if (issleft == isvleft && vlvl == slvl) {
		return;
	}
	if (*value + *TreeGetRootValue(t) == (ElemType)n) {
		*res = true;
		return;
	}
	
	if (t->left != NULL) {
		Iterate(t->left,n,res, value, isvleft, vlvl, true, slvl + 1);
	}
	if (t->right != NULL) {
		Iterate(t->right, n, res, value, isvleft, vlvl, false, slvl + 1);
	}
}

void CheckSumNRec(const Node* t, int n, bool* res, const Node* tmp, bool isvleft, size_t vlvl) {

	Iterate(t, n, res, TreeGetRootValue(tmp), isvleft, vlvl, false, 0);

	if (tmp->left != NULL) {
		CheckSumNRec(t, n, res, tmp->left, true, vlvl + 1);
	}
	else {
		return;
	}
	if (tmp->right != NULL) {
		CheckSumNRec(t, n, res, tmp->right, false, vlvl + 1);
	}
	else {
		return;
	}
}

bool CheckSumN(const Node* t, int n) {

	if (TreeIsEmpty(t)) {
		return false;
	}

	bool res = false;

	CheckSumNRec(t, n, &res, t, false, 0);

	return res;
}