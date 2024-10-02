/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-09
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
	// Allocate memory to the data structure
	name_set *set = malloc(sizeof *set);
	// Initialize the header fields.
	set->front = NULL;
	set->rear = NULL;
	return set;
}

int name_set_free(name_set **set) {

	// your code here
	name_set_node *now = (*set)->front;
	name_set_node *next;
	int i = 0;

	while (now != NULL) {
		next = now->next;
		free(now);
		now = next;
		i++;

	}
	free(*set);
	*set = NULL;
	return i;
}

BOOLEAN name_set_append(name_set *set, const char *first_name,
		const char *last_name) {

	// your code here
	if (name_set_contains(set, first_name, last_name)) {
		return FALSE;  // Name already exists
	} else {

		name_set_node *name_appended = (name_set_node*) malloc(
				sizeof(name_set_node));
		strncpy(name_appended->first_name, first_name,
				sizeof(name_appended->first_name) - 1);
		name_appended->first_name[sizeof(name_appended->first_name) - 1] = '\0';
		strncpy(name_appended->last_name, last_name,
				sizeof(name_appended->last_name) - 1);
		name_appended->last_name[sizeof(name_appended->last_name) - 1] = '\0';

		name_appended->next = NULL;

		if (set->front == NULL) {
			set->front = set->rear = name_appended;
		} else {
			set->rear->next = name_appended;
			set->rear = name_appended;
		}
		return TRUE;
	}

}

BOOLEAN name_set_contains(const name_set *set, const char *first_name,
		const char *last_name) {

	// your code here
	const name_set_node *now = set->front;
	while (now != NULL) {
		if ((strcmp(now->first_name, first_name) == 0)
				&& (strcmp(now->last_name, last_name) == 0)) {
			return TRUE;
		}
		now = now->next;
	}

	return FALSE;

}

void name_set_print(const name_set *set) {
	const name_set_node *now = set->front;

	while (now != NULL) {
		printf("%s, %s\n", now->last_name, now->first_name);
		now = now->next;
	}

}
