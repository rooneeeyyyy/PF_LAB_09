
#include <stdio.h>

int main() {
    FILE *fp;
    char name[50];
    int quantity, i;
    float price, total, grandtotal = 0;

    fp = fopen("sales.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        printf("Enter item %d (name quantity price): ", i+1);
        scanf("%s %d %f", name, &quantity, &price);

        fprintf(fp, "%s %d %.2f\n", name, quantity, price);
    }

    fclose(fp);

    fp = fopen("sales.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nItem        Qty      Price       Total\n");

    while (fscanf(fp, "%s %d %f", name, &quantity, &price) == 3) {
        total = quantity * price;
        grandtotal = grandtotal + total;

        printf("%-12s %-8d %-11.2f %.2f\n", name, quantity, price, total);
    }

    printf("Grand total: %.2f\n", grandtotal);

    fclose(fp);

    return 0;
}
