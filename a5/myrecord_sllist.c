/*
 -------------------------------------
 File:    myrecord_sllist.c
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
#include <string.h>
#include "myrecord_sllist.h"

/**
 * Search singly linked list by the key name.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - key to search
 * @return Pointer to found node if found; otherwise NULL
 */

NODE* sll_search(SLL *sllp, char *name) {
// your code
	int is_found = 0;
	NODE *ptr = sllp->start;
	while (ptr != NULL && is_found == 0) {
		if (strcmp(ptr->data.name, name) == 0) {
			is_found = 1;
		} else {
			ptr = ptr->next;
		}
	}
	if (is_found == 0) {
		ptr = NULL;
	}
	return ptr;
}

void sll_insert(SLL *sllp, char *name, float score) {
// your code
	NODE *p = (NODE*) malloc(sizeof(NODE));
	strcpy(p->data.name, name);
	p->data.score = score;
	p->next = NULL;
	NODE *prev = NULL;
	NODE *ptr = sllp->start;
	while (ptr != NULL) {
		if (strcmp(ptr->data.name, name) >= 0)
			break;
		prev = ptr;
		ptr = ptr->next;
	}
	if (prev == NULL) {
		sllp->start = p;
		p->next = ptr;
	} else {
		prev->next = p;
		p->next = ptr;
	}
	sllp->length++;
}

int sll_delete(SLL *sllp, char *name) {
// your code
	int found = 0;
	NODE *prev = NULL;
	NODE *ptr = sllp->start;
	while (ptr != NULL) {
		if (strcmp(ptr->data.name, name) == 0) { // found the node
			found = 1;
			if (prev == NULL) {
				sllp->start = ptr->next;
			} else {
				prev->next = ptr->next;
			}
			free(ptr);
			sllp->length--;
			break; // action
		}
		prev = ptr; // move to next
		ptr = ptr->next; // move to next
	}
	return found;
}

void sll_clean(SLL *sllp) {
	NODE *temp, *ptr = sllp->start;
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	sllp->start = NULL;
	sllp->length = 0;
}
