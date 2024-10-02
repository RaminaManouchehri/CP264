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

void enqueue(QUEUE *qp, NODE *np) {
// your code
	if (qp->front == NULL) {
		qp->front = np;
		qp->rear = np;
		qp->length++;
	} else {
		qp->rear->next = np;
		qp->rear = np;
		qp->length++;
	}
}

NODE* dequeue(QUEUE *qp) {
// your code
	NODE *removed = NULL;
	if (qp->length != 0) {
		removed = qp->front;
		if (qp->length == 1) {
			//free(qp->front);
			qp->front = NULL;
			qp->rear = NULL;
			qp->length--;
		} else {
			qp->front = qp->front->next;
			//free(ptr);
			qp->length--;
		}
	}
	return removed;
}

void clean_queue(QUEUE *qp) {
	clean(&(qp->front));
	qp->front = NULL;
	qp->rear = NULL;
	qp->length = 0;
}
