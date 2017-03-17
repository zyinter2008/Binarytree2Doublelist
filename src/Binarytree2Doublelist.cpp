#include <iostream>
#include <stdio.h>
using namespace std;

struct BSTreeNode {
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

void addValue2BsTree(BSTreeNode **current, int value);
void printValue(BSTreeNode *root);
void sortTree(BSTreeNode *root);
void convert2Doublelist(BSTreeNode *root);

BSTreeNode *pHead = NULL;
BSTreeNode *pIndex = NULL;

int main() {
	BSTreeNode *root = NULL;
	int data[] = { 10, 6, 14, 4, 8, 12, 16 };
	for (int i = 0; i < 7; i++) {
		addValue2BsTree(&root, data[i]);
	}
	printValue(root);
	sortTree(root);
	return 0;
}

void addValue2BsTree(BSTreeNode **current, int value) {
	if (*current == NULL) {
		BSTreeNode* pTree = new BSTreeNode();
		pTree->m_nValue = value;
		pTree->m_pLeft = NULL;
		pTree->m_pRight = NULL;
		*current = pTree;
	} else if ((*current)->m_nValue > value) {
		addValue2BsTree(&(*current)->m_pLeft, value);
	} else if ((*current)->m_nValue < value) {
		addValue2BsTree(&(*current)->m_pRight, value);
	} else {
		cout << "Equal value" << endl;
	}
}

void sortTree(BSTreeNode *root) {
	if (root == NULL) {
		return;
	}

	if (root->m_pLeft != NULL) {
		sortTree(root->m_pLeft);
	}

	convert2Doublelist(root);

	if (root->m_pRight != NULL) {
		sortTree(root->m_pRight);
	}
}

void printValue(BSTreeNode *root) {
	if (root != NULL) {
		printf("vlaue is %d\n", root->m_nValue);

		printValue(root->m_pLeft);
		printValue(root->m_pRight);
	}
}

void convert2Doublelist(BSTreeNode *root) {

	root->m_pLeft = pIndex;
	if (pIndex == NULL) {
		pHead = root;
	} else {
		pIndex->m_pRight = root;
	}
	pIndex = root;
	printf("sort vlaue is [%d]\n", root->m_nValue);
}
