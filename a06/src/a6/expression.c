/*
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

/*
 * Convert infix expression string to postfix expression reprsented by queue data structure.
 * @param infixstr - string of infix expression.
 * @return - postfix expression in queue of QUEUE type.
 */
QUEUE infix_to_postfix(char *infixstr) {
	char *p = infixstr;
	QUEUE queue = { 0 };    // result postfix expression in queue
	STACK stack = { 0 };       //  auxiliary stack
	int sign = 1, num = 0;
	while (*p) {   // expression string traversal
		if (*p == '-' && (p == infixstr || *(p - 1) == '(')) { // get the sign of an operand
			sign = -1;
		} else if (get_type(*p) == 0) { //  namely   *p is digit character,
			num = *p - '0';
			while ((*(p + 1) >= '0' && *(p + 1) <= '9')) {
				num = num * 10 + *(p + 1) - '0';
				p++;
			}
			enqueue(&queue, new_node(sign * num, 0));
			sign = 1;
		} else if (get_type(*p) == 1) {  // namely  *p is an operator character
			push(&stack, new_node(*p, 1));
		} else if (get_type(*p) == 2) {    // *p == '(‘    ????????
			push(&stack, new_node(*p, 2));
		} else if (get_type(*p) == 3) {    //    *p == ‘)‘    ????????
			NODE *n = pop(&stack);
			while (n->type != 2) {
				if (n->type == 1) {
					enqueue(&queue, n);
				}
				n = pop(&stack);
			}
		}    // else ignore
		p++;   //  move to next character
	}  // finally pop each node and insert it to queue
	while (stack.top) {
		enqueue(&queue, pop(&stack));
	}
	return queue;
}

/*
 * Evaluate and return the value postfix expression passed by queue.
 * @parame queue - postfix expression in queue of QUEUE type.
 ^ @return - value of postfix expression
 */
int evaluate_postfix(QUEUE queue) {
	NODE *p = queue.front;
	STACK stack = { 0 }; // auxilliary stack for postfix evaluation
	int type = 0;
	while (p) { // traversal the queue linked list
		type = p->type;
		if (type == 0) { // operant
			push(&stack, new_node(p->data, 0));
		} else if (type == 1) { // operator
			int operator = p->data;
			NODE *oprand2 = pop(&stack);
			if (operator == '+') {
				stack.top->data = stack.top->data + oprand2->data;
			} else if (operator == '-') {
				stack.top->data = stack.top->data - oprand2->data;
			} else if (operator == '*') {
				stack.top->data = stack.top->data * oprand2->data;
			} else if (operator == '/') {
				stack.top->data = stack.top->data / oprand2->data;
			}
			free(oprand2);
		}
		p = p->next;
	}
	int result = stack.top->data;
	clean_stack(&stack);
	return result;
}

/*
 * Evaluate and return the value of infix expression passed by string infixstr,
 * using infix_to_postfix() and evaluate_postfix() functions.
 * @param infixstr - string of infix expression.
 * @return - value of the infix expression.
 */
int evaluate_infix(char *infixstr) {
	QUEUE postfix = infix_to_postfix(infixstr);
	int result = evaluate_postfix(postfix);
	clean_queue(&postfix);
	return result;
}
