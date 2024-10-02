/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-06
 *
 * -------------------------------------
 */
#include "by_index.h"
#include <math.h>

void fill_values_by_index(int values[], int size) {

	for (int i = 0; i < size; i++) {
		values[i] = i + 1;
	}
}

void fill_squares_by_index(int values[], long int squares[], int size) {

	// your code here
	for (int j = 0; j < size; j++) {
		squares[j] = pow(values[j], 2);
	}

}

void print_by_index(int values[], long int squares[], int size) {

	// your code here
	printf("Value  Square\n");
	printf("-----  ----------\n");
	for (int k = 0; k < size; k++) {
		printf("%5i", values[k]);
		printf("%12ld", squares[k]);
		printf("\n");

	}

}
