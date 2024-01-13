#include <stdio.h>
struct student
{
    char name[5];
    int rollNo;
    int mathsMarks;
    int dfMarks;
    int dbmsMarks;
    int etcMarks;
    int dsMarks;
};

int main(){
    int i;
    struct student s[3];
    for ( i = 0 ; i < 3; i++)
    {
        printf("enter details: \n");
        printf("name: \n");
        scanf("%s", s[i].name );
        printf("rollno: \n");
        scanf("%d", &s[i].rollNo );
        printf("mathsMark: \n");
        scanf("%d", &s[i].mathsMarks );
        printf("dfmarks: \n");
        scanf("%d", &s[i].dfMarks);
        printf("dbms: \n");
        scanf("%d", &s[i].dbmsMarks );
        printf("etc: \n");
        scanf("%d", &s[i].etcMarks);
        printf("ds: \n");
        scanf("%d", &s[i].dsMarks);

    }

    for ( i = 0; i < 3; i++)
    {
        printf("details : \n");
        printf("    Name: %s\n",s[i].name);
        printf("    Rollno: %d\n", s[i].rollNo);
        printf("    DBMS: %d\n", s[i].dbmsMarks);
        printf("    df: %d\n", s[i].dfMarks);
        printf("    ds: %d\n", s[i].dsMarks);
        printf("    maths: %d\n", s[i].mathsMarks);
        printf("    etc: %d\n", s[i].etcMarks);
    }
    
    
    return 0;
}