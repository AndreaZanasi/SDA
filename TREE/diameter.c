#include "elemtype.h"
#include "tree.h"

void GetDiameter(const Node* t, int* lvlmax, int lvl) {

	if (*lvlmax < lvl) {
		*lvlmax = lvl;
	}

	if (!TreeIsEmpty(TreeLeft(t))) {
		GetDiameter(t->left, lvlmax, lvl + 1);
	}
	if (!TreeIsEmpty(TreeRight(t))) {
		GetDiameter(t->right, lvlmax, lvl + 1);
	}
}

void DiameterRec(const Node* t, int* diam, int node) {

	if (!TreeIsEmpty(t)) {
		node++;
	}
	if (node > *diam) {
		*diam = node;
	}

	if (!TreeIsEmpty(TreeLeft(t))) {
		DiameterRec(t->left, diam,  node);
		node++;
	}
	if (!TreeIsEmpty(TreeRight(t))) {
		DiameterRec(t->right, diam, node);
		node++;
	}
}

int Diameter(const Node* t) {

	if (TreeIsEmpty(t)) {
		return 0;
	}
	if (TreeIsLeaf(t)) {
		return 0;
	}

	int diam = 0;
	int diaml = 0;
	int diamr = 0;

	DiameterRec(t, &diam, 0);
	GetDiameter(t->left, &diaml, 1);
	GetDiameter(t->right, &diamr, 1);
	if (diaml + diamr + 1 > diam) {
		diam = diaml + diamr + 1;
	}

	return diam;
}