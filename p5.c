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

// Structure to represent the stack
typedef struct Stack {
    Node* head; // Top of the stack (points to the most recently added element)
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->head == NULL;
}

// Function to push (insert) an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = newNode(data);
    new_node->next = stack->head;
    stack->head = new_node;
    printf("%d pushed to stack\n", data);
}

// Function to pop (remove) an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Indicate error or empty stack
    }
    Node* temp = stack->head;
    int popped_data = temp->data;
    stack->head = stack->head->next;
    free(temp);
    printf("%d popped from stack\n", popped_data);
    return popped_data;
}

// Function to peek at the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Indicate error or empty stack
    }
    return stack->head->data;
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", peek(stack));

    pop(stack);
    pop(stack);
    pop(stack); // Try to pop from empty stack (handled in pop function)

    return 0;
}
/*
Explanation:

We avoid using global variables like in the array queue example and rely solely on passing the stack state (represented by a pointer to the top node) as arguments to functions.
EmptyStack function creates and returns a NULL pointer representing an empty stack.
Push creates a new node, sets its next to the current top (stack), and returns the new node as the updated top of the stack.
Pop checks for an empty stack. If not empty, it removes the top element and returns the updated stack.
Peek accesses the top element's data without modifying the stack.
main demonstrates usage by creating an empty stack, pushing elements, peeking, popping, and handling the empty stack case.
*/