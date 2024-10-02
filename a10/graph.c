/*
 -------------------------------------
 File:    graph.c
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
#include <string.h>
#include "queue_stack.h"
#include "graph.h"

GRAPH* new_graph(int order) {
	GRAPH *gp = malloc(sizeof(GRAPH));
	gp->nodes = malloc(order * sizeof(GNODE*));

	int i;
	for (i = 0; i < order; i++) {
		gp->nodes[i] = malloc(sizeof(GNODE));
		gp->nodes[i]->nid = i;
		strcpy(gp->nodes[i]->name, "null");
		gp->nodes[i]->neighbor = NULL;
	}

	gp->order = order;
	gp->size = 0;

	return gp;
}

void insert_edge_graph(GRAPH *g, int from, int to, int weight) {
// your code
	ADJNODE *n = g->nodes[from]->neighbor;
	int found = 0;
	ADJNODE *node = malloc(sizeof(ADJNODE));
	if (n) {
		while (n->next) {
			if (n->nid == to) {
				found = 1;
				break;
			}
			n = n->next;
		}
		if (n->nid == to) {
			found = 1;
		}
		if (found) {
			n->weight = weight;
		} else {
			node->next = NULL;
			node->nid = to;
			node->weight = weight;
			n->next = node;
		}
	} else {
		node->next = NULL;
		node->nid = to;
		node->weight = weight;
		g->nodes[from]->neighbor = node;
	}
	g->size++;
}

void delete_edge_graph(GRAPH *g, int from, int to) {
// your code
	if (g != NULL && g->size != 0) {
		if (from >= 0 && from < g->order && to >= 0 && to < g->order) {
			ADJNODE *current = g->nodes[from]->neighbor;
			ADJNODE *previous = NULL;
			while (current != NULL) {
				if (current->nid == to) {
					if (previous == NULL) {
						g->nodes[from]->neighbor = current->next;
					} else {
						previous->next = current->next;
					}
					free(current);
					g->size--;
					return;
				}
				previous = current;
				current = current->next;
			}
		}
	}
}

int get_edge_weight(GRAPH *g, int from, int to) {
// your code
	ADJNODE *node = g->nodes[from]->neighbor;
	int weight = INFINITY;
	while (node) {
		if (node->nid == to) {
			weight = node->weight;
			break;
		}
		node = node->next;
	}
	return weight;
}

void traverse_bforder(GRAPH *g, int nid) {
// your code
	if (g == NULL)
		return;
	int p = g->order;
	int visited[p];
	int index;
	for (index = 0; index < p; index++) {
		visited[index] = 0;
	}
	//traversal
	QUEUE q = { 0 };
	GNODE *graph_node = NULL;
	ADJNODE *adjnode = NULL;
	enqueue(&q, g->nodes[nid]);
	visited[nid] = 1;
	while (q.front) {
		graph_node = (GNODE*) dequeue(&q);
		printf("(%d %s) ", graph_node->nid, graph_node->name);
		adjnode = graph_node->neighbor;
		while (adjnode) {
			index = adjnode->nid;
			if (visited[index] == 0) {
				enqueue(&q, g->nodes[index]);
				visited[index] = 1;
			}
			adjnode = adjnode->next;
		}
	}
	clean_queue(&q);
}

// Use auxiliary stack data structure for the algorithm
void traverse_dforder(GRAPH *g, int nid) {
	int n = g->order;
	int visited[n], i;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	STACK stack = { 0 };
	GNODE *gnp = NULL;
	ADJNODE *anp = NULL;

	push(&stack, g->nodes[nid]);
	visited[nid] = 1;

	while (stack.top) {
		gnp = pop(&stack);
		printf("(%d %s) ", gnp->nid, gnp->name);
		anp = gnp->neighbor;
		while (anp) {
			int n_id = anp->nid;
			if (visited[n_id] == 0) {
				push(&stack, g->nodes[n_id]);
				visited[n_id] = 1;
			}
			anp = anp->next;
		}
	}

	clean_stack(&stack);
}
void clean_graph(GRAPH **gp) {
	int i;
	GRAPH *g = *gp;
	ADJNODE *temp, *ptr;
	for (i = 0; i < g->order; i++) {
		ptr = g->nodes[i]->neighbor;
		while (ptr != NULL) {
			temp = ptr;
			ptr = ptr->next;
			free(temp);
		}
		free(g->nodes[i]);
	}
	free(g->nodes);
	free(g);
	*gp = NULL;
}

void display_graph(GRAPH *g) {
	if (g) {
		printf("order %d ", g->order);
		printf("size %d ", g->size);
		printf("(from to weight) ");
		int i;
		ADJNODE *ptr;
		for (i = 0; i < g->order; i++) {
			//printf("\n%d:", g->nodes[i]->nid);
			ptr = g->nodes[i]->neighbor;
			while (ptr != NULL) {
				printf("(%d %d %d) ", i, ptr->nid, ptr->weight);
				ptr = ptr->next;
			}
		}
	}
}

