/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2024-02-22
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked* queue_initialize() {

	// your code here
	queue_linked *source = malloc(sizeof *source);
	source->front = NULL;
	source->rear = NULL;
	return source;
}

void queue_free(queue_linked **source) {

	// Free the linked data
	while ((*source)->front != NULL) {
		queue_node *temp = (*source)->front;
		// use the data_free function to free the actual data
		data_free(&temp->item);
		// update the stack top
		(*source)->front = (*source)->front->next;
		// free the stack node
		free(temp);
		temp = NULL;
	}
	//free the queue header
	free(*source);
	*source = NULL;
	return;
}

BOOLEAN queue_empty(const queue_linked *source) {

	// your code here
	if (source->front == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}

}

int queue_count(const queue_linked *source) {

	// your code here
	int count = 0;
	queue_node *current = source->front;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

void queue_insert(queue_linked *source, data_ptr item) {

	// allocate memory to a new stack node
	queue_node *node = (queue_node*) malloc(sizeof(queue_node));

	// allocate memory for the data
	node->item = malloc(sizeof(*item));
	data_copy(node->item, item);
	node->next = NULL;
	if (source->front == NULL) {
		// update the stack top
		source->front = node;
	} else {
		source->rear->next = node;
	}
	source->rear = node;
	source->count++;

}

BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {

	// your code here
	if (queue_empty(source) == FALSE) {
		// return a copy of the data in the node
		data_copy(item, source->front->item);
		return TRUE;
	} else {
		return FALSE;
	}
}

BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {

	// your code here
	if (queue_empty(source) == FALSE) {
		// return a copy of the data in the node
		*item = source->front->item;
		if (source->front == source->rear) {
			free(source->front);
			source->front = source->rear = NULL;
		} else {
			queue_node *temp = source->front;
			source->front = source->front->next;
			free(temp);
		}
		source->count--;
		return TRUE;
	} else {
		return FALSE;
	}
}

void queue_print(const queue_linked *source) {
	char string[DATA_STRING_SIZE];
	queue_node *current = source->front;

	while (current != NULL) {
		printf("%s\n", data_string(string, sizeof string, current->item));
		current = current->next;
	}
	return;
}
