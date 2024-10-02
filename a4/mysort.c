/*
 -------------------------------------
 File:    mysort.c
 Project: a4
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-02-10
 -------------------------------------
 */

#include "mysort.h"
void swap(float **x, float **y) {
	float *temp = *y;
	*y = *x;
	*x = temp;
}

void select_sort_inc(float *a[], int left, int right) {
// your code
	int indexmin;
	for (int i = left; i < right; i++) {
		indexmin = i;
		for (int j = i + 1; j <= right; j++) {
			if (*a[j] < *a[indexmin]
					|| ((*a[j]) == *a[indexmin] && a[j] < a[indexmin])) {
				indexmin = j;
			}
		}
		swap(&a[indexmin], &a[i]);
	}

}

void quick_sort_inc(float *a[], int left, int right) {
// your code
	int i, j;
	float key;
	if (left < right) {
		key = *a[left];
		i = left + 1;
		j = right;
		while (i <= j) {
			while (i <= right && *a[i] <= key)
				i++;
			while (j >= left && *a[j] > key)
				j--;
			if (i < j) {
				float *temporary = a[i];
				a[i] = a[j];
				a[j] = temporary;
			}
		}
		float *temporary = a[left];
		a[left] = a[j];
		a[j] = temporary;
		quick_sort_inc(a, left, j - 1);
		quick_sort_inc(a, j + 1, right);
	}
}

