/*
 -------------------------------------
 File:    polynomial.c
 Project: a2
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-01-27
 -------------------------------------
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // use stdlib.h header file to use abs() function.
#include "polynomial.h"

#define EPSILON 1e-6

/**
 *  add your comment
 */
float horner(float *p, int n, float x) {
// your code
	float r = 0;
	for (int i = 0; i < n; i++) {
		r = r * x + p[i];
	}
	if (r < 5 * EPSILON && r > 5 * -r) {
		r = 0.00;
	}
	return r;
}

/**
 *  add your comment
 */
float bisection(float *p, int n, float a, float b) {
// your code
	float tol = 1e-6;
	float c = (a + b) / 2;
	;

	while (fabs(horner(p, n, c)) >= tol && fabs(a - b) >= tol) {
		if (horner(p, n, c) * horner(p, n, a) > 0) {
			a = c;
		} else {
			b = c;
		}
		c = (a + b) / 2;

	}

	return c;
}

