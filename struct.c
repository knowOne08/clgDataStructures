#include<stdio.h>
#include<string.h>

struct student {
    char name[20];
    int rollNo;
    int marks;
};

int main() {
    struct student meet;
    struct student *meetptr;
    meetptr = &meet;
    
    strcpy((*meetptr).name, "Meet");

    meetptr->rollNo = 30;
    meetptr->marks = 70;
    
    // strcpy(abhi.name, "Abhi");
    // strcpy(yash.name, "Yash");


    printf("Details of Student 1:\n");
    printf("\tName : %s\n", meetptr->name);
    printf("\tRollNo : %d\n", meetptr->rollNo);
    printf("\tMarks: %d\n", meetptr->marks);

    return 0;
}