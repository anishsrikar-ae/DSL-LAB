#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollno;
    char grade;
};

void read(struct Student* s){

    printf("\nEnter Name: ");
    scanf("%s", &s->name);

    printf("\nEnter Roll No: ");
    scanf("%d",&s->rollno);

    printf("\nEnter Grade: ");
    scanf(" %c",&s->grade);
}

void display(struct Student* s){
    printf("\n\nName: ");
    puts(s->name);
    printf("Roll No: %d", s->rollno);
    printf("\nGrade: %c", s->grade);
}

void sortStruct(struct Student* s, int n){

    for(int i=0; i<n; i++){
        for(int j=i; j<n-1; j++){
            if ((s+j)->rollno >= (s+j+1)->rollno){
                struct Student temp = *(s+j);
                *(s+j) = *(s+j+1);
                *(s+j+1) = temp;
            }
        }
    }
    printf("\n\nSorted: ");
    for(int i=0; i<n; i++){
        display(s+i);
    }

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
    sortStruct(s,n);
    return 0;
}
