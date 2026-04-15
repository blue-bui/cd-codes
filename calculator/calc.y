%{
#include <stdio.h>
int yylex(void);
int yyerror(const char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/' '%'

%%
s : e '\n'         { printf("Result = %d\n", $1); };
e : e '+' e        { $$ = $1 + $3; }
  | e '-' e        { $$ = $1 - $3; }
  | e '*' e        { $$ = $1 * $3; }
  | e '/' e        { $$ = $1 / $3; }
  | e '%' e        { $$ = $1 % $3; }
  | '(' e ')'      { $$ = $2; }
  | NUM            { $$ = $1; }
  ;
%%

int main(void) { return yyparse(); }
int yyerror(const char *s) { printf("Invalid expression\n"); return 0; }