/*
 -------------------------------------
 File:    queue.h
 Project: a6
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-02
 -------------------------------------
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"
/*
 * Define a structure QUEUE containing length and pointers of front and rare node.
 * int length - maintains the length of queue,
 * NODE *front - pointer to the front node of linked list queue
 * NODE *rear - points to the rare node of linked list queue
 */
typedef struct queue {
	int length;
	NODE *front;
	NODE *rear;
} QUEUE;

void enqueue(QUEUE *qp, NODE *np);
NODE* dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif
