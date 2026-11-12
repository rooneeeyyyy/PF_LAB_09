
#include <stdio.h>
#include <string.h>

int main() {
    char names[5][30];
    char marks[5];
    int i, present = 0, absent = 0;

    for (i = 0; i < 5; i++) {
        printf("Enter name %d: ", i+1);
        fgets(names[i], sizeof(names[i]), stdin);

        int len = strlen(names[i]);

        if (names[i][len-1] == '\n') {
            names[i][len-1] = '\0';
        }
    }

    printf("\nMark attendance (P/A):\n");

    for (i = 0; i < 5; i++) {
        printf("%s: ", names[i]);
        scanf(" %c", &marks[i]);

        if (marks[i] == 'P' || marks[i] == 'p') {
            present++;
        }
        else {
            absent++;
        }
    }

    printf("\n--- Attendance Sheet ---\n");

    for (i = 0; i < 5; i++) {
        if (marks[i] == 'P' || marks[i] == 'p') {
            printf("%d. %s    Present\n", i+1, names[i]);
        }
        else {
            printf("%d. %s    Absent\n", i+1, names[i]);
        }
    }

    printf("Present: %d, Absent: %d\n", present, absent);

    printf("Absent students: ");

    int count = 0;

    for (i = 0; i < 5; i++) {
        if (marks[i] == 'A' || marks[i] == 'a') {
            if (count > 0) {
                printf(", ");
            }

            printf("%s", names[i]);
            count++;
        }
    }

    printf("\n");

    return 0;
}
