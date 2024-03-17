#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to heapify a subtree rooted with node i which is
// assumed to be a max heap
void heapify(int arr[], int n, int i) {
  int largest = i; // Initialize largest as root
  int left = 2 * i + 1; // left = 2*i + 1
  int right = 2 * i + 2; // right = 2*i + 2

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child is larger than largest so far
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(&arr[largest], &arr[i]);

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// Function to build a max heap from the array
void buildHeap(int arr[], int n) {
  // Start from the last parent (assuming the array is 0-indexed)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
}

// Function to implement Heap Sort
void heapSort(int arr[], int n) {
  // Build a max heap
  buildHeap(arr, n);

  // One by one extract an element from heap
  for (int i = n - 1; i > 0; i--) {
    // Move current root to end
    swap(&arr[0], &arr[i]);

    // Call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

// Function to print the array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
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
  printArray(arr, n);

  heapSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
