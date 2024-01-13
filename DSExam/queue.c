#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow! Cannot enqueue element %d.\n", element);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("%d enqueued into the queue.\n", element);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);

    dequeue();
    dequeue();

    enqueue(20);
    enqueue(25);

    return 0;
}
