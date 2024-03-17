#include <stdio.h>

void insertionSort(int arr[], int n) {
  int key, j;
  for (int i = 1; i < n; i++) {
    key = arr[i];  // Store the current element
    j = i - 1;      // Initialize index for comparison
    
    // Move elements of arr[0..i-1] that are greater than key, 
    // to one position ahead of their current position 
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;  // Insert the key at its correct position
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

  insertionSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
