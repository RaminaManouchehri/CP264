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
#include "queue_stack.h"
#include "tree.h"

/* Compute and return the TPROPS value of a tree.
 * @param root - pointer to the root of a tree
 * @return - number of nodes and height in TPROPS type.
 */
TPROPS tree_property(TNODE *root) {
// your code
	TPROPS r = { 0 };
	if (!root)
		return r;
	else {
		TPROPS l = tree_property(root->left);
		TPROPS m = tree_property(root->right);
		r.order = 1 + l.order + m.order;
		r.height = (l.height > m.height) ? l.height + 1 : m.height + 1;
		return r;
	}

}
/* Display the node data of the tree in pre-order and format "%c ".
 *
 *  @param root - pointer to the root of a tree
 */
void preorder(TNODE *root) {
// your code
	if (root) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
/* Display the node data of the tree in in-order and format "%c".
 *
 *  @param root - pointer to the root of a tree
 */
void inorder(TNODE *root) {
// your code
	if (root) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}
/* Display the node data of the tree in post-order and format "%c ".
 *
 *  @param root - pointer to the root of a tree
 */
void postorder(TNODE *root) {
// your code
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}
/* Display the node data of the tree in breadth-first-order and format "%c ".
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 */
void bforder(TNODE *root) {
// your code
	if (root == NULL)
		return;
	TNODE *t = NULL;
	QUEUE queue = { 0 };
	enqueue(&queue, root);
	while (queue.front) {
		t = dequeue(&queue);
		if (t) {
			printf("%c ", t->data);
			enqueue(&queue, t->left);
			enqueue(&queue, t->right);
		}
	}
}

/* Search by key using breadth-first-search algorithm
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 *  @param key -  search key
 *
 *  @return  - the found node pointer if fount, otherwise NULL
 */
TNODE* bfs(TNODE *root, char val) {
// your code
	TNODE *r = NULL;
	if (root) {
		QUEUE queue = { 0 };  // auxiliary queue for BST
		enqueue(&queue, root);
		while (queue.front) {
			TNODE *tnp = (TNODE*) dequeue(&queue);
			//check match, if r=p, break;
			if (tnp->data == val) {
				r = tnp;
				break;
			}
			if (tnp->left) {
				enqueue(&queue, tnp->left);
			}
			if (tnp->right) {
				enqueue(&queue, tnp->right);
			}
		}
		clean_queue(&queue);
	}
	return r;
}

/* Search by key using depth-first-search algorithm.
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 *  @param key -  search key
 *
 *  @return  - the found node pointer if fount, otherwise NULL
 */
TNODE* dfs(TNODE *root, char val) {
// your code
	TNODE *r = NULL;
	if (root) {
		STACK stack = { 0 };
		push(&stack, root);
		while (stack.top) {
			TNODE *p = (TNODE*) pop(&stack);
			if (p->data == val) {
				r = p;
				break;
			}
			if (p->left) {
				push(&stack, p->left);
			}
			if (p->right) {
				push(&stack, p->right);
			}
		}
		clean_stack(&stack);
	}
	return r;
}

// the following functions are given, need to add to your program.
// The following functions are given in a7 help.

/* Create a TNODE node and sets the data to value and returns the pointer.
 * Use malloc()
 */
TNODE* new_node(char val) {
	TNODE *np = (TNODE*) malloc(sizeof(TNODE));
	if (np != NULL) {
		np->data = val;
		np->left = NULL;
		np->right = NULL;
	}
	return np;
}
/* This function cleans a tree.
 * @param rootp - pointer of pointer to the tree root
 */
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
/* This function creates a new node of given value and inserts it into a tree
 * at the first available position in order of breadth-first and left to right.
 *
 * @param rootp - pointer of pointer to the tree node.
 * @param val - data for the new node.
 */
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

