#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>

void TreeContainsNode(const Node* tree, const Node* to_search, bool* find) {

	if (TreeIsEmpty(tree)) {
		return;
	}

	if (*find == true) {
		return;
	}

	if (tree == to_search) {
		*find = true;
		return;
	}
	
	TreeContainsNode(TreeLeft(tree), to_search, find);
	TreeContainsNode(TreeRight(tree), to_search, find);
}

const Node* LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, bool* find, int lvl, int lvl_max, const Node* root) {

	if (TreeIsEmpty(t)) {
		return root;
	}

	bool f1 = false, f2 = false;
	TreeContainsNode(t, n1, &f1);
	TreeContainsNode(t, n2, &f2);

	if (f1 && f2) {
		if (lvl > lvl_max) {
			lvl_max = lvl;
			root = t;
		}
		root = LowestCommonAncestorRec(TreeLeft(t), n1, n2, find, lvl + 1, lvl_max, root);
		root = LowestCommonAncestorRec(TreeRight(t), n1, n2, find,lvl + 1, lvl_max, root);
	}
	else {
		return root;
	}
	
	return root;
}

const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	bool find = false;
	const Node* root = t;
	root = LowestCommonAncestorRec(t, n1, n2, &find, 0, 0, root);
	return root;
}