/*
 -------------------------------------
 File:    algorithm.h
 Project: a10
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-04-03
 -------------------------------------
 */

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "edgelist.h"
#include "graph.h"

EDGELIST* mst_prim(GRAPH *g, int start);
EDGELIST* spt_dijkstra(GRAPH *g, int start);
EDGELIST* sp_dijkstra(GRAPH *g, int start, int end);

#endif
