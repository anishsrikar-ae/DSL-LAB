#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct queue{
    int id[MAX];
    char name[MAX][50];
    int front;
    int rear;
};

void enqueue(struct queue *que, int id, char name[]){
    if (que->rear == MAX-1){
        printf("Queue is full!\n");
        return;
    }
    if (que->front == -1){
        que->front++;
    }
    que->rear++;
    que->id[que->rear] = id;
    strcpy(que->name[que->rear], name);
    printf("Enqueued Successfuly!\n");
}

int dequeue(struct queue *que){
    if (que->front == -1 && que->rear == -1){
        printf("\nQueue is Empty!\n");
        return 1;
    }
    printf("\nDequeued document!\n");
    printf("Name: %s", que->name[que->front]);
    printf("\nid: %d", que->id[que->front]);
    if (que->front == que->rear){
        que->front = -1;
        que->rear = -1;

    }else{
        que->front++;
    }
    return 0;
}


int main()
{

    struct queue *que = (struct queue*)malloc(sizeof(struct queue));
    que->front=-1;
    que->rear=-1;
    int i = 1;
    int id;
    char name[MAX];
    do{
        printf("Enter Document id: ");
        scanf("%d", &id);
        printf("Enter Document Name: ");
        scanf("%s", name);
        enqueue(que,id, name);
        printf("Would you like to enqueue(1/0)?: ");
        scanf("%d", &i);
    }while(i == 1);

    int res = 0;

    while(res == 0){
        res = dequeue(que);
    }

    return 0;
}
