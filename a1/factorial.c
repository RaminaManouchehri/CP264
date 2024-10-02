/*
 -------------------------------------
 File:    factorial.c
 Project: mano2249_a01
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-01-18
 -------------------------------------
 */
/**
 * Compute the factorial n! and does overflow detection.
 *
 * @param n - a positive integer value
 * @return -  the factorial n! if it is not overflow; otherwise 0.
 */
#include "factorial.h"
#include <ctype.h>
int factorial(int n) {
	int f = 1;
	if (n >= 1) {
		for (int i = 1; i <= n; i++) {
			int temp = f;
			f = f * i;
			if (f > temp && temp != f / i) {
				return 0;
			}
		}
	}
	return f;
}

