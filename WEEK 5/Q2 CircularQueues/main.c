#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct queue{
    int item[MAX];
    int front;
    int rear;
};

void enqueue(struct queue *que, int item){
    if ((que->rear+1)%MAX == que->front){
        printf("Queue is full!\n");
        return;
    }
    if (que->front == -1){
        que->front = 0;
        que->rear = 0;
    }else{
        que->rear = (que->rear + 1)%MAX;
    }
    que->item[que->rear] = item;
    printf("Enqueued %d Successfuly!\n", item);

}

int dequeue(struct queue *que){
    if (que->front == -1){
        printf("\n\nQueue is Empty!\n");
        return 1;
    }
    printf("\nDequeued Item!");
    printf("\nItem: %d", que->item[que->front]);
    if (que->front == que->rear){
        que->front = -1;
        que->rear = -1;
    }else{
        que->front = (que->front+1)%MAX;
    }
    return 0;
}


int main()
{

    struct queue *que = (struct queue*)malloc(sizeof(struct queue));
    que->front =-1;
    que->rear = -1;
    int i = 1;
    int item;
    do{
        printf("\nEnter item: ");
        scanf("%d", &item);
        enqueue(que,item);
        printf("\nWould you like to enqueue(1/0)?: ");
        scanf("%d", &i);
    }while(i == 1);

    int res = 0;

    while(res == 0){
        res = dequeue(que);
    }

    return 0;
}
