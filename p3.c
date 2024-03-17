#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1, n; // n is the size of the queue

void enqueue(int x) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue overflow\n");
        return;
    }

    // Handle the first element being enqueued
    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE; // Circular increment
    queue[rear] = x;
    printf("Inserted element: %d\n", x);
}

void dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
        return;
    }

    printf("Dequeued element: %d\n", queue[front]);

    if (front == rear) {  // Queue becomes empty after dequeue
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE; // Circular increment
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        // Print elements from front to rear
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        // Wrap around for printing (front > rear)
        for (int i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    printf("Enter the size of the circular queue (MAX=%d): ", MAX_SIZE);
    scanf("%d", &n);

    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
/*
MAX_SIZE: Defines the maximum size of the queue.
queue: Array to store queue elements.
front and rear: Pointers for the front and rear of the queue.
n: Size of the queue used (can be less than MAX_SIZE).
enqueue: Adds an element to the rear of the queue using circular increment with modulo operation (%).
dequeue: Removes an element from the front of the queue and handles the case where the queue becomes empty.
display: Prints the elements of the queue, handling the case where front is greater than rear due to circular nature.
main: Provides a menu-driven interface for enqueue, dequeue, display, and exit operations.
*/