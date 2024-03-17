// To implement queue using array
#include <stdio.h>

int queue[100], choice, n, front = -1, rear = -1, x;

void enqueue(void);
void dequeue(void);
void display(void);

int main() {
    front = rear = -1;
    printf("\nEnter the size of QUEUE (MAX=100):");
    scanf("%d", &n);

    printf("\n\tQUEUE OPERATIONS USING ARRAY\n");
    printf("\t--------------------------------\n");
    printf("\t1. ENQUEUE\n");
    printf("\t2. DEQUEUE\n");
    printf("\t3. DISPLAY\n");
    printf("\t4. EXIT\n");

    do {
        printf("\nEnter the Choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tEXIT POINT\n");
                break;
            default:
                printf("\n\tPlease Enter a Valid Choice (1/2/3/4)\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue() {
    if (rear == n - 1) {
        printf("\n\tQUEUE is overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("Enter a value to be enqueued:");
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1) {
        printf("\n\tQUEUE is underflow\n");
    } else {
        printf("\n\tThe dequeued element is %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nQUEUE is Empty\n");
    } else {
        printf("\nQUEUE elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
/*
Key differences from the stack implementation:

Front and rear: Uses both front and rear pointers for enqueue and dequeue operations.
Enqueue: Adds elements at the rear of the queue.
Dequeue: Removes elements from the front of the queue.
Empty queue check: Uses front == -1 instead of top <= -1.
Overflow check: Uses rear == n - 1 instead of top >= n - 1.
Underflow check: Same as in the stack implementation.
Display: Prints elements from front to rear.
*/