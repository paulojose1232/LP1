#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    int count = 0;
    char c;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        count++;
    }

    fclose(file);

    printf("The file contains %d characters.\n", count);

    return 0;
}
