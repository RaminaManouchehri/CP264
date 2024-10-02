/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"
#include <stdbool.h>

int sum_integers(void) {

	// your code here
	int s = 0;
	char input[100];
	bool sp = false;
	printf("Enter integers, one per line:\n");
	while (!sp && fgets(input, sizeof(input), stdin)) {
		int n;
		if (sscanf(input, "%d", &n) == 1) {
			s += n;
		} else {
			sp = true;
		}
	}
	return s;
}
