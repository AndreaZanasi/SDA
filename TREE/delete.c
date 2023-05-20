#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>

void Iterate(Node* n, int liv, int* liv_min, Node** min) {

	if (liv > *liv_min) {
		*liv_min = liv;
		*min = n;
	}

	if (n->left != NULL) {
		Iterate(n->left, liv + 1, liv_min, min);
	}
	if (n->right != NULL) {
		Iterate(n->right, liv + 1, liv_min, min);
	}

	return;
}

void DeleteBstNodeRec(Node* n, const ElemType* key, Node* prec, bool mag) {

	if (ElemCompare(TreeGetRootValue(n), key) == 0) {
		if (TreeIsLeaf(n)) {
			if (mag == true) {
				free(&n->value);
				prec->right = NULL;
			}
			else {
				free(&n->value);
				prec->left = NULL;
			}
			return;
		}
		else if (n->left == NULL) {
			if (mag == true) {
				free(&n->value);
				prec->right = n->right;
			}
			else {
				free(&n->value);
				prec->left = n->right;
			}
			return;
		}
		else if (n->right == NULL) {
			if (mag == true) {
				free(&n->value);
				prec->right = n->left;
			}
			else {
				free(&n->value);
				prec->left = n->left;
			}
			return;
		}

		int liv_min;

		if (mag == true) {
			Iterate(n->left, 0, &liv_min, &prec->right);
			prec->right->right = n->right;
			prec->right->left = n->left;
			return;
		}
		else {
			Iterate(n->left, 0, &liv_min, &prec->left);
			prec->left->right = n->right;
			prec->left->left = n->left;
			return;
		}

	}

	if (n->left == NULL && n->right == NULL) {
		return;
	}

	if (ElemCompare(key, TreeGetRootValue(n)) > 0 && n->right != NULL) {
		DeleteBstNodeRec(n->right, key, n, true);
	}

	else if (ElemCompare(key, TreeGetRootValue(n)) <= 0 && n->left != NULL) {
		DeleteBstNodeRec(n->left, key, n, false);
	}
}

Node* DeleteBstNode(Node* n, const ElemType* key) {

	if (TreeIsEmpty(n)) {
		return NULL;
	}

	if (ElemCompare(TreeGetRootValue(n), key) == 0) {
		if (n->right == NULL) {
			free(&n->value);
			return n->left;
		}
		else if (n->left == NULL) {
			free(&n->value);
			return n->right;
		}
		else if (TreeIsLeaf(n)){
			free(&n->value);
			return NULL;
		}

		int liv_min = 0;
		Node* prec = n;

		Iterate(n->left, 0, &liv_min, &n);
		n->left = prec->left;
		n->right = prec->right;
		free(&prec->value);
		return n;

	}

	DeleteBstNodeRec(n, key, n, false);

	return n;
}