#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void concatenate(struct Node** X1, struct Node** X2) {
    if (*X1 == NULL) {
        *X1 = *X2;
        *X2 = NULL;
        return;
    }
    if (*X2 == NULL) return;

    struct Node* temp = *X1;
    while (temp->next != NULL) temp = temp->next;

    temp->next = *X2;
    (*X2)->prev = temp;
    *X2 = NULL;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* X1 = NULL;
    struct Node* X2 = NULL;

    insertEnd(&X1, 10);
    insertEnd(&X1, 20);

    insertEnd(&X2, 30);
    insertEnd(&X2, 40);

    concatenate(&X1, &X2);

    printList(X1);

    return 0;
}
