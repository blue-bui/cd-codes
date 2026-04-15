#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {
    "int", "float", "char", "if", "else", "while", "for", "return"
};

// Check keyword
int isKeyword(char *str) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[50];
    int i = 0;

    printf("Enter code (Ctrl+D to stop):\n");

    while ((ch = getchar()) != EOF) {

        // IDENTIFIER / KEYWORD
        if (isalpha(ch)) {
            buffer[i++] = ch;

            while (isalnum(ch = getchar()) || ch == '_') {
                buffer[i++] = ch;
            }

            buffer[i] = '\0';
            i = 0;

            if (isKeyword(buffer))
                printf("%s : KEYWORD\n", buffer);
            else
                printf("%s : IDENTIFIER\n", buffer);

            ungetc(ch, stdin);
        }

        // NUMBER
        else if (isdigit(ch)) {
            buffer[i++] = ch;

            while (isdigit(ch = getchar())) {
                buffer[i++] = ch;
            }

            buffer[i] = '\0';
            i = 0;

            printf("%s : NUMBER\n", buffer);
            ungetc(ch, stdin);
        }

        // COMMENT (// style)
        else if (ch == '/') {
            char next = getchar();

            if (next == '/') {
                printf("COMMENT\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
            }
            else {
                printf("/ : OPERATOR\n");
                ungetc(next, stdin);
            }
        }

        // OPERATORS
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '=' || ch == '<' || ch == '>') {
            printf("%c : OPERATOR\n", ch);
        }

        // IGNORE SPACES
        else if (isspace(ch)) {
            continue;
        }

        // SPECIAL SYMBOLS
        else {
            printf("%c : SPECIAL SYMBOL\n", ch);
        }
    }

    return 0;
}