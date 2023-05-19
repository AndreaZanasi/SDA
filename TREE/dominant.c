#include "elemtype.h"
#include "tree.h"

int CountDominantRec(const Node* t) {

	int dom = 0;

	if (t->left == NULL && t->right == NULL) {
		return 0;
	}

	ElemType a, b;
	if (t->left == NULL) {
		a = 0;
	}
	else {
		a = *TreeGetRootValue(t->left);
	}
	if (t->right == NULL) {
		b = 0;
	}
	else {
		b = *TreeGetRootValue(t->right);
	}


	ElemType sum = a + b;

	if (ElemCompare(TreeGetRootValue(t), &sum) > 0) {
		dom++;
	}
	if (t->left != NULL) {
		dom += CountDominantRec(t->left);
	}
	if (t->right != NULL) {
		dom += CountDominantRec(t->right);
	}

	return dom;
}

int CountDominant(const Node* t) {

	if (TreeIsEmpty(t)) {
		return 0;
	}

	int dom = 0;
	dom = CountDominantRec(t);

	return dom;
}