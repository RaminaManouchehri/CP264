/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {

	// your code here
	printf("Enter %d values for an array of int.\n", size);
	for (int i = 0; i < size; i++) {
		int n;
		char input[100];
		printf("Value for index %d: ", i);
		fgets(input, sizeof(input), stdin);
		if (sscanf(input, "%d", &n) == 1) {
			array[i] = n;
		} else {
			printf("Not a valid integer\n");
			i--;
		}
	}

}
