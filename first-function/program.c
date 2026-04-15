#include <stdio.h>
#include <ctype.h>
#include <string.h>

char productions[10][10];
char first[10];
int count, n = 0;

// Check if already present
int isPresent(char c) {
    for (int i = 0; i < n; i++) {
        if (first[i] == c)
            return 1;
    }
    return 0;
}

// Function to find FIRST
void FIRST(char c) {
    int i;

    // If terminal → add directly
    if (!isupper(c)) {
        if (!isPresent(c))
            first[n++] = c;
        return;
    }

    // Search productions
    for (i = 0; i < count; i++) {
        if (productions[i][0] == c) {

            // If epsilon
            if (productions[i][2] == '$') {
                if (!isPresent('$'))
                    first[n++] = '$';
            }

            // If terminal after =
            else if (!isupper(productions[i][2])) {
                if (!isPresent(productions[i][2]))
                    first[n++] = productions[i][2];
            }

            // If non-terminal → recurse
            else {
                FIRST(productions[i][2]);
            }
        }
    }
}

int main() {
    int i;
    char symbol;

    printf("Enter number of productions: ");
    scanf("%d", &count);

    printf("Enter productions (use $ for epsilon):\n");
    for (i = 0; i < count; i++) {
        scanf("%s", productions[i]);
    }

    printf("Enter symbol to find FIRST: ");
    scanf(" %c", &symbol);

    FIRST(symbol);

    printf("FIRST(%c) = { ", symbol);
    for (i = 0; i < n; i++) {
        printf("%c ", first[i]);
    }
    printf("}\n");

    return 0;
}