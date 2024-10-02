/*
 -------------------------------------
 File:    mychar.c
 Project: mano2249_a01
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-01-17
 -------------------------------------
 */
#include "mychar.h"
#include <ctype.h>

/**
 *  add your comment
 */
int mytype(char c) {
	if (isdigit(c)) {
		return 0;
	} else if (c == '+' || c == '-' || c == '*' || c == '/') {
		return 1;
	} else if (isalpha(c)) {
		return 2;
	} else {
		return -1;
	}
}

/**
 *  add your comment
 */
char case_flip(char c) {
	// your code
	if (c >= 'a' && c <= 'z') {
		return toupper(c); //change to uppercase
	} else if (c >= 'A' && c <= 'Z') {
		return tolower(c); //else change to lowercase
	} else {
		return c;
	}
}

/**
 *  add your comment
 */
int char_to_int(char c) {
	// your code
	if ((c >= '0') && (c <= '9')) {
		return c - '0';
	} else {
		return -1;
	}
}
