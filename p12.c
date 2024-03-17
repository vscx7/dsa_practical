#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function for quicksort
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Select the last element as pivot
  int i = (low - 1); // Index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // Check if current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++;    // Increment index of smaller element
      swap(&arr[i], &arr[j]);  // Swap current element with the smaller element
    }
  }
  swap(&arr[i + 1], &arr[high]); // Swap the pivot element with the element at i+1
  return (i + 1);
}

// Recursive quicksort function
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // pi is partitioning index, arr[p] is now at right place
    int pi = partition(arr, low, high);

    // Recursively sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
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

  quickSort(arr, 0, n - 1);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
