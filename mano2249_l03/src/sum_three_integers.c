/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2023-09-09
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {

	// your code here
	int n1;
	int n2;
	int n3;
	char input[100];
	while (1) {
		printf("Enter three comma-separated integers: ");
		fgets(input, sizeof(input), stdin);
		if (sscanf(input, "%d,%d,%d", &n1, &n2, &n3) == 3) {
			return n1 + n2 + n3;
		} else {
			printf("The integers were not properly entered.");
		}
	}

}
