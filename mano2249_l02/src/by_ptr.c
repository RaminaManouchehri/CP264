/**
 * -------------------------------------
 * @file  by_ptr.c
 * Lab 2 Pointer Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-06
 *
 * -------------------------------------
 */
#include "by_ptr.h"
#include <math.h>
void fill_values_by_ptr(int *values, int size) {

	for (int i = 0; i < size; i++) {
		*(values + i) = i + 1;
	}
}

void fill_squares_by_ptr(int *values, long int *squares, int size) {

	// your code here
	for (int i = 0; i < size; i++) {
		*(squares + i) = pow(*(values + i), 2);
	}

}

void print_by_ptr(int *values, long int *squares, int size) {

	// your code here
	printf("Value  Square\n");
	printf("-----  ----------\n");
	for (int i = 0; i < size; i++) {
		printf("%5i", *(values + i));
		printf("%12ld", *(squares + i));
		printf("\n");
	}

}
