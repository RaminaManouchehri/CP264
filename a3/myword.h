/*
 -------------------------------------
 File:    myword.h
 Project: a3
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-03
 -------------------------------------
 */

#ifndef MYWORD_H
#define MYWORD_H

#include <stdio.h>

typedef enum boolean {
// your code
	FALSE = 0,
	TRUE = 1
} BOOLEAN;

typedef struct word {
//your code
	char word[20];
	int count;
} WORD;

typedef struct wordstats {
// your code
	int line_count;
	int word_count;
	int keyword_count;
} WORDSTATS;

int create_dictionary(FILE *fp, char *dictionary);

BOOLEAN contain_word(char *dictionary, char *word);

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif

