#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int cqueue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int element) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1 && front != -1)) {
        printf("Circular Queue Overflow! Cannot enqueue element %d.\n", element);
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        cqueue[rear] = element;
        printf("%d enqueued into the circular queue.\n", element);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Circular Queue Underflow! Cannot dequeue from an empty circular queue.\n");
    } else {
        printf("%d dequeued from the circular queue.\n", cqueue[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
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
