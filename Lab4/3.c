#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=');
}

int isValidIdentifier(char *word) {
    if (!isalpha(word[0]) && word[0] != '_')
        return 0;

    for (int i = 1; word[i] != '\0'; i++) {
        if (!isalnum(word[i]) && word[i] != '_')
            return 0;
    }

    return 1;
}

void analyzeExpression(char *expression) {
    char identifiers[10][20], operators[10];
    int idCount = 0, opCount = 0;
    char token[20];
    int tokenIndex = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isOperator(expression[i])) {
            operators[opCount++] = expression[i];
        } else if (isalnum(expression[i]) || expression[i] == '_') {
            token[tokenIndex++] = expression[i];
        } else if (expression[i] == ' ' || expression[i] == ';') {
            if (tokenIndex > 0) {
                token[tokenIndex] = '\0';
                if (isValidIdentifier(token)) {
                    strcpy(identifiers[idCount++], token);
                }
                tokenIndex = 0;
            }
        }
    }

    printf("Identifiers: ");
    for (int i = 0; i < idCount; i++)
        printf("%s ", identifiers[i]);
    printf("\nOperators: ");
    for (int i = 0; i < opCount; i++)
        printf("%c ", operators[i]);
    printf("\n");
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    analyzeExpression(expression);
    return 0;
}
