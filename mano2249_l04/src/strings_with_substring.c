/*
 -------------------------------------
 File:    strings_with_substring.c
 Project: mano2249_l04
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-07
 -------------------------------------
 */
#include "functions.h"
/**
 * Traverses every string in strings and prints the strings that contain substr. Case must match.
 *
 * @param data - the strings_array struct to traverse
 * @param substr - the substring to look for in each string
 */

void strings_with_substring(strings_array *data, char *substr) {

	// your code here
	for (int i = 0; i < data->capacity; i++) {
		if ((strstr(data->strings[i], substr) != NULL)) {
			printf("%s\n", data->strings[i]);
		}
	}
}
