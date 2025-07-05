#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <c_program_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    int comment_lines = 0;
    char line[1024];
    int in_multiline_comment = 0;

    while (fgets(line, sizeof(line), file)) {
        char *trimmed = line;

        while (*trimmed == ' ' || *trimmed == '\t') trimmed++;

        if (in_multiline_comment) {
            comment_lines++;
            if (strstr(trimmed, "*/")) {
                in_multiline_comment = 0;
            }
        } else if (strncmp(trimmed, "//", 2) == 0) {
            comment_lines++;
        } else if (strncmp(trimmed, "/*", 2) == 0) {
            comment_lines++;
            if (!strstr(trimmed, "*/")) {
                in_multiline_comment = 1;
            }
        }
    }

    fclose(file);

    printf("Number of comment lines: %d\n", comment_lines);
    return 0;
}
