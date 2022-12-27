#include "options/options.h"
#include "calculator/calculator.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    const Student author = new_student("Sven", "Vogel", 1191225);

    unsigned int offerCount;
    unsigned int years;
    double investmentAmount;

    char info[100];

    generate_string(info, &author);

    if (argc > 1 && strcmp(argv[1], "--info") == 0) {
        printf("%s", info);

        if (argc > 2 && strcmp(argv[2], "--export") == 0) {
            export_to_disk(info);
            return 0;
        }
    }

    while (1) {
        
        do {
            printf("Enter investment duration in years [1; 50]: ");
            scanf("%u", &years);
        } while (years > 50 || years < 1);

        do {
            printf("Enter investment amount in € [100; 10000]: ");
            scanf("%lf", &investmentAmount);
        } while (investmentAmount > 10000 || investmentAmount < 100);

        do {
            printf("Enter offer count [1; 3]: ");
            scanf("%u", &offerCount);
        } while (investmentAmount > 10000 || investmentAmount < 100);

        // allocate table
        double (*tab)[3] = calloc(years, sizeof(double[3]));

        // alternative dynamic stack allocation: double totalInterests[offerCount];
        // alternative static stack allocation: double totalInterests[50];
        double *totalInterests = calloc(offerCount, sizeof(double));
        
        for (int i = 0; i < offerCount; i++) {
            printf("\n--------------------------------------------------------------\n");

            double totalInterest = calculate_interest_growth(tab, years, investmentAmount);

            totalInterests[i] = totalInterest;

            output_table(tab, years, 3);

            printf("\nTotal interest after 3 years: %.2lf€\n", totalInterest);
        }

        unsigned int bestOffer = find_index(totalInterests, offerCount);

        printf("\n--------------------------------------------------------------\n");
        printf("Offer %d has the best total interest with %.2lf€ after %d years\n\n", bestOffer + 1, totalInterests[bestOffer], years);
        printf("\n--------------------------------------------------------------\n");
        
        free(totalInterests);
        free(tab);
    }

    return 0;
}