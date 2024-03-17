#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int swapped = 1;  // Flag to track if any swaps occurred in a pass
    int temp;

    for (int i = 0; i < n - 1 && swapped; i++) {
        swapped = 0;  // Reset flag for the next pass
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // Set flag if a swap occurred
            }
        }
    }
}

int main() {
    int arr[100]; // Array to hold elements (adjust size as needed)
    int n;

    printf("Enter the number of elements (less than 100): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
