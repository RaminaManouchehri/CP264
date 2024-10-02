/*
 -------------------------------------
 File:    mystring.c
 Project: a3
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-03
 -------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a str
 * @return - return the number of words.
 */
int str_words(char *s) {
	int len = strlen(s);
	int count = 0;
	int wrd = 0; //checks if char is part of a word and not a delimiter
	char notword[] = " .,;\n\t"; //possible things between each word
	for (int i = 0; i < len; i++) { //parses through string charachter by charachter;
		if (strchr(notword, *(s + i)) != NULL) { // Check if the character is a delimiter
			wrd = 0; //end of word
		} else if (isalpha(*(s + i)) != 0) { // Check if the character is an alphabet
			if (wrd == 0) {
				count++;
				wrd = 1;  //reset new word
			}
		}
	}
	return count;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a str
 * @return - return the number of actual flips.
 */
int str_lower(char *s) {
	int len = strlen(s);
	int flips = 0;
	for (int i = 0; i < len; i++) {
		if (isalpha(*(s + i)) != 0) {
			if (isupper(*(s + i)) != 0) {
				*(s + i) = tolower(*(s + i));
				flips++;
			}
		}
	}
	return flips;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a str
 */
void str_trim(char *s) {
	char *p = s, *dp = s;
	while (*p) {
		if (*p != ' ' || (p > s && *(p - 1) != ' ')) {
			*dp = *p;
			dp++;
		}
		p++;
	}
	if (*(p - 1) != (' ')) {
		*dp = '\0';
	} else {
		*(dp - 1) = '\0';
	}
}

