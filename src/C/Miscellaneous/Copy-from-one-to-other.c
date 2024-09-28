#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFilename[100], destFilename[100];
    char ch;

    // Get the source and destination filenames from the user
    printf("Enter the source filename: ");
    scanf("%s", sourceFilename);

    printf("Enter the destination filename: ");
    scanf("%s", destFilename);

    // Open the source file in read mode
    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    // Open the destination file in write mode (creates if it doesn't exist)
    destinationFile = fopen(destFilename, "w");
    if (destinationFile == NULL) {
        printf("Error opening destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy character by character from source to destination
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully.\n");

    // Close both files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
