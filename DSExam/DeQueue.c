#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int dequeue[MAX_SIZE];
int front = -1, rear = -1;

void insertFront(int element) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1 && front != -1)) {
        printf("Dequeue Overflow! Cannot insert at front.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            front--;
        }
        dequeue[front] = element;
        printf("%d inserted at the front of the dequeue.\n", element);
    }
}


void deleteRear() {
    if (front == -1) {
        printf("Dequeue Underflow! Cannot delete from rear of an empty dequeue.\n");
    } else {
        printf("%d deleted from the rear of the dequeue.\n", dequeue[rear]);
        if (front == rear) {
            front = rear = -1;
        } else {
            rear--;
        }
    }
}

int main() {
    insertRear(5);
    insertRear(10);
    insertFront(15);

    deleteFront();
    deleteRear();

    insertFront(20);
    insertRear(25);

    return 0;
}
