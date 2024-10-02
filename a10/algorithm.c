/*
 -------------------------------------
 File:    algorithm.c
 Project: a10
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-04-03
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "algorithm.h"
#include "edgelist.h"

EDGELIST* mst_prim(GRAPH *g, int start) {
// your code
	if (g == NULL)
		return NULL;
	int i;
	int heapindex;
	int n = g->order;
	int T[n];
	int parent[n];
	for (i = 0; i < n; i++)
		T[i] = 0;
	for (i = 0; i < n; i++)
		parent[i] = -1;
	HEAPDATA hda;
	HEAP *h = new_heap(4);
	T[start] = 1;
	ADJNODE *temporary = g->nodes[start]->neighbor;
	while (temporary) {
		hda.key = temporary->weight;
		hda.value = temporary->nid;
		heap_insert(h, hda);
		parent[temporary->nid] = start;
		temporary = temporary->next;
	}
	EDGELIST *mst = new_edgelist();
	while (h->size > 0) {
		hda = heap_extract_min(h);
		i = hda.value;
		T[i] = 1;
		insert_edge_end(mst, parent[i], i, hda.key);
		temporary = g->nodes[i]->neighbor;
		while (temporary) {
			heapindex = heap_search_data(h, temporary->nid);
			if (heapindex >= 0) {
				if (T[temporary->nid] == 0
						&& temporary->weight < h->hda[heapindex].key) {
					heap_change_key(h, heapindex, temporary->weight);
					T[temporary->nid] = i;
				}
			} else {
				if (T[temporary->nid] == 0) {
					hda.key = temporary->weight;
					hda.value = temporary->nid;
					heap_insert(h, hda);
					parent[temporary->nid] = i;
				}
			}
			temporary = temporary->next;
		}
	}
	return mst;
}

EDGELIST* spt_dijkstra(GRAPH *g, int start) {
// your code
	if (!g)
		return NULL;
	EDGELIST *spt = new_edgelist();
	int i;
	int u;
	int n = g->order;
	int T[n];
	int parent[n];
	int l[n];
	HEAPDATA hda;
	for (i = 0; i < n; i++) {
		T[i] = 0;
		parent[i] = -1;
		l[i] = 9999;
	}
	HEAP *h = new_heap(4);
	l[start] = 0;
	T[start] = 1;
	u = start;
	while ((g->order - 1) - spt->size != 0) {
		ADJNODE *v = g->nodes[u]->neighbor;
		while (v) {
			if (l[u] + v->weight < l[v->nid]) {
				l[v->nid] = l[u] + v->weight;
				parent[v->nid] = u;
				hda.key = v->weight + l[u];
				hda.value = v->nid;
				heap_insert(h, hda);
			}
			v = v->next;
		}
		if (h->size != 0) {
			hda = heap_extract_min(h);
			u = hda.value;
			T[u] = 1;
			l[u] = hda.key;
			insert_edge_end(spt, parent[u], u, l[u] - l[parent[u]]);
		}
	}
	heap_clean(&h);
	return spt;
}

EDGELIST* sp_dijkstra(GRAPH *g, int start, int end) {
// your code
	if (g == NULL)
		return NULL;
	EDGELIST *spt = new_edgelist();
	int i, heapindex, n = g->order;
	int T[n], parent[n], label[n];
	int found = 0;
	HEAPDATA hn;
	for (i = 0; i < n; i++) {
		T[i] = 0;
		label[i] = INFINITY;
	}
	HEAP *h = new_heap(4);
	ADJNODE *temporary = g->nodes[start]->neighbor;

	label[start] = 0;
	T[start] = 1;
	while (temporary) {
		hn.key = temporary->weight + label[start];
		hn.value = temporary->nid;
		heap_insert(h, hn);
		parent[temporary->nid] = start;
		temporary = temporary->next;
	}
	while (h->size > 0 && found == 0) {
		hn = heap_extract_min(h);
		i = hn.value;
		if (hn.key == end) {
			found = 1;
		}
		T[i] = 1;
		label[i] = hn.key;
		insert_edge_end(spt, parent[i], i, label[i] - label[parent[i]]);
		temporary = g->nodes[i]->neighbor;
		while (temporary) {
			heapindex = heap_search_data(h, temporary->nid);
			if (heapindex >= 0) {
				if (T[temporary->nid] == 0
						&& temporary->weight + label[i]
								< h->hda[heapindex].key) {
					heap_change_key(h, heapindex, temporary->weight + label[i]);
					parent[temporary->nid] = i;
				}
			} else {
				if (T[temporary->nid] == 0) {
					hn.key = temporary->weight + label[i];
					hn.value = temporary->nid;
					heap_insert(h, hn);
					parent[temporary->nid] = i;
				}
			}
			temporary = temporary->next;
		}
	}
	EDGELIST *sp = new_edgelist();
	i = end;
	while (1) {
		if (i == start)
			break;
		insert_edge_start(sp, parent[i], i, label[i] - label[parent[i]]);
		i = parent[i];
	}
	return sp;
}
