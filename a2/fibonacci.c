/*
 -------------------------------------
 File:    fibonacci.c
 Project: a2
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-01-27
 -------------------------------------
 */
#include "fibonacci.h"

/**
 *  add your comment
 */
int recursive_fibonacci(int n) {
	// your code
	if (n <= 1) {
		return n;
	} else {
		return recursive_fibonacci(n - 2) + recursive_fibonacci(n - 1);
	}
}
/**
 *  add your comment
 */
int iterative_fibonacci(int n) {
// your code

	if (n <= 1) {
		return n;
	} else {
		int f1 = 0, f2 = 1, temp;
		for (int i = 2; i <= n; i++) {
			temp = f2;
			f2 = f1 + f2;
			f1 = temp;
		}
		return f2;
	}
}

/**
 *  add your comment
 */
int dpbu_fibonacci(int *f, int n) {
// your code
	f[0] = 0, f[1] = 1;
	if (n == 0 || n == 1) {
		return f[n];
	} else {
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 2] + f[i - 1];
		}
		return f[n];
	}

}

/**
 *  add your comment
 */
int dptd_fibonacci(int *f, int n) {
	// your code
	if (n <= 1) {
		f[n] = n;
		return f[n];
	}
	if (f[n] > 0) {
		return f[n];
	} else {
		f[n] = dptd_fibonacci(f, n - 2) + dptd_fibonacci(f, n - 1);
		return f[n];
	}
}
