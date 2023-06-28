#include "elemtype.h"
#include "tree.h"

void InvertRec(Node* left, Node* right) {

	if (TreeIsEmpty(left) && TreeIsEmpty(right)) {
		return;
	}

	ElemType tmp = left->value;
	left->value = right->value;
	right->value = tmp;

	InvertRec(left->left, right->right);
	InvertRec(left->right, right->left);
}

Node* Invert(Node* t) {

	if (TreeIsEmpty(t)) {
		return NULL;
	}
	if (TreeIsLeaf(t)) {
		return t;
	}

	InvertRec(t->left, t->right);

	return t;
}