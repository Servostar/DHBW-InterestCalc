#include "calculator.h"

/**
 * @brief 
 * 
 * @param interestRate 
 * @param growthRate 
 * @return true 
 * @return false 
 */
bool input_rate_and_growth(double *interestRate, double *growthRate) {
    
    do {
        printf("\tEnter interest rate [0.01; 10]: ");
        fscanf(stdin, "%lf", interestRate);
    } while(*interestRate > 10.0 || *interestRate < 0.01);

    do {
        printf("\tEnter growth rate [0.01; 5]: ");
        fscanf(stdin, "%lf", growthRate);
    } while (*growthRate > 5.0 || *growthRate < 0.01);

    return true;
}

double calculate_interest_growth(double tab[][3], int duration, double investmentAmount) {
    // declare variables
    double interestRate;
    double growthRate;
    double totalInterests = 0;

    if (!input_rate_and_growth(&interestRate, &growthRate)) {
        return -1.0;
    }

    // initialize 1. year
    tab[0][0] = interestRate;
    tab[0][1] = investmentAmount;
    tab[0][2] = investmentAmount * interestRate * 1e-2;

    for(unsigned int year = 1; year < duration; year++) {
        unsigned int lastYear = year - 1;

        // investment = investment form last year + interest
        tab[year][1] = tab[lastYear][1] + tab[lastYear][2];

        // interest rate = last interest rate + interest growth
        tab[year][0] = tab[lastYear][0] + growthRate;

        // interest = investmentAmount * interest rate
        tab[year][2] = tab[year][1] * tab[year][0] * 1e-2;

        totalInterests += tab[year][2];
    }

    return totalInterests + tab[0][2];
}

void output_table(double tab[][3], unsigned int rows, unsigned int columns) {
    printf("\n\tinterest rate [%%] investment [€] annual interest [€]\n");

    unsigned int year = 0;

    for(unsigned int row = 0; row < rows; row++) {
        year ++;
        printf("year %2d:% 12.2lf\t% 12.2lf\t% 10.2lf\n", year, tab[row][0], tab[row][1], tab[row][2]);
    }
}

unsigned int find_index(double arr[], unsigned int len) {
    unsigned int current = 0;
    double max = 0;

    for (unsigned int x = 0; x < len; x++) {
        if (arr[x] > max) {
            current = x;
            max = arr[x];
        }
    }

    return current;
}