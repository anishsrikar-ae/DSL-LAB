#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct details{
        char name[50];
        int age;
        int priority;
    };
struct Node{
    struct details* det;
    struct Node* next;
};

void printDetails(struct Node* d){
    printf("\nName: %s", d->det->name);
    printf("\nAge: %d", d->det->age);
    printf("\nPriority: %d\n\n", d->det->priority);
}

void enqueue(struct Node** que, struct details* det){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Failed!\n");
        return;
    }
    if (*que == NULL){
        newNode->det = det;
        newNode->next = NULL;
        *que = newNode;
        return;
    }
    struct Node* rear = *que;
    while(rear->next != NULL){
        rear = rear->next;
    }

    newNode->det = det;
    newNode->next = NULL;
    rear->next = newNode;
    printf("\nEnqueued Patient: \n");
    printDetails(newNode);
}

int dequeue(struct Node** que){
    if (*que == NULL){
        printf("Queue is Empty!\n");
        return 1;
    }
    struct Node* temp = *que;
    *que=(*que)->next;

    printf("\nDequeued Patient: \n");
    printDetails(temp);
    free(temp->det);
    free(temp);
    return 0;
}

int main()
{
    struct Node* queue = NULL;

    int i = 1;
    do{
        struct details* det = (struct details*)malloc(sizeof(struct details));
        printf("Enter Patient Name: ");
        scanf("%s", det->name);
        printf("Enter Patient Age: ");
        scanf("%d", &det->age);
        printf("Enter Patient Priority: ");
        scanf("%d", &det->priority);
        enqueue(&queue, det);
        printf("Would you like to enqueue(1/0)?: ");
        scanf("%d", &i);
    }while(i == 1);

    int res = 0;

    while(res == 0){
        res = dequeue(&queue);
    }
    return 0;
}
