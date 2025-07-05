%{
#include "y.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[\+\-\*/]   { return yytext[0]; }
\(          { return '('; }
\)          { return ')'; }
[ \t\n]     { /* Ignore whitespaces */ }
.           { printf("Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
