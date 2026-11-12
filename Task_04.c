
#include <stdio.h>
#include <string.h>

int main() {
    char rooms[5][10] = {"R101", "R102", "R103", "R104", "R105"};
    char guests[5][50] = {"", "", "", "", ""};
    char room[10], name[50];
    int choice, i, found;

    do {
        printf("\n1. Book room 2. Check out 3. Show rooms 4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter room number:\n ");
            fgets(room, sizeof(room), stdin);

            int len = strlen(room);
            if (room[len-1] == '\n') {
                room[len-1] = '\0';
            }

            found = 0;

            for (i = 0; i < 5; i++) {
                if (strcmp(room, rooms[i]) == 0) {
                    found = 1;

                    if (strcmp(guests[i], "") == 0) {
                        printf("Enter guest name: ");
                        fgets(name, sizeof(name), stdin);

                        len = strlen(name);
                        if (name[len-1] == '\n') {
                            name[len-1] = '\0';
                        }

                        strcpy(guests[i], name);

                        printf("Room %s booked for %s.\n", rooms[i], guests[i]);
                    }
                    else {
                        printf("Error: %s is already occupied.\n", rooms[i]);
                    }

                    break;
                }
            }

            if (found == 0) {
                printf("Error: room not found.\n");
            }
        }

        else if (choice == 2) {
            printf("Enter room number: ");
            fgets(room, sizeof(room), stdin);

            int len = strlen(room);
            if (room[len-1] == '\n') {
                room[len-1] = '\0';
            }

            found = 0;

            for (i = 0; i < 5; i++) {
                if (strcmp(room, rooms[i]) == 0) {
                    found = 1;

                    if (strcmp(guests[i], "") != 0) {
                        printf("%s checked out of %s.\n", guests[i], rooms[i]);
                        guests[i][0] = '\0';
                    }
                    else {
                        printf("Error: %s is already empty.\n", rooms[i]);
                    }

                    break;
                }
            }

            if (found == 0) {
                printf("Error: room not found.\n");
            }
        }

        else if (choice == 3) {
            for (i = 0; i < 5; i++) {
                if (strcmp(guests[i], "") == 0) {
                    printf("%s - Empty\n", rooms[i]);
                }
                else {
                    printf("%s - %s\n", rooms[i], guests[i]);
                }
            }
        }

        else if (choice == 4) {
            printf("Exiting program...\n");
        }

        else {
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
