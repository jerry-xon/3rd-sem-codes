#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100], ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;  // Flag to track if we are inside a word

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read through the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Count characters
        characters++;

        // Count lines
        if (ch == '\n') {
            lines++;
        }

        // Check for word boundaries (spaces, newlines, or tabs)
        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            // If we were not inside a word and now encounter a non-space character, it's a new word
            inWord = 1;
            words++;
        }
    }

    // If the file is not empty and doesn't end with a newline, count the last line
    if (characters > 0 && ch != '\n') {
        lines++;
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("Number of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);

    return 0;
}

