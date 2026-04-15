%{
#include <stdio.h>
int yylex(void);
int yyerror(const char *s);
%}

%token INT FLOAT CHAR
%token INT_VAL FLOAT_VAL CHAR_VAL
%token ID

%%
program : stmt
        ;

stmt    : INT   ID '=' INT_VAL   { printf("Type Check OK : int assignment\n"); }
    | FLOAT ID '=' FLOAT_VAL { printf("Type Check OK : float assignment\n"); }
    | CHAR  ID '=' CHAR_VAL  { printf("Type Check OK : char assignment\n"); }
    | INT   ID '=' FLOAT_VAL { printf("Type Error    : float assigned to int\n"); }
    | INT   ID '=' CHAR_VAL  { printf("Type Error    : char assigned to int\n"); }
    | FLOAT ID '=' INT_VAL   { printf("Type Error    : int assigned to float\n"); }
    | FLOAT ID '=' CHAR_VAL  { printf("Type Error    : char assigned to float\n"); }
    | CHAR  ID '=' INT_VAL   { printf("Type Error    : int assigned to char\n"); }
    | CHAR  ID '=' FLOAT_VAL { printf("Type Error    : float assigned to char\n"); }
        ;
%%

int main(void) {
    printf("Enter declaration (ex: int x = 5): \n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Syntax Error\n");
    return 0;
}