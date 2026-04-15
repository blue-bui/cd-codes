#include <stdio.h>
#include <ctype.h>

int main() {
    char str[50];
    int i;

    printf("Enter variable: ");
    scanf("%s", str);

    // Check first character
    if (!isalpha(str[0])) {
        printf("Invalid Variable\n");
        return 0;
    }

    // Check remaining characters
    for (i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            printf("Invalid Variable\n");
            return 0;
        }
    }

    printf("Valid Variable\n");
    return 0;
}