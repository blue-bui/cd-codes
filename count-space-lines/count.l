%{
#include <stdio.h>
int w = 0, l = 0;
%}

%%
\n              { l++; }
[A-Za-z0-9_]+   { w++; }
.               ;
%%

int yywrap(void) { return 1; }

int main(void) { yylex(); printf("Lines: %d\nWords: %d\n", l, w); }