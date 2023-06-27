#include "elemtype.h"
#include "tree.h"

Node* TreeCopy(const Node* t) {

	if (TreeIsEmpty(t)) {
		return NULL;
	}

	Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
	n->left = TreeCopy(TreeLeft(t));
	n->right = TreeCopy(TreeRight(t));

	return n;
}

Node* MergeTreeRec(const Node* t1, const Node* t2) {

	Node* ris = TreeCreateEmpty();
	ElemType e1 = 0, e2 = 0, sum;

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return NULL;
	}
	else if (TreeIsEmpty(t1)) {
		e1 = 0;
		e2 = *TreeGetRootValue(t2);
	}
	else if (TreeIsEmpty(t2)) {
		e2 = 0;
		e1 = *TreeGetRootValue(t1);
	}
	else {
		e1 = *TreeGetRootValue(t1);
		e2 = *TreeGetRootValue(t2);
	}
	sum = e1 + e2;
	ris = TreeCreateRoot(&sum, NULL, NULL);

	ris->left = MergeTreeRec(TreeLeft(t1), TreeLeft(t2));
	ris->right = MergeTreeRec(TreeRight(t1), TreeRight(t2));

	return ris;
}

Node* MergeTree(const Node* t1, const Node* t2) {

	Node* ris = TreeCreateEmpty();

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return ris;
	}
	else if (TreeIsEmpty(t1)) {
		ris = TreeCopy(t2);
		return ris;
	}
	else if (TreeIsEmpty(t2)) {
		ris = TreeCopy(t1);
		return ris;
	}

	ris = MergeTreeRec(t1, t2);

	return ris;
}