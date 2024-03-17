// To implement queue using linked list.
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

// Structure to represent the queue
typedef struct Queue {
    Node* front; // Pointer to the front node (first element to be dequeued)
    Node* rear;  // Pointer to the rear node (last element enqueued)
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue (insert) an element into the queue
void enqueue(Queue* queue, int data) {
    Node* new_node = newNode(data);
    if (isEmpty(queue)) { // Handle the first element being enqueued
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Indicate error or empty queue
    }
    Node* temp = queue->front;
    int dequeued_data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) { // Queue becomes empty after dequeue
        queue->rear = NULL;
    }
    free(temp);
    printf("%d dequeued from queue\n", dequeued_data);
    return dequeued_data;
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue)); // Try to dequeue from empty queue (handled in dequeue function)

    return 0;
}
/*
Node: Same structure as in the previous examples, storing data and a pointer to the next node.
Queue: A new structure named Queue is defined, containing two pointers:
front: Points to the first element (front) of the queue.
rear: Points to the last element (rear) of the queue.
createQueue: Creates a new Queue by allocating memory and initializing both front and rear to NULL.
isEmpty: Checks if both front and rear pointers are NULL, indicating an empty queue.
enqueue: Creates a new node, handles the first element insertion by assigning it to both front and rear, and otherwise appends it to the end using rear->next.
dequeue: Checks for an empty queue. If not empty, removes the front element by storing its data, updating front to point to the next element, and handling the case where the queue becomes empty after dequeue.
main: Demonstrates usage by creating a queue, enqueueing elements, dequeueing, and handling the empty queue case.
*/