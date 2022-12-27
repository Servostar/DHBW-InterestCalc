#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief fill tab with interest calculations. Each row will contain data for the next year.
 * the columns will contain [0] := interest rate [1] := investment amount [2] := investment growth 
 * 
 * @param tab 3 column table
 * @param duration number of years to calculate for
 * @param investmentAmount start money
 * @return double sum off total investments
 */
double calculate_interest_growth(double tab[][3], int duration, double investmentAmount);

/**
 * @brief print the table tab as layouted for calculate_interest_growth() to stdout
 * 
 * @param tab 
 * @param duration number of rows 
 * @param columns number of columns
 */
void output_table(double tab[][3], unsigned int duration, unsigned int columns);

/**
 * @brief find the maximum value in arr
 * 
 * @param arr 
 * @param len 
 * @return unsigned int index of the maximum value in arr 
 */
unsigned int find_index(double arr[], unsigned int len);

#endif