/*
 -------------------------------------
 File:     myrecord_bst.c
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
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"
void add_record(BSTDS *ds, RECORD record) {
// your code
	if (bst_search(ds->root, record.name) == NULL) {
		bst_insert(&ds->root, record);
		int count = ds->count;
		float mean = ds->mean;
		float stddev = ds->stddev;
		ds->count++;
		ds->mean = (mean * count + record.score) / (count + 1);
		ds->stddev = sqrt(
				(count * (stddev * stddev + mean * mean)
						+ record.score * record.score) / (count + 1)
						- ds->mean * ds->mean);

	}

}

void remove_record(BSTDS *ds, char *name) {
// your code
	BSTNODE *pointer = bst_search(ds->root, name);
	if (pointer != NULL) {
		float score = pointer->data.score;
		bst_delete(&(ds->root), name);
		int count = ds->count;
		float mean = ds->mean;
		float stddev = ds->stddev;
		if (ds->count > 1) {
			ds->count = count - 1;
			ds->mean = ((float) count * mean - score) / ds->count;
			ds->stddev = sqrtf(
					((float) 1 / (float) (ds->count))
							* ((float) count * (stddev * stddev + mean * mean)
									- (score * score)) - (ds->mean * ds->mean));
		} else {

			ds->count = 0;
			ds->mean = 0;
			ds->stddev = 0;
		}
	}
}

void clean_bstds(BSTDS *ds) {
	clean_bst(&ds->root);
	ds->count = 0;
	ds->mean = 0;
	ds->stddev = 0;
}
