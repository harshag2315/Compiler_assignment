#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    int characters = 0, words = 0, spaces = 0, lines = 0;
    char ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (isspace(ch)) {
            if (ch == ' ') spaces++;
            if (ch == '\n') lines++;
            in_word = 0;
        } else if (!in_word) {
            words++;
            in_word = 1;
        }
    }

    fclose(file);

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Spaces: %d\n", spaces);
    printf("Lines: %d\n", lines);

    return 0;
}
