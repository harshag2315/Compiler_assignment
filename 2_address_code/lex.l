%{
#include "y.tab.h"
#include <string.h>
%}

%%

"main"              { return MAIN; }
"int"               { return INT; }
"print"             { return PRINT; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return ID; }
[0-9]+                  { yylval.str = strdup(yytext); return ID; } // constants as IDs

"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
";"                 { return SEMI; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL; }
"="                 { return ASSIGN; }

[ \t\r\n]+          { /* Skip whitespace */ }
.                   { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
