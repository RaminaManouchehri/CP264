/*
 -------------------------------------
 File:    bst.h
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

#ifndef BST_H
#define BST_H

typedef struct record {
	char name[40];
	float score;
} RECORD;

typedef struct bstnode {
	RECORD data;
	struct bstnode *left;
	struct bstnode *right;
} BSTNODE;

BSTNODE* bst_search(BSTNODE *root, char *key);

void bst_insert(BSTNODE **rootp, RECORD data);

void bst_delete(BSTNODE **rootp, char *key);
static BSTNODE* new_node(RECORD data);
BSTNODE* extract_smallest_node(BSTNODE **rootp);
void clean_bst(BSTNODE **rootp);

#endif

