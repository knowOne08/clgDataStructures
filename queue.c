#include<stdio.h>
#define SIZE 20
void enqueue();
void dequeue();
void show();
int inp_array[SIZE];
int rear = -1;
int front = -1;
int main(){
    int ch;
    while(1){
        printf("1. Enqueue Operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch (ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("Aree bhai value to sahi dal de");
        }
    }
    return 0;
}

void enqueue(){
    int item;
    if(rear == SIZE - 1)
        printf("Overflow");
    else {
        if(front == -1)
            front = 0;
        
        printf("Element to be inserted: ");
        scanf("%d",&item);
        rear = rear + 1;
        inp_array[rear] = item;
        
    }
}
void dequeue(){
    if(front == -1 || front > rear){
        printf("Unnderflow");
        return;    
    } else {
        printf("%d deleted\n", inp_array[front]);
        front = front + 1;
    }
}

void show(){
    if(front == -1)
        printf("Empty Queue");
    else {
        printf("Queue: ");
        for(int i = front; i <= rear; i++){
            printf("%d",i);
        }
        printf("\n");
    }
}