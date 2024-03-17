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

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a node after a given node
void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
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

// Function to delete a node by its given key (value)
void deleteNode(Node** head_ref, int key) {
    // Handle empty list
    if (*head_ref == NULL) return;

    // Store the head node
    Node* temp = *head_ref;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            // Found the key. Now delete the next node
            Node* next = temp->next->next;
            free(temp->next);
            temp->next = next;
            return;
        }
        temp = temp->next;
    }

    // If key was not present in linked list
    printf("Key %d not found in linked list\n", key);
}

// Function to traverse the linked list and print its contents
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to check if the linked list is empty
int isEmpty(Node* head) {
    return head == NULL;
}

int main() {
    Node* head = NULL;

    // Inserting elements at the beginning
    insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 1);
    printf("Linked list before insertion: ");
    printList(head);

    // Inserting a node after the node with value 6
    insertAfter(head->next, 5);
    printf("Linked list after insertion after 6: ");
    printList(head);

    // Inserting a node at the end
    insertAtEnd(&head, 9);
    printf("Linked list after insertion at end: ");
    printList(head);

    // Deleting node with value 12
    deleteNode(&head, 12);
    printf("Linked list after deletion of 12: ");
    printList(head);

    // Check if the list is empty
    if (isEmpty(head)) {
        printf("Linked list is empty.\n");
    } else {
        printf("Linked list is not empty.\n");
    }

    return 0;
}
