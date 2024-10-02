/*
 -------------------------------------
 File:    myrecord_sllist.h
 Project: a05
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */

#ifndef SLL_H
#define SLL_H

typedef struct {
	char name[20];
	float score;
} RECORD;

typedef struct node {
	RECORD data;
	struct node *next;
} NODE;

typedef struct sllist {
	int length;
	NODE *start;
} SLL;

NODE* sll_search(SLL *sllp, char *name);
void sll_insert(SLL *sllp, char *name, float score);
int sll_delete(SLL *sllp, char *name);
void sll_clean(SLL *sllp);

#endif
