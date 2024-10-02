/*
 -------------------------------------
 File:    myword.c
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
#include "myword.h"
#include <string.h>
#include "mystring.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

// You can copy here the functions in mysttring.c if you want to use them in the
// following functions. You can also add other auxiliary functions here.
/*
 * Load word data from file, and insert words a directory represented by char array.
 *
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored.
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.
 */

int create_dictionary(FILE *fp, char *dictionary) {
// your code
	char line[1000];
	char delimiters[] = " .,\n\t\r";
	char *token;
	int count = 0;
	while (fgets(line, 1000, fp) != NULL) {
		count++;
		str_lower(line);
		token = (char*) strtok(line, delimiters);
		while (token != NULL) {
			strcat(dictionary, token);
			strcat(dictionary, ",");
			count++;
			token = (char*) strtok(NULL, delimiters);
		}
	}
	return count;
}

/**
 *  add your comment
 */
BOOLEAN contain_word(char *dictionary, char *word) {
// your code
	if (word == NULL || *word == '\0') {
		return 0;
	} else {
		char temp[20] = { 0 };
		strcat(temp, ",");
		strcat(temp, word);
		strcat(temp, ",");
		char *result = strstr(dictionary, temp);
		// If strstr returns non-NULL, the word is found
		if (result != NULL) {
			return TRUE;
		} else {
			return FALSE;
		}
	}
}

/**
 *  add your comment
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
	WORDSTATS ws = { 0 };
	char line[MAX_LINE_LEN];
	char delimiters[] = " .,\n\t\r";
	char *word_token;

	while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
		ws.line_count++;
		str_lower(line);

		word_token = strtok(line, delimiters);
		while (word_token != NULL) {
			if (contain_word(dictionary, word_token) == FALSE) {
				int j = 0;
				while (j < ws.keyword_count
						&& strcmp(word_token, words[j].word) != 0) {
					j++;
				}
				if (j < ws.keyword_count) {
					words[j].count++;
				} else {
					strcpy(words[j].word, word_token);
					words[j].count = 1;
					ws.keyword_count++;
				}
			}

			word_token = (char*) strtok(NULL, delimiters);
		}
	}

	return ws;
}
