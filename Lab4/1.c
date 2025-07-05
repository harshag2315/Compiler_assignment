#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceScanPrint(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    FILE *temp = fopen("output.c", "w");
    if (!temp) {
        printf("Error creating output file.\n");
        fclose(file);
        return;
    }

    char line[256];
    int scanfCount = 0, printfCount = 0;

    while (fgets(line, sizeof(line), file)) {
        char *pos;
        
        if ((pos = strstr(line, "scanf")) != NULL) {
            scanfCount++;
            fprintf(temp, "%.*sread%s", (int)(pos - line), line, pos + 5);
        } else if ((pos = strstr(line, "printf")) != NULL) {
            printfCount++;
            fprintf(temp, "%.*swrite%s", (int)(pos - line), line, pos + 6);
        } else {
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);

    printf("Number of scanf: %d\n", scanfCount);
    printf("Number of printf: %d\n", printfCount);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    replaceScanPrint(filename);
    return 0;
}
