#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* ptr, int first){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    int ele;
    printf("\nEnter Element: ");
    scanf("%d", &ele);
    newNode->data = ele;

    if (ptr == NULL){
        return newNode;
    }

    if (first){
        struct Node* temp = ptr;
        while(temp->next != ptr){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next =newNode;
        return ptr;
    }else{
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr = newNode;
        return ptr;
    }
}

struct Node* deleteNode(struct Node* ptr){
    if (!ptr){printf("List is Empty"); exit(0);}
    struct Node* temp = ptr;
    while(temp->next!=ptr){
        temp = temp->next;
    }
    temp->next = ptr->next;
    printf("\ndeleted %d from list.\n", ptr->data);
    free(ptr);
    if (temp->next == NULL){return NULL;}
    return temp;
}

void display(struct Node* head){
    struct Node* temp = head;
    if (!head){printf("\nList is Empty!\n"); return;}
    while(temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int main()

{
    int choice = 0;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    do {
        printf("\nMenu: \n1.Insert at end using first.\n2.Insert at end using last.\n3.Delete at end using first.\n");
        printf("4.deletion at end using last\n5.display\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            head = insertEnd(head, 1);
            if (tail == NULL) {tail = head;head->next = tail;}
            display(head);
            break;
        case 2:
            tail = insertEnd(tail, 0);
            if (head == NULL){head = tail; tail->next = head;}
            display(head);
            break;
        case 3:
            head = deleteNode(head);
            display(head);
            if (!head){tail = head;}
            break;
        case 4:
            tail = deleteNode(tail);
            if (!tail){head = tail;}
            display(head);
            break;
        case 5:
            display(head);
            break;
        default:
            printf("Invalid Input.\n");
            break;
        }
    }while(choice != 0);


    return 0;
}
