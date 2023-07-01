#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

size_t FindMax(const ElemType* v, size_t start, size_t end) {

	size_t posmax = start;
	for (size_t i = start; i < end; i++) {
		if (v[posmax] < v[i]) {
			posmax = i;
		}
	}

	return posmax;
}

Node* CreateMaxBinTreeRec(const ElemType* v, size_t start, size_t end, Node* t) {

	if (start == end) {
		return NULL;
	}

	size_t posmax = FindMax(v, start, end);

	t = TreeCreateRoot(&v[posmax], NULL, NULL);

	t->left = CreateMaxBinTreeRec(v, start, posmax, TreeLeft(t));
	t->right = CreateMaxBinTreeRec(v, posmax + 1, end, TreeRight(t));

	return t;
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {

	if (v == NULL || v_size == 0) {
		return NULL;
	}

	Node* t = TreeCreateEmpty();

	t = CreateMaxBinTreeRec(v, 0, v_size, t);

	return t;
}