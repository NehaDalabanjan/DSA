#include <stdio.h>
#include<stdlib.h>

int check_prime(int i, int num);

int main() {
    FILE *file = fopen("output.txt", "w");
    int num;

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter the number: ");
    scanf("%d", &num);

    if (check_prime(2, num) == 0) {
        fprintf(file, "Its a prime number.\n");
    } else {
        fprintf(file, "Not a prime number.\n");
    }

    fclose(file);

    return 0;
}

int check_prime(int i, int num) {
    if (num == i) {
        return 0;
    } else {
        if (num % i == 0) {
            return 1;
        } else {
            return check_prime(i + 1, num);
        }
    }
}
