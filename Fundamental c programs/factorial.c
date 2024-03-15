#include <stdio.h>
int main() {
    int n, i;
    int factorial=1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    // Show an error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        // Calculate the factorial using a loop
        for (i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("factorial of %d = %d", n, factorial);
    }

    return 0;
}
