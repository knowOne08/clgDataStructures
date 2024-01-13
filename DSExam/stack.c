#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push element %d.\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed onto the stack.\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty. Cannot peek.\n");
    } else {
        printf("Top element of the stack: %d\n", stack[top]);
    }
}

int main() {
    push(5);
    push(10);
    push(15);

    peek();

    pop();
    pop();

    peek();

    pop(); 

    return 0;
}
