#include<stdio.h>
#include<stdlib.h>
#define size 5

struct stack {
    int a[size],top;
    int temp[size];
}s;

void push(){
    int value;
    printf("Enter value to be pushed: ");
    scanf("%d",&value);
    s.top = s.top+1;
    s.a[s.top] = value;
}

void pop(){
    printf("Popped element is %d\n",s.a[s.top]);
    s.top = s.top-1;
}

void peep(){
    printf("Value at top postion is %d",s.a[s.top]);
}

void display(){
    for(int i=s.top; i>=0; i--){
        printf("\t%d",s.a[i]);
    }
}

void change(int index,int new_element){
    int  i,j=-1;
    for(i=s.top;i>index;i--){
        s.temp[++j] = s.a[s.top--];
    }
    s.a[s.top]= new_element;
    for(i=j;i>-1;i--){
        s.a[++s.top] = s.temp[j--];
    }
}

int main() {
    s.top=-1;
    int choice,index,new_element;
    do{
        printf("\n Stack implemention Program");
        printf("\n1. PUSH 2. POP 3. PEEP 4. CHANGE 5. DISPLAY 0. EXIT\n");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                if(s.top == size-1){
                    printf("\t Stack Overflow\n");
                } else {
                    push();
                }
                break;
            case 2:
                if(s.top == -1){
                    printf("\t Stack Underflow \n");
                } else {
                    pop();
                }
                break;
            case 3:
                printf("Enter index no: ");
                scanf("%d",&index);
                if(index<0 || index>s.top){
                    printf("\tInvalid index number: ");
                    scanf("%d",&new_element);
                    change(index,new_element);
                }
                break;
            case 5:
                if(s.top==-1){
                    printf("\t Stack is empty.\n");
                } else {
                    display();
                }
                break;
            case 0:
                printf("\tEnd of Program\n");
                break;
            default :
                printf("\tINVALID CHOICE\n");
            
        }
    } while(choice != 0);

    return 0;
}