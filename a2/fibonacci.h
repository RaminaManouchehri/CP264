/*
 -------------------------------------
 File:    fibonacci.h
 Project: a2
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-01-27
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIBONACCI_H
#define FIBONACCI_H

int iterative_fibonacci(int n);

int recursive_fibonacci(int n);

int dpbu_fibonacci(int *f, int n);

int dptd_fibonacci(int *f, int n);

#endif
