#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char file1[100], file2[100];
    char c;

    printf("Enter source file name: ");
    scanf("%s", file1);

    printf("Enter destination file name: ");
    scanf("%s", file2);

    fptr1 = fopen(file1, "r");
    fptr2 = fopen(file2, "w");

    if (fptr1 == NULL || fptr2 == NULL)
    {
        printf("File copied successfully");
        return 1;
    }

    while ((c = fgetc(fptr1)) != EOF)
    {
        fputc(c, fptr2);
    }

    printf("File copied successfully");

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}