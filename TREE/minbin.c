#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>

int FindMin(const ElemType* v, size_t start, size_t end) {

	int posmin = (int)start;
	for (int i = (int)start; i < end; i++) {
		if (v[posmin] > v[i]) {
			posmin = i;
		}
	}

	return posmin;
}

Node* CreateMinBinTreeRec(const ElemType* v, size_t start, size_t end, Node* t) {

	if (start == end) {
		return NULL;
	}

	int posmin = FindMin(v, start, end);
	t = TreeCreateRoot(&v[posmin], NULL, NULL);
	t->left = CreateMinBinTreeRec(v, start, (size_t)posmin, TreeLeft(t));
	t->right = CreateMinBinTreeRec(v, (size_t)posmin + 1, end, TreeRight(t));
	return t;
}

Node* CreateMinBinTree(const ElemType* v, size_t v_size) {

	if (v == NULL, v_size == 0) {
		return NULL;
	}

	Node* t = TreeCreateEmpty();

	t = CreateMinBinTreeRec(v, 0, v_size, t);

	return t;
}