#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char c;

    // Open the first file for reading
    fptr1 = fopen("file1.txt", "r");

    if (fptr1 == NULL)
    {
        printf("Cannot open file1.txt \n");
        exit(0);
    }

    // Open the second file for appending
    fptr2 = fopen("file2.txt", "a");

    if (fptr2 == NULL)
    {
        printf("Cannot open file2.txt \n");
        exit(0);
    }

    // Copy the contents of file1 to file2
    while ((c = fgetc(fptr1)) != EOF)
    {
        fputc(c, fptr2);
    }

    // Close both files
    fclose(fptr1);
    fclose(fptr2);

    printf("Contents added successfully.\n");

    return 0;
}
