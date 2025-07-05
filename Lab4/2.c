#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50

// List of C keywords
char *keywords[] = {
    "int", "float", "if", "else", "while", "return", "for", "char", "double",
    "void", "switch", "case", "do", "break", "continue", "default", "extern",
    "register", "static", "typedef", "union", "struct", "enum", "signed",
    "unsigned", "const", "volatile", "short", "long", "sizeof", "goto"
};
int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

// Function to check if a word is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to check if a word is a valid identifier
int isValidIdentifier(char *word) {
    if (!isalpha(word[0]) && word[0] != '_')  // First character must be a letter or ''
        return 0;

    return 1;
}

// Function to count identifiers in a file
void countIdentifiers(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char word[MAX_WORD_LEN];
    int identifierCount = 0;
    char ch;
    int index = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch) || ch == '_') {  // If part of an identifier
            word[index++] = ch;
        } else {
            if (index > 0) {  // End of a word
                word[index] = '\0';  // Null-terminate the string
                index = 0;
                if (!isKeyword(word) && isValidIdentifier(word)) {
                    identifierCount++;
                    printf("%s\n", word);
                }
            }
        }
    }

    fclose(file);
    printf("Total Identifiers: %d\n", identifierCount);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    countIdentifiers(filename);
    return 0;
}
