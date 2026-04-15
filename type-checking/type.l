%{
#include "type.tab.h"
%}

%%
"int"           { return INT; }
"float"         { return FLOAT; }
"char"          { return CHAR; }
[0-9]+\.[0-9]+  { return FLOAT_VAL; }
[0-9]+          { return INT_VAL; }
\'[a-zA-Z]\'    { return CHAR_VAL; }
[a-zA-Z]+       { return ID; }
[ \t\n]         ;
.               { return yytext[0]; }
%%
int yywrap(void) { return 1; }