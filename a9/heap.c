/*
 -------------------------------------
 File:    heap.c
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
#include "heap.h"

int cmp(KEYTYPE a, KEYTYPE b) {
	int r = 0;
	if (a < b)
		r = -1;
	else if (a > b)
		r = 1;
	return r;
}

HEAP* new_heap(int capacity) {
	HEAP *hp = (HEAP*) malloc(sizeof(HEAP));
	if (hp == NULL)
		return NULL;
	hp->hda = (HEAPDATA*) malloc(sizeof(HEAPDATA) * capacity);
	if (hp->hda == NULL) {
		free(hp);
		return NULL;
	};
	hp->capacity = capacity;
	hp->size = 0;
	return hp;
}

// you may add this function to be used other functions.
int heapify_up(HEAPDATA *hda, int index) {
// your code
	int i = index;
	int pi, val = hda[i].key;
	while (i) {
		pi = (i - 1) >> 1;
		if (hda[pi].key <= val) {
			break;
		} else {
			hda[i] = hda[pi];
			i = pi;
		}
	}
	hda[i].key = val;
	return val;
}

// you may add this function to be used other functions.
int heapify_down(HEAPDATA *hda, int n, int index) {
// your code
	int small = index;
	int l = 2 * index + 1;
	int r = 2 * index + 2;

	if (l < n && hda[l].key < hda[small].key) {
		small = l;
	}
	if (r < n && hda[r].key < hda[small].key) {
		small = r;
	}
	if (small != index) {
		HEAPDATA t = hda[index];
		hda[index] = hda[small];
		hda[small] = t;
		heapify_down(hda, n, small);
	}
}

void heap_insert(HEAP *heap, HEAPDATA new_node) {
// your code
	if (heap->size == heap->capacity) {
		heap->capacity *= 2;
		HEAPDATA *t = realloc(heap->hda, sizeof(HEAPDATA) * heap->capacity);
		if (t) {
			heap->hda = t;
		} else {
			t = malloc(sizeof(HEAPDATA) * heap->capacity);
			if (t) {
				memcpy(t, heap->hda, sizeof(HEAPDATA));
				free(heap->hda);
				heap->hda = t;

			} else {
				printf("Array resize failed\n");
				return;
			}
		}
	}
	heap->hda[heap->size++] = new_node;
	heapify_up(heap->hda, heap->size - 1);
}

HEAPDATA heap_find_min(HEAP *heap) {
// your code
	HEAPDATA min_data = { 0 };
	if (heap->size > 0) {
		min_data = heap->hda[0];
	}
	return min_data;
}

HEAPDATA heap_extract_min(HEAP *heap) {
// your code
	if (heap->size == 0) {
		HEAPDATA empty_min = { 0 };
		return empty_min;
	}
	HEAPDATA min = heap->hda[0];
	heap->hda[0] = heap->hda[heap->size - 1];
	heap->size--;
	if (heap->size <= (heap->capacity / 4)) {
		heap->capacity /= 2;
		HEAPDATA *t = realloc(heap->hda, sizeof(HEAPDATA) * heap->capacity);
		if (t) {
			heap->hda = t;
		} else {
			printf("Array resize failed\n");
			return min;
		}
	}
	heapify_down(heap->hda, heap->size, 0);
	return min;

}

int heap_change_key(HEAP *heap, int index, KEYTYPE new_key) {
// your code
	if (index < 0 || index >= heap->size) {
		return -1;
	}
	heap->hda[index].key = new_key;
	int parent = (index - 1) / 2;
	if (index > 0 && heap->hda[index].key < heap->hda[parent].key) {
		heapify_up(heap->hda, index);
	} else {
		heapify_down(heap->hda, heap->size, index);
	}
	return 0;
}

int heap_search_data(HEAP *heap, VALUETYPE data) {
// your code
	for (int i = 0; i < heap->size; i++) {
		if (heap->hda[i].value == data) {
			return i;
		}
	}
	return -1;
}

void heap_clean(HEAP **heapp) {
	if (heapp) {
		HEAP *heap = *heapp;
		if (heap->capacity > 0) {
			heap->capacity = 0;
			heap->size = 0;
			free(heap->hda);
			free(heap);
		}
		*heapp = NULL;
	}
}
