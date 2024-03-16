#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // Element found, return index
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int n, key;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Input the elements of the sorted array
    int arr[n];
    printf("Enter the elements of the sorted array: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Input the key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search
    int index = binarySearch(arr, n, key);

    // Write result to output file
    FILE *outputFile = fopen("binary_search_output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open binary_search_output.txt for writing.\n");
        return 1;
    }

    if (index != -1) {
        fprintf(outputFile, "Element found at index %d.\n", index);
    } else {
        fprintf(outputFile, "Element not found.\n");
    }

    fclose(outputFile);

    printf("Binary search performed and result saved to binary_search_output.txt.\n");

    return 0;
}
