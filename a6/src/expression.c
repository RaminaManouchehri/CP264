/*{}
 -------------------------------------
 File:    expression.c
 Project: a6
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-02
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"
#include <ctype.h>

QUEUE infix_to_postfix(char *infixstr) {
// your code
	char *p = infixstr;
	STACK s = { 0 };
	QUEUE pe = { 0 };
	int sign = 1, num = 0;
	while (*p) {
		//check if negative
		if (*p == '-' && (*p == infixstr || *(p - 1) == '(')) {
			sign = -1;
		} else if (get_type(*p) == 0) {
			while (isdigit(*(p + 1))) { //horners algorithm
				//num * 10 multiplies to make room for next char
				//*(p + 1) - '0' makes next char into digit
				num = num * 10 + *(p + 1) - '0'; // loops until non digit is reached
				p++; //move pointer to next char
			}
			//add num to queue
			//0 is the type;
			enqueue(&pe, new_node(sign * num, 0));			//
			sign = -1;

		} else if (get_type(*p) == 1) { //is an operator
			if (s.length == 0) {
				push(&s, new_node(*p, 1));
			} else {
				if (get_priority((s.top)->data) != 2) { //is not a (
					if (get_priority(*p) >= (get_priority((s.top)->data))) {
						push(&s, new_node(*p, 1));
					} else {
						enqueue(&pe, pop(&s));
						push(&s, new_node(*p, 1));
					}
				} else {
					push(&s, new_node(*p, 1));
				}
			}
		} else if ((get_type(*p) == 2)) { //opening bracket
			push(&s, new_node(*p, 2));
		} else if ((get_type(*p) == 3)) {
			NODE *n = pop(&s);
			while (get_type(n->data) != 2) { //while not (
				enqueue(&pe, n);
				if (n->type == 1) {
					enqueue(&pe, n);
				}
				n = pop(&s);
			}
		}
		p++;
	}
	// finally pop each node and insert it to queue
	while (s.top) {
		enqueue(&pe, pop(&s));
	}
	return pe;

}

int evaluate_postfix(QUEUE queue) {
// your code
}

int evaluate_infix(char *infixstr) {
// your code
}
