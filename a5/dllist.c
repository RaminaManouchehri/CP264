/*
 -------------------------------------
 File:    dllist.c
 Project: a05
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

NODE* new_node(char data) {
// your code
	NODE *p = (NODE*) malloc(sizeof(NODE));
	p->next = NULL;
	p->prev = NULL;
	p->data = data;
	return p;
}

/*
 * Insert a given node at the beginning the of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 * @param NODE *np  -  reference of a NODE node to be inserted
 */

void dll_insert_start(DLL *dllp, NODE *np) {
// your code
	np->next = dllp->start;
	if (dllp->start != NULL) {
		dllp->start->prev = np;
	} else {
		dllp->end = np;
	}
	np->prev = NULL;

	dllp->start = np;
	dllp->length++;
}

void dll_insert_end(DLL *dllp, NODE *np) {
// your code
	if (dllp->end != NULL) {
		(dllp->end)->next = np;
		np->prev = (dllp->end);
	} else {
		(dllp->start) = np;
	}
	(dllp->end) = np;
	dllp->length++;
	return;
}

void dll_delete_start(DLL *dllp) {
// your code
	NODE *p = dllp->start;
	if (dllp->start != NULL) {
		(dllp->start) = (dllp->start)->next;
		if (dllp->start != NULL) {
			(dllp->start)->prev = NULL;
		} else {
			dllp->end = NULL;
		}
		free(p);
		dllp->length--;
	}
}

void dll_delete_end(DLL *dllp) {
// your code
	NODE *ptr = dllp->end;

	dllp->end = dllp->end->prev;
	if (dllp->end != NULL) {
		(dllp->end)->next = NULL;
	} else {
		// List is empty after deletion
		dllp->start = NULL;
	}

	free(ptr);
	dllp->length--;  // Decrement the length
}

void dll_clean(DLL *dllp) {
	NODE *ptr = dllp->start;
	NODE *next = NULL;
	while (ptr != NULL) {
		next = (NODE*) ptr->next;
		free(ptr);
		ptr = next;
		dllp->length--;
	}
	dllp->start = NULL;
	dllp->end = NULL;
	return;
}

