%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUM; }
\n          { return '\n'; }
[+\-*/()%]  { return yytext[0]; }
[ \t]       ;
.           { return yytext[0]; }
%%

int yywrap(void) { return 1; }