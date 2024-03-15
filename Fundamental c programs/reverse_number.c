#include <stdio.h>

int main()
{
    int n;

    // Read integer from input.txt
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error: Unable to open input.txt for reading.\n");
        return 1;
    }
    fscanf(inputFile, "%d", &n);
    fclose(inputFile);

    // Initialize reverse to 0
    int reverse = 0;

    // Loop until n becomes 0
    while (n != 0) {
        // Get the remainder of n divided by 10
        int remainder = n % 10;

        // Reverse is updated by adding the remainder multiplied by 10
        // to the current value of reverse, then shifting reverse to
        // the left by one digit
        reverse = reverse * 10 + remainder;

        // Divide n by 10 to remove the last digit
        n /= 10;
    }

    // Write the reversed number to output.txt
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error: Unable to open output.txt for writing.\n");
        return 1;
    }
    fprintf(outputFile, "Reversed number = %d", reverse);
    fclose(outputFile);

    return 0;
}
