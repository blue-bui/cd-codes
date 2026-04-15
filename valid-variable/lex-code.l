%{
#include <stdio.h>
%}

%option noyywrap

%%

[a-zA-Z][a-zA-Z0-9]*   { printf("Valid Variable: %s\n", yytext); }

[0-9][a-zA-Z0-9]*      { printf("Invalid Variable: %s\n", yytext); }

.|\n                   ;   /* ignore others */

%%

int main() {
    printf("Enter input:\n");
    yylex();
    return 0;
}