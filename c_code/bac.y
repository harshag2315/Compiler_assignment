%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAR_SIZE 26

typedef struct nodeTypeTag {
    int value;
} nodeType;

int variables[VAR_SIZE];     // for a-z
int var_declared[VAR_SIZE];  // track declarations

int yyerror(const char *s);
int yylex(void);
%}

%union {
    int iValue;
    char sIndex;
    nodeType *nPtr;
}

%token MAIN INT ASSIGN PRINT
%token <iValue> NUMBER
%token <sIndex> ID
%token PLUS MINUS TIMES SEMI

%type <nPtr> expression
%type <nPtr> assignment
%type <nPtr> declaration
%type <nPtr> program
%type <nPtr> statement
%type <nPtr> statements

%%

program:
    MAIN '(' ')' '{' statements '}' {
        printf("Execution finished.\n");
    }
;

statements:
      /* empty */ { $$ = NULL; }
    | statements statement
;

statement:
      declaration
    | assignment
    | PRINT ID SEMI {
        int index = $2 - 'a';
        if (!var_declared[index]) {
            printf("Error: variable %c not declared.\n", $2);
        } else {
            printf("Print variable: %c = %d\n", $2, variables[index]);
        }
    }
    | expression SEMI {
        printf("Result: %d\n", $1->value);
        free($1);
    }
;

declaration:
    INT ID SEMI {
        int index = $2 - 'a';
        if (var_declared[index]) {
            printf("Warning: variable %c already declared.\n", $2);
        } else {
            var_declared[index] = 1;
            printf("Declared variable %c\n", $2);
        }
        $$ = NULL;
    }
;

assignment:
    ID ASSIGN expression SEMI {
        int index = $1 - 'a';
        if (!var_declared[index]) {
            printf("Error: variable %c not declared.\n", $1);
        } else {
            variables[index] = $3->value;
            printf("Assigned %d to %c\n", $3->value, $1);
        }
        free($3);
        $$ = NULL;
    }
;

expression:
      NUMBER {
          $$ = malloc(sizeof(nodeType));
          $$->value = $1;
      }
    | ID {
        int index = $1 - 'a';
        $$ = malloc(sizeof(nodeType));
        if (!var_declared[index]) {
            printf("Error: variable %c not declared.\n", $1);
            $$->value = 0;
        } else {
            $$->value = variables[index];
        }
    }
    | expression PLUS expression {
        $$ = malloc(sizeof(nodeType));
        $$->value = $1->value + $3->value;
        free($1); free($3);
    }
    | expression MINUS expression {
        $$ = malloc(sizeof(nodeType));
        $$->value = $1->value - $3->value;
        free($1); free($3);
    }
    | expression TIMES expression {
        $$ = malloc(sizeof(nodeType));
        $$->value = $1->value * $3->value;
        free($1); free($3);
    }
;

%%

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}

int main(void) {
    printf("Enter a main block (e.g., main() { int x; x = 5 + 3; print x; })\n");
    return yyparse();
}

