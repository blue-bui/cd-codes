%{
#include "y.tab.h"
%}

%%
[0-9]+      { return NUM; }
[+\-*/()]   { return yytext[0]; }
\n          { return '\n'; }
[ \t]       ;
.           { return yytext[0]; }
%%

int yywrap(void) { return 1; }