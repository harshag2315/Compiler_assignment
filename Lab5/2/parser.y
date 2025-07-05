%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(const char *s);
int yylex();
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

expr: expr '+' expr   { printf("Result = %d\n", $1 + $3); }
    | expr '-' expr   { printf("Result = %d\n", $1 - $3); }
    | expr '*' expr   { printf("Result = %d\n", $1 * $3); }
    | expr '/' expr   { 
        if ($3 == 0) {
            printf("Error: Division by zero!\n");
            YYABORT;
        }
        printf("Valid Expression. Result = %d\n", $1 / $3);
      }
    | '(' expr ')'     { $$ = $2; }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | NUMBER          { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    printf("Syntax Error: %s\n", s);
}

int main() {
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}
