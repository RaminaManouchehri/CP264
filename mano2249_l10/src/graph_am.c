/**
 * -------------------------------------
 * @file  graph_am.c
 * Adjacency Matrix Graph Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-03-14
 *
 * -------------------------------------
 */
#include "graph_am.h"

// Initializes an adjacency matrix graph.
graph_am* graph_am_initialize(int size) {
	graph_am *source = malloc(sizeof *source);
	source->size = size;
	// Initialize values to zeroes.
	source->values = calloc(size * size, sizeof *source->values);
	return source;
}

void graph_am_free(graph_am **source) {
	// Free up the data array.
	free((*source)->values);
	(*source)->values = NULL;
	free(*source);
	*source = NULL;
	return;
}
void add_edge(graph_am g, int i, int j) {
	*(g.values + i * g.size + j) = 1;
}

void delete_edge(graph_am g, int i, int j) {
	*(g.values + i * g.size + j) = 0;
}

int graph_am_add_vertice(graph_am *source, const graph_am_pair *pair) {

	if (pair->row < 0 && pair->row >= source->size && pair->col < 0
			&& pair->col >= source->size) {
		return 0;
	}

	if (source->values[pair->row * source->size + pair->col] != 0) {
		return 0;
	}
	if (pair->row == pair->col) {
		source->values[pair->row * source->size + pair->col] = 2;
	} else {
		add_edge(*source, pair->row, pair->col);
		add_edge(*source, pair->col, pair->row);
	}
	return 1;
}

int graph_am_remove_vertice(graph_am *source, const graph_am_pair *pair) {

	// your code here
	if (pair->row < 0 || pair->row >= source->size || pair->col < 0
			|| pair->col >= source->size) {
		return 0;
	}

	if (source->values[pair->row * source->size + pair->col] == 0) {
		return 0;
	}

	delete_edge(*source, pair->row, pair->col);
	delete_edge(*source, pair->col, pair->row);

	return 1;
}

graph_am* graph_am_create(int size, const graph_am_pair pairs[], int count) {
	graph_am *source = graph_am_initialize(size);

	// your code here
	if (source) {
		for (int i = 0; i < count; i++) {
			int row = pairs[i].row;
			int col = pairs[i].col;
			if (row >= 0 && row < size && col >= 0 && col < size) {
				if (row == col) { //is it a loop?
					source->values[size * col + row] = 2;
					source->values[size * row + col] = 2;
				} else { //is it an edge?
					source->values[size * col + row] = 1;
					source->values[size * row + col] = 1;
				}

			}
		}
	}

	return source;
}

void graph_am_neighbours(const graph_am *source, int vertex, int vertices[],
		int *count) {

	if (vertex >= 0 && vertex < source->size) {
		for (int column = 0; column < source->size; column++) {
			if (source->values[vertex * source->size + column] != 0) {
				vertices[*count] = column;
				(*count) = (*count) + 1;
			}
		}

	}

	return;
}

int graph_am_degree(const graph_am *source, int vertex) {
	int connected = 0;

	if (vertex >= 0 && vertex < source->size) {
		for (int column = 0; column < source->size; column++) {
			if (source->values[column * source->size + vertex] != 0) {
				connected += source->values[column * source->size + vertex];
			}
		}
	}

	return connected;
}

void graph_am_breadth_traversal(const graph_am *source, int vertex,
		int vertices[], int *count) {

	// your code here
	*count = 0;
	int v[source->size];
	for (int i = 0; i < source->size; i++) {
		v[i] = 0;
	}
	int queue[source->size];
	int front = 0;
	int rear = 0;
	queue[rear++] = vertex;
	v[vertex] = 1;

	while (front != rear) {
		int curr = queue[front++];
		vertices[(*count)++] = curr;
		for (int i = 0; i < source->size; i++) {
			if (source->values[curr * source->size + i] != 0 && !v[i]) {
				v[i] = 1;
				queue[rear++] = i;
			}
		}
	}

	return;
}

void graph_am_depth_traversal(const graph_am *source, int vertex,
		int vertices[], int *count) {

	// your code here
	source->values[vertex * source->size + vertex] = 1;
	vertices[(*count)++] = vertex;

	for (int i = 0; i < source->size; i++) {

		if (source->values[vertex * source->size + i] == 1
				&& source->values[i * source->size + i] == 0) {
			graph_am_depth_traversal(source, i, vertices, count);
		}

	}
}

// Prints the contents of an adjacency matrix graph.
void graph_am_print(const graph_am *source) {
	// Print the column numbers.
	printf("    ");

	for (int i = 0; i < source->size; i++)
		printf("%3d", i);
	printf("\n");
	printf("    ");
	for (int i = 0; i < source->size; i++)
		printf("---");
	printf("\n");

	// Print the row numbers and rows.
	for (int i = 0; i < source->size; i++) {
		printf("%3d|", i);

		for (int j = 0; j < source->size; j++) {
			// find item using offsets
			printf("%3d", *(source->values + i * source->size + j));
		}
		printf("\n");
	}
}
