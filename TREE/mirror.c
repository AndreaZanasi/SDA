#include "elemtype.h"
#include "tree.h"

void Iterate(Node* t, int liv, int* liv_min) {

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
}

void TreeIsMirrorRec(const Node* tl, const Node* tr, bool* flag) {

	if (ElemCompare(TreeGetRootValue(tl), TreeGetRootValue(tr)) != 0) {
		*flag = false;
		return;
	}

	if (TreeLeft(tl) != NULL && TreeRight(tr) != NULL) {
		TreeIsMirrorRec(TreeLeft(tl), TreeRight(tr), flag);
	}
	if (TreeLeft(tr) != NULL && TreeRight(tl) != NULL) {
		TreeIsMirrorRec(TreeRight(tl), TreeLeft(tr), flag);
	}
	return;
}

bool TreeIsMirror(const Node* t) {

	if (TreeIsEmpty(t)) {
		return true;
	}
	if (TreeGetRootValue(t) != NULL && TreeLeft(t) == NULL && TreeRight(t) == NULL) {
		return true;
	}

	int liv_minl = 0;
	int liv_minr = 0;

	Iterate(TreeLeft(t), 0, &liv_minl);
	Iterate(TreeRight(t), 0, &liv_minr);

	if (liv_minr != liv_minl) {
		return false;
	}

	bool flag = true;
	TreeIsMirrorRec(TreeLeft(t), TreeRight(t), &flag);

	return flag;
}