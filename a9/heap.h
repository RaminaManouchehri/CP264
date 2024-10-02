/*
 -------------------------------------
 File:    heap.h
 Project: a09
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#ifndef HEAP_H
#define HEAP_H

typedef int KEYTYPE;
typedef int VALUETYPE;

typedef struct {
	KEYTYPE key;
	VALUETYPE value;
} HEAPDATA;

typedef struct heap {
	unsigned int size;
	unsigned int capacity;
	HEAPDATA *hda;
} HEAP;

HEAP* new_heap(int capacity);

void heap_insert(HEAP *heap, HEAPDATA data);

HEAPDATA heap_find_min(HEAP *heap);

HEAPDATA heap_extract_min(HEAP *heap);

int heap_change_key(HEAP *heap, int index, KEYTYPE new_key);

int heap_search_data(HEAP *heap, VALUETYPE val);

void heap_clean(HEAP **heapp);

#endif
