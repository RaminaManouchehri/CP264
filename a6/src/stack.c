/*
 -------------------------------------
 File:    stack.c
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
#include "stack.h"

void push(STACK *sp, NODE *np) {
// your code
	np->next = sp->top;
	sp->top = np;
	sp->length++;
}

NODE* pop(STACK *sp) {
// your code
	NODE *node = NULL;
	if (sp->top != NULL) {
		node = sp->top;
		if (sp->length == 1) {
			sp->top = NULL;
		} else {
			sp->top = sp->top->next;
		}
		sp->length--;
	}
	return node;
}

void clean_stack(STACK *sp) {
	clean(&(sp->top));
	sp->top = NULL;
	sp->length = 0;
}
