/*
 -------------------------------------
 File:    queue.c
 Project: a6
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-02
 -------------------------------------
 */

#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
/*
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue
 * @param NODE *np - pointer to the node.
 */
void enqueue(QUEUE *qp, NODE *np) {
	if (qp->length != 0) {
		qp->rear->next = np;
		qp->rear = np;
	} else {
		qp->front = np;
		qp->rear = np;
	}
	qp->length++;
}

/*
 * Dequeue and return the pointer of the removed node.
 * @param *qp - pointer to the queue
 * @return - the reference of the removed node, and set it's next to NULL
 */
NODE* dequeue(QUEUE *qp) {
	if (qp->front == NULL) {
		return NULL;
	}
	NODE *node = qp->front;
	if (qp->length == 1) {
		qp->front = NULL;
		qp->rear = NULL;
	} else {
		qp->front = qp->front->next;
		node->next = NULL;
	}
	qp->length--;
	return node;
}

/*
 * Clean the linked list queue
 */
void clean_queue(QUEUE *qp) {
	clean(&(qp->front));
	qp->front = NULL;
	qp->rear = NULL;
	qp->length = 0;
}
