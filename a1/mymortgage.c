/*
 -------------------------------------
 File:    mymortgage.c
 Project: mano2249_a01
 file description
 -------------------------------------
 Author:  Ramina Manouchehri
 ID:      169042249
 Email:   mano2249@mylaurier.ca
 Version  2024-01-18
 -------------------------------------
 */
#include <math.h>
#include "mymortgage.h"
#include <ctype.h>

/**
 * Compute the monthly payment of given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - monthly payment, float type.
 */
float monthly_payment(float principal_amount, float annual_interest_rate,
		int years) {
	float monthly_rate = (annual_interest_rate / 100) / 12;
	float n = years * 12;
	float payment = principal_amount * (monthly_rate * pow(1 + monthly_rate, n))
			/ (pow(1 + monthly_rate, n) - 1);
	return payment;
}

/**
 * Determine the total payment of loan given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total payment of the loan, float type.
 */
float total_payment(float principal_amount, float annual_interest_rate,
		int years) {
	float monthly_rate = (annual_interest_rate / 100) / 12;
	int payments_total = years * 12;
	float total_payment = monthly_payment(principal_amount,
			annual_interest_rate, years) * payments_total;
	return total_payment;
}

/**
 * Determine the total interested payed for the loan given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total interest payed by the end of paying off the loan, float type.
 */
float total_interest(float principal_amount, float annual_interest_rate,
		int year) {
	float total_interest = total_payment(principal_amount, annual_interest_rate,
			year) - principal_amount;
	return total_interest;
}

