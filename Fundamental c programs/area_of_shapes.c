#include <stdio.h>

int main() {
    int figure;
    float side, base, length, breadth, height, area, radius;

    printf("Choose a shape:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Square\n");
    printf("Enter the figure code: ");
    scanf("%d", &figure);

    switch (figure) {
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            area = 3.142 * radius * radius;
            printf("Area of the circle: %.2f square units\n", area);
            break;
        case 2:
            printf("Enter the breadth and length of the rectangle: ");
            scanf("%f %f", &breadth, &length);
            area = breadth * length;
            printf("Area of the rectangle: %.2f square units\n", area);
            break;
        case 3:
            printf("Enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            area = 0.5 * base * height;
            printf("Area of the triangle: %.2f square units\n", area);
            break;
        case 4:
            printf("Enter the side length of the square: ");
            scanf("%f", &side);
            area = side * side;
            printf("Area of the square: %.2f square units\n", area);
            break;
        default:
            printf("Invalid figure code. Please choose a valid option.\n");
    }

    return 0;
}
