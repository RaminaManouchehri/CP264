/*
 -------------------------------------
 File:    edgelist.h
 Project: a10
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-04-03
 -------------------------------------
 */

#ifndef EDGELIST_H
#define EDGELIST_H

typedef struct edgenode {
	int from;
	int to;
	int weight;
	struct edgenode *next;
} EDGENODE;

typedef struct edgelist {
	int size;
	EDGENODE *start;
	EDGENODE *end;
} EDGELIST;

EDGELIST* new_edgelist();

void insert_edge_start(EDGELIST *g, int from, int to, int weight);

void insert_edge_end(EDGELIST *g, int from, int to, int weight);

void delete_edge(EDGELIST *g, int from, int to);

int weight_edgelist(EDGELIST *g);

void clean_edgelist(EDGELIST **gp);

void display_edgelist(EDGELIST *g);

#endif
