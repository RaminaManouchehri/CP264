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

BSTNODE* new_node(RECORD data);
BSTNODE* extract_smallest_node(BSTNODE **rootp);

BSTNODE* bst_search(BSTNODE *root, char *key) {
// your code
	BSTNODE *curr = root;
	if (curr) {
		while (curr) {
			int comp = strcmp(curr->data.name, key);
			if (comp == 0) {
				return curr;
				break;
			} else if (comp > 0) {
				curr = curr->left;
			} else {
				curr = curr->right;
			}
		}

	}
	return NULL;
}

void bst_insert(BSTNODE **rootp, RECORD data) {
// your code
	BSTNODE *new = (BSTNODE*) malloc(sizeof(BSTNODE));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	BSTNODE *curr = *rootp;
	if (curr) {
		while (curr) {
			int comp = strcmp(new->data.name, curr->data.name);
			if (comp > 0) {
				if (curr->right == NULL) {
					curr->right = new;
					break;
				} else {
					curr = curr->right;
				}
			} else if ((comp < 0)) {
				if (curr->left == NULL) {
					curr->left = new;
					break;
				} else {
					curr = curr->left;
				}
			} else {
				free(new);
				return;
			}

		}
	} else {
		*rootp = new;
	}

}

void bst_delete(BSTNODE **rootp, char *key) {
// your code
	if (*rootp) {
		BSTNODE *curr = *rootp, *parent = NULL;
		while (curr) {
			int comp = strcmp(key, curr->data.name);
			if (comp == 0) {
				break;
			} else {
				parent = curr;
				if (comp > 0) {
					curr = curr->right;
				} else {
					curr = curr->left;
				}
			}
		}
		if (curr->left == NULL && curr->right == NULL) {
			if (parent == NULL) {
				*rootp = NULL;
				free(curr);
			} else if (parent->left == curr) {
				parent->left = NULL;
			} else {
				parent->right = NULL;
			}
		} else if (curr->left == NULL && curr->right != NULL) {
			if (parent == NULL) {
				*rootp = curr->right;
				free(curr);
			} else if (parent->left == curr) {
				parent->left = curr->right;
			} else {
				parent->right = curr->right;
			}
		} else if (curr->left != NULL && curr->right == NULL) {
			if (parent == NULL) {
				*rootp = curr->left;
				free(curr);
			} else if (parent->left == curr) {
				parent->left = curr->right;
			} else {
				parent->right = curr->right;
			}
		} else if (curr->left != NULL && curr->right != NULL) {
			BSTNODE *smallest = extract_smallest_node(&curr->right);
			if (parent == NULL) {
				*rootp = smallest;
			} else if (parent->left == curr) {
				parent->left = smallest;
			} else {
				parent->right = smallest;
			}
			smallest->left = curr->left;
			smallest->right = curr->right;
		}
		free(curr);
	}
}

BSTNODE* new_node(RECORD data) {
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
