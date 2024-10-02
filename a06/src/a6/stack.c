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

/*
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack
 * @param NODE *np - pointer to the node.
 */
void push(STACK *sp, NODE *np) {
	np->next = sp->top;
	sp->top = np;
	sp->length++;

}

/*
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL
 */
NODE* pop(STACK *sp) {
	if (sp->length != 0) {
		NODE *node = sp->top;
		sp->top = sp->top->next;
		node->next = NULL;
		sp->length--;
		return node;
	} else {
		return NULL;
	}
}

/*
 * clean the linked list stack
 */

void clean_stack(STACK *sp) {
	clean(&(sp->top));
	sp->top = NULL;
	sp->length = 0;
}
