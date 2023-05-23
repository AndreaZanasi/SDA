#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* TreeReadRec(FILE* f) {

	ElemType node = 0;
	ElemType useless = 0;

	if (ElemRead(f, &useless) == 0) {
		return NULL;
	}

	while (useless == ' ' || useless == '\t' || useless == '\r' || useless == '\n' || useless == '\v' || useless == '\f') {
		ElemRead(f, &useless);
	}

	if (useless == (ElemType)EOF) {
		return NULL;
	}

	node = useless;

	if (node == '.') {
		ElemRead(f, &useless);
		while (useless == ' ' || useless == '\t' || useless == '\r' || useless == '\n' || useless == '\v' || useless == '\f') {
			ElemRead(f, &useless);
		}
		node = useless;
		return TreeCreateRoot(&node, NULL, NULL);
	}

	Node* nl = TreeReadRec(f);
	Node* nr = TreeReadRec(f);

	return TreeCreateRoot(&node, nl, nr);
}

Node* TreeRead(const char* filename) {

	if (filename == NULL) {
		return NULL;
	}

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Node* read = TreeReadRec(f);
	fclose(f);

	return read;
}