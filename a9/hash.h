/*
 -------------------------------------
 File:    hash.h
 Project: a09
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#ifndef HASH_H
#define HASH_H

typedef struct {
	char key[20];
	int value;
} HASHDATA;

typedef struct hashnode {
	char key[20];
	int value;
	struct hashnode *next;
} HASHNODE;

typedef struct hashtable {
	HASHNODE **hna;
	int size;
	int count;
} HASHTABLE;

int hash(char *key, int size);

HASHTABLE* new_hashtable(int size);

int hashtable_insert(HASHTABLE *ht, char *key, int value);

HASHNODE* hashtable_search(HASHTABLE *ht, char *key);

int hashtable_delete(HASHTABLE *ht, char *key);

void hashtable_clean(HASHTABLE **ht);

#endif
