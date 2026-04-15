#include <stdio.h>
#include <stdlib.h>

char input[100];
int pos = 0;

// Function declarations
int S();
int L();
int Ldash();

// Error function
void error() {
    printf("Invalid String\n");
    exit(1);
}

// Lookahead
char lookahead() {
    return input[pos];
}

// S → (L) | a
int S() {
    if (lookahead() == 'a') {
        pos++;
        return 1;
    }
    else if (lookahead() == '(') {
        pos++;
        if (!L()) error();

        if (lookahead() == ')') {
            pos++;
            return 1;
        } else {
            error();
        }
    }
    return 0;
}

// L → S L'
int L() {
    if (!S()) return 0;
    return Ldash();
}

// L' → , S L' | ε
int Ldash() {
    if (lookahead() == ',') {
        pos++;
        if (!S()) error();
        return Ldash();
    }
    return 1; // epsilon
}

int main() {
    printf("Enter string: ");
    scanf("%s", input);

    if (S() && input[pos] == '\0') {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}