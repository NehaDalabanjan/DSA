#include <stdio.h>

int main()
{
    int number1, number2, sum;

    // Read two integers from input.txt
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error: Unable to open input.txt for reading.\n");
        return 1;
    }
    fscanf(inputFile, "%d %d", &number1, &number2);
    fclose(inputFile);

    // Calculate the sum
    sum = number1 + number2;

    // Write the sum to output.txt
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error: Unable to open output.txt for writing.\n");
        return 1;
    }
    fprintf(outputFile, "%d + %d = %d\n", number1, number2, sum);
    fclose(outputFile);

    return 0;
}
