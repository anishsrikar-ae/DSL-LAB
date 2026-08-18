#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollno;
    int marks;
};

void read(struct Student* s){

    printf("\nEnter Name: ");
    scanf("%s", &s->name);

    printf("\nEnter Roll No: ");
    scanf("%d",&s->rollno);

    printf("\nEnter Marks: ");
    scanf(" %d",&s->marks);
}

void display(struct Student* s){
    printf("\n\nName: ");
    puts(s->name);
    printf("Roll No: %d", s->rollno);
    printf("\nMarks: %d", s->marks);
}

void findHighest(struct Student* s, int n){

    struct Student highest = *s;

    for(int i=0; i<n; i++){
        if (highest.marks <= (s+i)->marks){
            highest = *(s+i);
        }
    }
    printf("Best Student: ");
    display(&highest);
}


int main()
{
    int n;

    printf("Enter Number of Students: ");
    scanf("%d", &n);
    struct Student s[n];

    printf("\n\nEnter Student Details: ");
    for(int i=0; i<n; i++){
        read(s+i);
        display(s+i);
    }
    findHighest(s,n);
    return 0;
}
