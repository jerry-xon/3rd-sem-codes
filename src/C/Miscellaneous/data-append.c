#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char filename[100], data[100];

    // Get the filename from the user
    printf("Enter the filename to append to: ");
    scanf("%s", filename);

    // Open the file in append mode
    fptr = fopen(filename, "a");

    // Check if the file was successfully opened
    if (fptr == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Get the data from the user
    printf("Enter the data you want to append: ");
    getchar(); // To consume the newline left by scanf
    fgets(data, sizeof(data), stdin);

    // Append the data to the file
    fprintf(fptr, "%s", data);

    // Close the file
    fclose(fptr);

    printf("Data successfully appended to the file.\n");

    return 0;
}
