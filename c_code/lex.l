%{
typedef struct node {
    int value;
} nodeType;

#include "y.tab.h"  // must come after nodeType is defined
%}

%%

"main"          return MAIN;
"int"           return INT;
"print"         return PRINT;
"="             return ASSIGN;
";"             return SEMI;
"("             return '(';
")"             return ')';
"{"             return '{';
"}"             return '}';
"+"             return PLUS;
"-"             return MINUS;
"*"             return TIMES;

[0-9]+          {
                    yylval.iValue = atoi(yytext);
                    return NUMBER;
                }

[a-z]           {
                    yylval.sIndex = yytext[0];
                    return ID;
                }

[ \t\r\n]+      ;  // ignore whitespace

.               {
                    printf("Unknown character: %s\n", yytext);
                }

%%

int yywrap() {
    return 1;
}
