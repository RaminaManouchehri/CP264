/*
 -------------------------------------
 File:    bst.c
 Project: a7
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-09
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

BSTNODE* extract_smallest_node(BSTNODE **rootp);

BSTNODE* bst_search(BSTNODE *root, char *key) {
// your code
	BSTNODE *curr = root;
	int found = 0;
	while (!found && curr) {
		int compare = strcmp(curr->data.name, key);
		if (compare == 0) {
			found = 1;
		} else if (compare > 0) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}
	return curr;
}

void bst_insert(BSTNODE **rootp, RECORD data) {
// your code
	RECORD new_record;
	new_record.score = data.score;
	strcpy(new_record.name, data.name);

	BSTNODE *node = (BSTNODE*) malloc(sizeof(BSTNODE));
	node->data = new_record;
	node->right = NULL;
	node->left = NULL;
	if (*rootp == NULL) {
		*rootp = node;
		return;
	}

	BSTNODE *m = *rootp;
	node->data = new_record;
	node->right = NULL;
	node->left = NULL;
	while (1) {
		int cmp = strcmp(node->data.name, m->data.name);
		if (cmp == 0) {
			free(node);
			return;
		} else if (cmp < 0) {
			if (m->left == NULL) {
				m->left = node;
				break;
			} else {
				m = m->left;
			}
		} else {
			if (m->right == NULL) {
				m->right = node;
				break;
			} else {
				m = m->right;
			}
		}

	}
}

void bst_delete(BSTNODE **rootp, char *key) {
// your code
	BSTNODE *curr = *rootp;
	BSTNODE *parent = NULL;
	BSTNODE *smallest_node;
	//find the node
	while (curr != NULL && strcmp(curr->data.name, key) != 0) {
		parent = curr;
		curr = (strcmp(key, curr->data.name) < 0) ? curr->left : curr->right;
	}
	if (curr != NULL) { //nothing to do if the node doesn't exist
		//delete and rearrange nodes
		if (curr->right == NULL) {
			if (parent == NULL) {
				*rootp = curr->left;
			} else {
				if (parent->left == curr)
					parent->left = curr->left;
				else
					parent->right = curr->left;
			}
		} else {
			smallest_node = extract_smallest_node(&curr->right);
			if (parent == NULL) {
				*rootp = smallest_node;
			} else {
				if (parent->left == curr)
					parent->left = smallest_node;
				else
					parent->right = smallest_node;
			}
			smallest_node->left = curr->left;
			smallest_node->right = curr->right;
		}
		free(curr);

	}

}

static BSTNODE* new_node(RECORD data) {
	BSTNODE *np = (BSTNODE*) malloc(sizeof(BSTNODE));
	if (np) {
		memcpy(np, &data, sizeof(BSTNODE));
		np->left = NULL;
		np->right = NULL;
	}
	return np;
}

BSTNODE* extract_smallest_node(BSTNODE **rootp) {
	BSTNODE *p = *rootp, *parent = NULL;
	if (p) {
		while (p->left) {
			parent = p;
			p = p->left;
		}

		if (parent == NULL)
			*rootp = p->right;
		else
			parent->left = p->right;

		p->left = NULL;
		p->right = NULL;
	}

	return p;
}

void clean_bst(BSTNODE **rootp) {
	BSTNODE *root = *rootp;
	if (root) {
		if (root->left)
			clean_bst(&root->left);
		if (root->right)
			clean_bst(&root->right);
		free(root);
	}
	*rootp = NULL;
}
