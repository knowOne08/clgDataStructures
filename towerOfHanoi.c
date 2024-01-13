#include<stdio.h>
void move(int n, char x, char y, char z){
    if(n>0){
        move(n-1,x,z,y);
        printf("Moving disk %d from %c to %c\n",n,x,y);
        move(n-1,z,y,x);
    }
}   

int main(){
    int n=2;
    move(n,'A','B','C');
    return 0;
}