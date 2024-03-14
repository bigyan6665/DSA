#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent a circular queue
struct CircularQueue {
    int front, rear;
    int arr[MAX_SIZE];
};

// Function to initialize a circular queue
void initializeQueue(struct CircularQueue* queue) {
    queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return ((queue->front == 0 && queue->rear == MAX_SIZE - 1) ||
            (queue->rear == (queue->front - 1) % (MAX_SIZE - 1)));
}

// Function to add an element to the rear of the queue
void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = item;

    printf("%d enqueued to the queue.\n", item);
}

// Function to remove an element from the front of the queue
int dequeue(struct CircularQueue* queue) {
    int item;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    item = queue->arr[queue->front];

    if (queue->front == queue->rear)
        initializeQueue(queue);
    else
        queue->front = (queue->front + 1) % MAX_SIZE;

    return item;
}

// Function to display the elements in the queue
void display(struct CircularQueue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue are: ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
        printf("%d ", queue->arr[i]);

    printf("%d\n", queue->arr[i]);
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    display(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));

    display(&queue);

    return 0;
}
