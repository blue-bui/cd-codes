%{
#include <stdio.h>
int yylex(void);
int yyerror(const char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
s : e '\n'     { puts("Valid expression"); };
e : e '+' e
  | e '-' e
  | e '*' e
  | e '/' e
  | '(' e ')'
  | NUM
  ;
%%

int main(void) { return yyparse(); }
int yyerror(const char *s) { puts("Invalid expression"); return 0; }