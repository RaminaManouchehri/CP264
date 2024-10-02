/*
 -------------------------------------
 File:    hash.c
 Project: a09
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
/* Search the hash table and return the pointer of found hashnode
 * @param ht - pointer to a HASHTABLE
 * @param key - input search key string
 * @return - pointer to the found HASHNODE, otherwise NULL
 */
HASHNODE* hashtable_search(HASHTABLE *ht, char *key) {
// your code
	int i = hash(key, ht->size);
	HASHNODE *p = ht->hna[i];
	if (p != NULL) {
		while (p != NULL) {
			if (strcmp(p->key, key) == 0) {
				return p;
			}
			p = p->next;
		}
	}
	return NULL;
}
/* Insert key value data into HASHTABLE, so that each linked list maintains the increasing order of keys.
 * @param ht - pointer to a HASHTABLE
 * @param key - key string
 * @param value - int value
 * #return - when the HASHNODE of the key exists, update its value and return 0;
 * otherwise insert into the hash table and return 1
 */
int hashtable_insert(HASHTABLE *ht, char *key, int value) {
// your code
	HASHNODE *np = (HASHNODE*) malloc(sizeof(HASHNODE));
	int i = hash(key, ht->size);
	strcpy(np->key, key);
	np->value = value;
	np->next = NULL;
	HASHNODE *p = *(ht->hna + i), *pp = NULL;
	while ((p != NULL && strcmp(p->key, key) < 0)) {
		pp = p;
		p = p->next;
	}
	if (pp == NULL) {
		np->next = ht->hna[i];
		ht->hna[i] = np;
	} else {
		np->next = p;
		pp->next = np;
	}
	ht->count++;
	return 1;
}
/* Delete hashnode by key.
 * @param ht - pointer to a HASHTABLE
 * @param key - delete key string
 * @return - if the named hash node exists, delete it and return 1; otherwise return 0.
 */

int hashtable_delete(HASHTABLE *ht, char *key) {
// your code
	int a = hash(key, ht->size);
	HASHNODE *pointer = *(ht->hna + a), *previous = NULL;
	if (pointer != NULL) {
		while (pointer != NULL) {
			if (strcmp(pointer->key, key) == 0) {
				if (previous) {
					previous->next = pointer->next;
				} else {
					*(ht->hna + a) = pointer->next;
				}
				free(pointer);
				ht->count--;
				return 1;
			}

			previous = pointer;
			pointer = pointer->next;
		}
	}

	return 0;
}

int hash(char *key, int size) {
	unsigned int hash = 0;
	while (*key) {
		hash += *key++;
	}
	return hash % size;
}

HASHTABLE* new_hashtable(int size) {
	HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
	ht->hna = (HASHNODE**) malloc(sizeof(HASHNODE**) * size);
	int i;
	for (i = 0; i < size; i++)
		*(ht->hna + i) = NULL;

	ht->size = size;
	ht->count = 0;
	return ht;
}

void hashtable_clean(HASHTABLE **htp) {
	if (*htp == NULL)
		return;
	HASHTABLE *ht = *htp;
	HASHNODE *p, *temp;
	int i;
	for (i = 0; i < ht->size; i++) {
		p = ht->hna[i];
		while (p) {
			temp = p;
			p = p->next;
			free(temp);
		}
		ht->hna[i] = NULL;
	}
	free(ht->hna);
	ht->hna = NULL;
	*htp = NULL;
}
