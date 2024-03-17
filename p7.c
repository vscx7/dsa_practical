// To implement linear search.
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

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    if (*head_ref == NULL) {
        (*head_ref) = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to search for a given key (value) in the linked list
int search(Node* head, int key) {
    Node* current = head; // Start from the beginning
    int position = 1;  // Track the position of the node

    // Traverse the linked list
    while (current != NULL) {
        if (current->data == key) {
            return position; // Key found, return its position
        }
        current = current->next;
        position++;
    }

    return -1; // Key not found
}

int main() {
    Node* head = NULL; // Initially an empty list

    int num_elements, data;

    // Get the number of elements to insert from the user
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &num_elements);

    // Insert elements into the linked list based on user input
    for (int i = 0; i < num_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Created linked list: ");
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

    int position = search(head, key);

    if (position == -1) {
        printf("Key %d not found in linked list\n", key);
    } else {
        printf("Key %d found at position %d\n", key, position);
    }

    return 0;
}
