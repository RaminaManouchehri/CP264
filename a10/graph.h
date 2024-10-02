/*
 -------------------------------------
 File:    graph.h
 Project: a10
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-04-03
 -------------------------------------
 */
#ifndef GRAPH_H
#define GRAPH_H

#define INFINITY 99999

typedef struct adjnode {
	int nid;
	int weight;
	struct adjnode *next;
} ADJNODE;

typedef struct gnode {
	int nid;
	char name[10];
	ADJNODE *neighbor;
} GNODE;

typedef struct graph {
	int order;
	int size;
	GNODE **nodes;
} GRAPH;

GRAPH* new_graph(int n);

void insert_edge_graph(GRAPH *g, int from, int to, int weight);

void delete_edge_graph(GRAPH *g, int from, int to);

int get_edge_weight(GRAPH *g, int from, int to);

void traverse_bforder(GRAPH *g, int start);

void traverse_dforder(GRAPH *g, int start);

void display_graph(GRAPH *g);

void clean_graph(GRAPH **gp);

#endif
