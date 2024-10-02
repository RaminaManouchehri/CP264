/*
 -------------------------------------
 File:    bigint.c
 Project: a05
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
	BIGINT bn = { 0 };
	if (p == NULL)
		return bn;
	else if (!(*p >= '0' && *p <= '9')) { // not begin with digits
		return bn;
	} else if (*p == '0' && *(p + 1) == '\0') { // just "0"
		dll_insert_end(&bn, new_node(*p - '0'));
		return bn;
	} else {
		while (*p) {
			if (*p >= '0' && *p <= '9') {
				dll_insert_end(&bn, new_node(*p - '0'));
			} else {
				dll_clean(&bn);
				break;
			}
			p++;
		}
		return bn;
	}
}
/*
 * Add two BIGINT operants and returns the sum in BIGINT type.
 * @param oprand1  - first operand of BIGINT type.
 * @param oprand2  - second operand of BIGINT type.
 * @return - the sum of oprand1 and oprand2 in BIGINT type.
 */

BIGINT bigint_add(BIGINT op1, BIGINT op2) {
// your code
	BIGINT sum = bigint(NULL);
	NODE *p1 = op1.end;
	NODE *p2 = op2.end;
	int c = 0, a, b, s;
	while (p1 || p2) {
		a = 0;
		b = 0;
		if (p1) {
			a = p1->data;
			p1 = p1->prev;
		}
		if (p2) {
			b = p2->data;
			p2 = p2->prev;
		}
		s = a + b + c;
		if (s >= 10) {
			dll_insert_start(&sum, new_node(s - 10));
			c = 1;
		} else {
			dll_insert_start(&sum, new_node(s));
			c = 0;
		}
	}
	if (c == 1) {
		dll_insert_start(&sum, new_node(c));
		return sum;
	}
}
/*
 * Compute and return Fibonacci(n)
 * @param n - input positive integer
 * @return  - Fibonacci(n) in BIGINT type
 */

BIGINT bigint_fibonacci(int n) {
// your code
	if (n <= 2) {
		return bigint("1");
	} else {
		BIGINT temp = bigint(NULL);
		BIGINT f1 = bigint("1");
		BIGINT f2 = bigint("1");
		int i = 1;

		while (i < n) {
			temp = f2;
			f2 = bigint_add(f1, f2);
			f1 = temp;
			i++;
		}

		return f1;
	}
}
