
#include <stdio.h>
#include <string.h>

int main() {
    char code[50];
    char *dash;
    int i, valid = 1;

    printf("Enter product code: ");
    fgets(code, sizeof(code), stdin);

    int len = strlen(code);

    if (code[len-1] == '\n') {
        code[len-1] = '\0';
    }

    len = strlen(code);

    if (len != 8) {
        printf("Invalid code: length must be 8.\n");
    }
    else {
        dash = strchr(code, '-');

        if (dash == NULL || code[3] != '-') {
            printf("Invalid code: the 4th character must be '-'.\n");
        }
        else if (strncmp(code, "ELE", 3) != 0 &&
                 strncmp(code, "GRO", 3) != 0 &&
                 strncmp(code, "CLO", 3) != 0) {
            printf("Invalid code: unknown category.\n");
        }
        else {
            for (i = 4; i < 8; i++) {
                if (code[i] < '0' || code[i] > '9') {
                    valid = 0;
                    break;
                }
            }

            if (valid == 0) {
                printf("Invalid code: last 4 characters must be digits.\n");
            }
            else {
                if (strncmp(code, "ELE", 3) == 0) {
                    printf("Valid code. Category: Electronics\n");
                }
                else if (strncmp(code, "GRO", 3) == 0) {
                    printf("Valid code. Category: Grocery\n");
                }
                else {
                    printf("Valid code. Category: Clothing\n");
                }
            }
        }
    }

    return 0;
}
