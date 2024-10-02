/*
 -------------------------------------
 File:    myrecord_avl.h
 Project: a8
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-16
 -------------------------------------
 */
#ifndef MYRECORD_AVL_H
#define MYRECORD_AVL_H

#include "avl.h"

typedef struct {
	AVLNODE *root;
	int count;
	float mean;
	float stddev;
} AVLDS;

void merge_avl(AVLNODE **dest_rootp, AVLNODE **source_rootp);

void merge_avlds(AVLDS *dest, AVLDS *source);

void clean_avlds(AVLDS *ds);

void add_record(AVLDS *ds, RECORD data);

void remove_record(AVLDS *ds, char *name);

#endif
