/*
 -------------------------------------
 File:    stack.h
 Project: a6
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-03-02
 -------------------------------------
 */

#ifndef STACK_H
#define STACK_H
#include "common.h"
/*
 * Define a structure STACK containing the length and pointer of the top node.
 * int length - maintains the length of stack.
 * NODE *top - pointer to the top node of linked list stack
 */
typedef struct stack {
	int length;
	NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE* pop(STACK *sp);
void clean_stack(STACK *sp);

#endif
