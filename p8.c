// To implement binary search.
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node in a sorted linked list (ascending order)
void insertSorted(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* current;

    /* 1. Special case for the empty list */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* 2. Traverse the list to find the insertion position */
    current = *head_ref;
    while (current->next != NULL && current->next->data < new_data) {
        current = current->next;
    }

    /* 3. Insert node at the found position */
    new_node->next = current->next;
    current->next = new_node;
}

// Function to get the count of nodes in the linked list
int getLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to search for a given key (value) in the linked list using binary search
int binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1; // Adjust for 0-based indexing

    // Handle empty list
    if (head == NULL) {
        return -1;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;
        Node* current = head;

        // Traverse to the mid-point node
        for (int i = 0; i < mid; i++) {
            if (current == NULL) {
                return -1; // Unexpected error (list might be corrupted)
            }
            current = current->next;
        }

        // Check if key is present at mid
        if (current != NULL && current->data == key) {
            return mid + 1; // Return position (1-based indexing)
        }

        // If key is greater, ignore left half
        if (current != NULL && current->data < key) {
            left = mid + 1;
        } else { // key is smaller, ignore right half
            right = mid - 1;
        }
    }

    // Key not found
    return -1;
}

int main() {
    Node* head = NULL; // Initially an empty list

    int num_elements, data;

    // Get the number of elements to insert from the user
    printf("Enter the number of elements in the linked list (sorted ascending): ");
    scanf("%d", &num_elements);

    // Insert elements into the linked list based on user input
    for (int i = 0; i < num_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertSorted(&head, data);
    }

    printf("Created linked list (sorted): ");
    // Print the linked list for clarity (optional)
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Get the key to search for from the user
    int key;
    printf("Enter the key to search for: ");
    scanf("%d", &key);

    int position = binarySearch(head, key);

    if (position == -1) {
        printf("Key %d not found in linked list\n", key);
    } else {
        printf("Key %d found at position %d\n", key, position);
    }

    return 0;
}
