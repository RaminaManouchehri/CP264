/*
 -------------------------------------
 File:    myrecord.c
 Project: a4
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-10
 -------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

GRADE grade(float score) {
	GRADE r = { "F" };
// your code
	if (score >= 90) {
		strcpy(r.letter_grade, "A+");
	} else if (score >= 85 && score < 90) {
		strcpy(r.letter_grade, "A");
	} else if (score >= 80 && score < 85) {
		strcpy(r.letter_grade, "A-");
	} else if (score >= 77 && score < 80) {
		strcpy(r.letter_grade, "B+");
	} else if (score >= 73 && score < 77) {
		strcpy(r.letter_grade, "B");
	} else if (score >= 70 && score < 73) {
		strcpy(r.letter_grade, "B-");
	} else if (score >= 67 && score < 70) {
		strcpy(r.letter_grade, "C+");
	} else if (score >= 63 && score < 67) {
		strcpy(r.letter_grade, "C");
	} else if (score >= 60 && score < 63) {
		strcpy(r.letter_grade, "C-");
	} else if (score >= 57 && score < 60) {
		strcpy(r.letter_grade, "D+");
	} else if (score >= 53 && score < 57) {
		strcpy(r.letter_grade, "D");
	} else if (score >= 50 && score < 53) {
		strcpy(r.letter_grade, "D-");
	}
	return r;
}

STATS process_data(RECORD *dataset, int count) {
// your code
	STATS stats = { 0 };
	int n = count;
	float mean = 0;
	float median = 0;
	float std = 0;
	for (int i = 0; i < count; i++) {
		mean += dataset[i].score;

	}
	mean /= count;
	for (int i = 0; i < count; i++) {
		std += (dataset[i].score - mean) * (dataset[i].score - mean);
	}
	std = sqrt(std / count);
	if (n < 0) {
		median = dataset[n / 2].score;
	} else {
		median = (dataset[n / 2 - 1].score + dataset[n / 2].score) / 2;
	}
	stats.count = n;
	stats.mean = mean;
	stats.stddev = std;
	stats.median = median;
	return stats;
}

int import_data(FILE *fp, RECORD *dataset) {
// your code
	char delimiters[] = ",\n\r";
	char line[100];
	int i = 0;
	char *token = NULL;
	while (fgets(line, sizeof(line), fp) != NULL) {
		sscanf(line, "%[^, ],%f", dataset[i].name, &dataset[i].score);
		token = (char*) strtok(line, delimiters);
		strcpy(dataset[i].name, token);
		token = (char*) strtok(NULL, delimiters);
		sscanf(token, "%f", &dataset[i].score);
		i++;
	}
	return i;
}
int report_data(FILE *fp, RECORD *dataset, int count) {
// your code
	for (int i = 0; i < count; i++) {
		char line[100];
		snprintf(line, sizeof(line), "%s,%.1f,%s\n", dataset[i].name,
				dataset[i].score, grade(dataset[i].score).letter_grade);
		fputs(line, fp);

	}
	return 1;

}
