
#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    float value, weight, ratio;
    float fraction;
} Package;

Package p[MAX];
int n = 0;
float capacity = 0, totalValue = 0, totalWeight = 0;
int entered = 0, sorted = 0, calculated = 0;

void enterDetails() {
    int i;

    printf("Enter number of packages: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of packages!\n");
        n = 0;
        entered = 0;
        return;
    }

    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].fraction = 0;

        printf("\nEnter value of package %d: ", i + 1);
        scanf("%f", &p[i].value);

        printf("Enter weight of package %d: ", i + 1);
        scanf("%f", &p[i].weight);

        if (p[i].value < 0 || p[i].weight <= 0) {
            printf("Value must be non-negative and weight positive.\n");
            n = 0;
            entered = 0;
            return;
        }

        p[i].ratio = p[i].value / p[i].weight;
    }

    printf("\nEnter vehicle capacity: ");
    scanf("%f", &capacity);

    if (capacity < 0) {
        printf("Invalid capacity!\n");
        n = 0;
        entered = 0;
        return;
    }

    entered = 1;
    sorted = 0;
    calculated = 0;

    printf("\nPackage details entered successfully!\n");
}

void displayDetails() {
    int i;

    if (!entered) {
        printf("Please enter package details first.\n");
        return;
    }

    printf("\nID\tValue\tWeight\tRatio\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id, p[i].value,
               p[i].weight, p[i].ratio);
    }

    printf("Vehicle capacity: %.2f\n", capacity);
}

void calculateRatio() {
    int i;

    if (!entered) {
        printf("Please enter package details first.\n");
        return;
    }

    printf("\nPackage Value/Weight Ratios:\n");

    for (i = 0; i < n; i++) {
        p[i].ratio = p[i].value / p[i].weight;
        printf("Package %d: %.2f / %.2f = %.2f\n",
               p[i].id, p[i].value,
               p[i].weight, p[i].ratio);
    }
}

void sortPackages() {
    int i, j;
    Package temp;

    if (!entered) {
        printf("Please enter package details first.\n");
        return;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].ratio < p[j + 1].ratio) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    sorted = 1;
    calculated = 0;

    printf("\nPackages sorted in decreasing ratio order.\n");
    printf("ID\tValue\tWeight\tRatio\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id, p[i].value,
               p[i].weight, p[i].ratio);
    }
}

void findMaximumValue() {
    int i;
    float remaining, take;

    if (!entered) {
        printf("Please enter package details first.\n");
        return;
    }

    if (!sorted) {
        printf("Please sort packages by ratio first.\n");
        return;
    }

    remaining = capacity;
    totalValue = 0;
    totalWeight = 0;

    for (i = 0; i < n; i++)
        p[i].fraction = 0;

    for (i = 0; i < n && remaining > 0; i++) {
        if (p[i].weight <= remaining) {
            p[i].fraction = 1.0;
            totalValue += p[i].value;
            totalWeight += p[i].weight;
            remaining -= p[i].weight;
        } else {
            take = remaining / p[i].weight;
            p[i].fraction = take;
            totalValue += take * p[i].value;
            totalWeight += remaining;
            remaining = 0;
        }
    }

    calculated = 1;

    printf("\nMaximum value calculation completed!\n");
    printf("Total weight used: %.2f\n", totalWeight);
    printf("Maximum value obtained: %.2f\n", totalValue);
}

void displaySelectedPackages() {
    int i;

    if (!calculated) {
        printf("Please calculate maximum value first.\n");
        return;
    }

    printf("\nSelected Packages:\n");
    printf("ID\tFraction\tWeight\tValue\n");

    for (i = 0; i < n; i++) {
        if (p[i].fraction > 0) {
            printf("%d\t%.2f\t\t%.2f\t%.2f\n",
                   p[i].id,
                   p[i].fraction,
                   p[i].fraction * p[i].weight,
                   p[i].fraction * p[i].value);
        }
    }

    printf("\nTotal weight used: %.2f\n", totalWeight);
    printf("Maximum value: %.2f\n", totalValue);
}

int main() {
    int choice;

    do {
        printf("\n===== FRACTIONAL KNAPSACK =====\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterDetails();
                break;

            case 2:
                displayDetails();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                findMaximumValue();
                break;

            case 6:
                displaySelectedPackages();
                break;

            case 7:
                printf("Exiting program. Thank you!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
