/*
 -------------------------------------
 File:    myrecord.h
 Project: a4
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-10
 -------------------------------------
 */

#ifndef MYRECORD_H
#define MYRECORD_H

typedef struct {
	char name[20];
	float score;
} RECORD;

typedef struct {
	int count;
	float mean;
	float stddev;
	float median;
} STATS;

typedef struct {
	char letter_grade[3];
} GRADE;

GRADE grade(float score);

int import_data(FILE *fp, RECORD *dataset);

STATS process_data(RECORD *dataset, int count);

int report_data(FILE *fp, RECORD *dataset, int count);

#endif
