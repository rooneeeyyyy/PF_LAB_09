
#include <stdio.h>
#include <string.h>

int main() {
    char firstname[22], lastname[22];
    char badge[50], fullname[50];
    int len1, len2, len3;

    printf("Enter first name: ");
    fgets(firstname, sizeof(firstname), stdin);

    len1 = strlen(firstname);
    if (firstname[len1-1] == '\n') {
        firstname[len1-1] = '\0';
    }

    printf("Enter last name: ");
    fgets(lastname, sizeof(lastname), stdin);

    len2 = strlen(lastname);
    if (lastname[len2-1] == '\n') {
        lastname[len2-1] = '\0';
    }

    len1 = strlen(firstname);
    len2 = strlen(lastname);

    if (len1 > 20) {
        printf("Error: first name has %d characters. Maximum allowed is 20.\n", len1);
    }
    else if (len2 > 20) {
        printf("Error: last name has %d characters. Maximum allowed is 20.\n", len2);
    }
    else {
        strcpy(badge, lastname);
        strcat(badge, ", ");
        strcat(badge, firstname);

        strcpy(fullname, firstname);
        strcat(fullname, " ");
        strcat(fullname, lastname);

        len3 = strlen(fullname);

        printf("Badge     : %s\n", badge);
        printf("Full name : %s\n", fullname);
        printf("Length    : %d\n", len3);
    }

    return 0;
}
