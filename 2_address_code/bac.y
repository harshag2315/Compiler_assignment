%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tempCount = 0;

char* newTemp() {
    char* temp = malloc(10);
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
int yylex();

// symbol table
typedef struct {
    char name[100];
    int value;
} Symbol;

Symbol symtab[100];
int symCount = 0;

int getValue(char* name) {
    for (int i = 0; i < symCount; i++) {
        if (strcmp(symtab[i].name, name) == 0)
            return symtab[i].value;
    }
    return atoi(name); // if not found, treat as constant
}

void setValue(char* name, int val) {
    for (int i = 0; i < symCount; i++) {
        if (strcmp(symtab[i].name, name) == 0) {
            symtab[i].value = val;
            return;
        }
    }
    // if not found, add new
    strcpy(symtab[symCount].name, name);
    symtab[symCount].value = val;
    symCount++;
}
%}

%union {
    char* str;
    int val;
}

%token <str> ID
%token MAIN INT PRINT
%token LPAREN RPAREN LBRACE RBRACE SEMI PLUS MINUS MUL ASSIGN

%type <val> expression

%%

program:
    MAIN LPAREN RPAREN LBRACE statements RBRACE {printf("Parsing Done");}
    ;

statements:
    statement SEMI
    | statements statement SEMI
    ;

statement:
    assignment
    | declaration
    | print_stmt
    ;

declaration:
    INT ID
    {
        printf("// Declare: int %s\n", $2);
        setValue($2, 0); // default initialize
    }
    ;

print_stmt:
    PRINT ID
    {
        int v = getValue($2);
        printf("PRINT %d\n", v);
    }
    ;

assignment:
    ID ASSIGN expression
    {
        setValue($1, $3);
        printf("MOV %d, %s\n", $3, $1);
    }
    ;

expression:
    ID
    {
        $$ = getValue($1);
        char* temp = newTemp();
        printf("MOV %d, %s\n", $$, temp);
    }
    | expression PLUS expression
    {
        $$ = $1 + $3;
        char* temp = newTemp();
        printf("ADD %d, %d -> %d\n", $1, $3, $$);
    }
    | expression MINUS expression
    {
        $$ = $1 - $3;
        char* temp = newTemp();
        printf("SUB %d, %d -> %d\n", $1, $3, $$);
    }
    | expression MUL expression
    {
        $$ = $1 * $3;
        char* temp = newTemp();
        printf("MUL %d, %d -> %d\n", $1, $3, $$);
    }
    ;

%%

int main() {
    return yyparse();
}
