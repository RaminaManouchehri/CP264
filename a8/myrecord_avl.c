/*
 -------------------------------------
 File:    myrecord_avl.c
 Project: a8
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-16
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avl.h"
#include "myrecord_avl.h"

void merge_avl(AVLNODE **dest_rootp, AVLNODE **source_rootp) {
// your code
	AVLNODE *node = *source_rootp;
	if (node) {
		avl_insert(dest_rootp, node->data);
		if (node->left)
			merge_avl(dest_rootp, &node->left);
		if (node->right)
			merge_avl(dest_rootp, &node->right);
	}
}

void merge_avlds(AVLDS *dest, AVLDS *source) {
// your code
	int c1 = dest->count;
	int c2 = source->count;

	float m1 = dest->mean;
	float m2 = source->mean;
	float stddev1 = dest->stddev;
	float stddev2 = source->stddev;

	merge_avl(&dest->root, &source->root);
	dest->count = c1 + c2;
	dest->mean = (m1 * c1 + m2 * c2) / dest->count;

	int difference = ((stddev1 * stddev1 * c1) + (m1 * m1 * c1)
			+ (stddev2 * stddev2 * c2) + (m2 * m2 * c2)) / dest->count
			- (dest->mean * dest->mean);
	dest->stddev = sqrt(difference);

}

void clean_avlds(AVLDS *ds) {
	clean_avl(&ds->root);
	ds->count = 0;
	ds->mean = 0;
	ds->stddev = 0;
}

// the following functions are adapted from a7q3
void add_record(AVLDS *tree, RECORD data) {
	if (avl_search(tree->root, data.name) == NULL) {
		avl_insert(&(tree->root), data);
		int count = tree->count;
		float mean = tree->mean;
		float stddev = tree->stddev;
		tree->count = count + 1;
		tree->mean = (mean * count + data.score) / (count + 1.0);
		tree->stddev = sqrt(
				data.score * data.score / (count + 1.0)
						+ (stddev * stddev + mean * mean)
								* (count / (count + 1.0))
						- tree->mean * tree->mean);
	} else {
		printf("record exits");
	}
}

void remove_record(AVLDS *tree, char *name) {
	AVLNODE *np = NULL;
	if ((np = avl_search(tree->root, name)) != NULL) {
		float score = np->data.score;
		avl_delete(&(tree->root), name);
		float count = tree->count;
		float mean = tree->mean;
		float stddev = tree->stddev;
		tree->count = count - 1;
		if (count >= 3) {
			tree->mean = (mean * count - score) / (count - 1.0);
			tree->stddev = sqrt(
					(stddev * stddev + mean * mean) * (count / (count - 1.0))
							- score * score / (count - 1.0)
							- tree->mean * tree->mean);
		} else if (count == 2) {
			tree->mean = mean * count - score;
			tree->stddev = 0;
		} else {
			tree->mean = 0;
			tree->stddev = 0;
		}
	} else {
		printf("record does not exit");
	}
}

