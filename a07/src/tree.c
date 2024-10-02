/*
 -------------------------------------
 File:    tree.c
 Project: a7
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-09
 -------------------------------------
 */
/*
 * your program signature
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_stack.h"
#include "tree.h"

TPROPS tree_property(TNODE *root) {
// your code
	TPROPS r = { 0 };
	if (root) {
		TPROPS lp = tree_property(root->left);
		TPROPS rp = tree_property(root->right);
		r.order = 1 + lp.order + rp.order;
		r.height = (lp.height > rp.height) ? lp.height + 1 : rp.height + 1;
	}
	return r;
}

void preorder(TNODE *root) {
// your code
	if (root) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
	return;
}

void inorder(TNODE *root) {
// your code
	if (root) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
	return;
}

void postorder(TNODE *root) {
// your code
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
	return;
}

void bforder(TNODE *root) {
// your code
	if (root) {
		QUEUE queue = { 0 };
		enqueue(&queue, root);
		while (queue.front) {
			TNODE *p = dequeue(&queue);
			printf("%c ", p->data);
			if (p->left) {
				enqueue(&queue, p->left);
			}
			if (p->right) {
				enqueue(&queue, p->right);
			}
		}

	}
}

TNODE* bfs(TNODE *root, char val) {
	if (root) {
		QUEUE q = { 0 };
		enqueue(&q, root);
		while (q.front) {
			TNODE *ptr = dequeue(&q);
			if (ptr->data == val) {
				return ptr;
				break;
			} else {
				if (ptr->left) {
					enqueue(&q, ptr->left);
				}
				if (ptr->right) {
					enqueue(&q, ptr->right);
				}
			}
		}
		clean_queue(&q);
	}
	return NULL;
}

TNODE* dfs(TNODE *root, char val) {
// your code
	if (root) {
		STACK s = { 0 };
		push(&s, root);
		while (s.top) {
			TNODE *ptr = pop(&s);
			if (ptr->data == val) {
				return ptr;
				break;
			} else {
				if (ptr->left) {
					push(&s, ptr->left);
				}
				if (ptr->right) {
					push(&s, ptr->right);
				}
			}
		}
	}
	return NULL;
}

// the following functions are given, need to add to your program.

TNODE* new_node(char val) {
	TNODE *np = (TNODE*) malloc(sizeof(TNODE));
	if (np != NULL) {
		np->data = val;
		np->left = NULL;
		np->right = NULL;
	}
	return np;
}

void clean_tree(TNODE **rootp) {
	TNODE *p = *rootp;
	if (p) {
		if (p->left)
			clean_tree(&p->left);
		if (p->right)
			clean_tree(&p->right);
		free(p);
	}
	*rootp = NULL;
}

void insert_tree(TNODE **rootp, char val) {
	if (*rootp == NULL) {
		*rootp = new_node(val);
	} else {
		QUEUE queue = { 0 };
		TNODE *p;
		enqueue(&queue, *rootp);
		while (queue.front) {
			p = dequeue(&queue);
			if (p->left == NULL) {
				p->left = new_node(val);
				break;
			} else {
				enqueue(&queue, p->left);
			}

			if (p->right == NULL) {
				p->right = new_node(val);
				break;
			} else {
				enqueue(&queue, p->right);
			}
		}
	}
}
