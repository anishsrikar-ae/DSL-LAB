#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int c, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, Node** tail, int c, int e) {
    Node* newNode = createNode(c, e);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node *resHead = NULL, *resTail = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) append(&resHead, &resTail, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            append(&resHead, &resTail, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            append(&resHead, &resTail, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        append(&resHead, &resTail, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        append(&resHead, &resTail, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return resHead;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *p1Head = NULL, *p1Tail = NULL;
    Node *p2Head = NULL, *p2Tail = NULL;

    append(&p1Head, &p1Tail, 3, 3);
    append(&p1Head, &p1Tail, 5, 2);
    append(&p1Head, &p1Tail, 1, 0);

    append(&p2Head, &p2Tail, 2, 3);
    append(&p2Head, &p2Tail, 4, 1);
    append(&p2Head, &p2Tail, 1, 0);

    Node* sumHead = addPolynomials(p1Head, p2Head);

    printf("Polynomial 1: ");
    display(p1Head);
    printf("Polynomial 2: ");
    display(p2Head);
    printf("Sum: ");
    display(sumHead);

    return 0;
}


