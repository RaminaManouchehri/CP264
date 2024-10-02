/*
 -------------------------------------
 File:    edgelist.c
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
#include "edgelist.h"
#include <stdbool.h>

EDGELIST* new_edgelist() {
	EDGELIST *tp = malloc(sizeof(EDGELIST));
	tp->size = 0;
	tp->start = NULL;
	tp->end = NULL;
	return tp;
}

void insert_edge_end(EDGELIST *g, int from, int to, int weight) {
// your code
	EDGENODE *new = (EDGENODE*) malloc(sizeof(EDGENODE));
	new->from = from;
	new->to = to;
	new->weight = weight;
	new->next = NULL;

	if (g->start == NULL) {
		g->start = new;
	} else
		g->end->next = new;
	g->end = new;
	g->size++;

}

void insert_edge_start(EDGELIST *g, int from, int to, int weight) {
// your code;mmm
	EDGENODE *new = malloc(sizeof(EDGENODE));
	new->from = from;
	new->to = to;
	new->weight = weight;
	new->next = g->start;
	if (!g->start) {
		g->end = new;
	}
	g->size++;
	g->start = new;
}

void delete_edge(EDGELIST *g, int from, int to) {
// your code
	bool deleted = false;
	EDGENODE *prev = NULL;
	EDGENODE *curr = g->start;
	while (curr || deleted == false) {
		if (curr->from == from && curr->to == to) {
			if (prev == NULL) {
				g->start = curr->next;
			} else {
				prev->next = curr->next;
			}
			if (curr == g->end) {
				g->end = prev;
			}
			free(curr);
			g->size--;
			deleted = true;
		}
		prev = curr;
		curr = curr->next;
	}
	return;
}

int weight_edgelist(EDGELIST *g) {
// your code
	int weight = 0;
	EDGENODE *node = g->start;
	while (node) {
		weight += node->weight;
		node = node->next;
	}
	return weight;
}

void clean_edgelist(EDGELIST **gp) {
	EDGELIST *g = *gp;
	EDGENODE *temp, *p = g->start;
	while (p) {
		temp = p;
		p = p->next;
		free(temp);
	}
	free(g);
	*gp = NULL;
}

void display_edgelist(EDGELIST *g) {
	if (g == NULL)
		return;
	printf("size %d ", g->size);
	printf("(from to weight) ");
	EDGENODE *p = g->start;
	while (p) {
		printf("(%d %d %d) ", p->from, p->to, p->weight);
		p = p->next;
	}
}
