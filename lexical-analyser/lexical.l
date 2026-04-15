%{
#include <stdio.h>
#include <stdlib.h>
%}

id      [A-Za-z_][A-Za-z0-9_]*

%%
"//".*          { printf("Comment: %s\n", yytext); }
{id}            { printf("Identifier: %s\n", yytext); }
[0-9]+          { printf("Number: %s\n", yytext); }
[+\-*/=]        { printf("Operator: %s\n", yytext); }
[ \t\n]+        ;
.               ;
%%

int yywrap(void) { return 1; }

int main(void) { yylex(); return 0; }