#include <stdio.h>
#include <stdlib.h>

struct Node{
    int element;
    struct Node* next;
    struct Node* prev;
};

struct Node* insertRear(struct Node* head, int element){
    struct Node* temp;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){printf("Allocation Failed!\n");exit(0);}
    newNode->element = element;
    if(head == NULL){
        head = newNode;
    }else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Enqueued %d at rear\n", newNode->element);
    return newNode;
}

struct Node* deleteRear(struct Node* head){
    if(head == NULL){printf("Queue is Empty!\n");exit(0);}
    struct Node* temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("Dequeued %d from rear\n", temp->element);
    struct Node* tail = temp->prev;
    free(temp);
    return tail;
}

void deletePosition(struct Node* head, int pos){
    if(head == NULL){printf("Queue is Empty!\n");exit(0);}
    struct Node* temp;
    int count = 0;
    temp = head;
    while (count < pos){
        if(temp->next == NULL){
            printf("Element Not found!\n");
            return 0;
        }
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL){
        temp->prev->next = NULL;
    }else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    printf("\nDeleted %d from pos %d\n", temp->element, count);
    free(temp);
}
void insertPosition(struct Node* head, int pos, int ele){
    if(head == NULL){printf("Queue is Empty!\n");exit(0);}
    struct Node* temp;
    temp = head;
    int count = 0;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){printf("Allocation Failed!\n");exit(0);}
    while(count<pos){
        if(temp->next == NULL){
            printf("Element Not found!\n");
            return 0;
        }
        temp = temp->next;
        count++;
    }
    newNode->element = ele;
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
    printf("inserted %d at %d pos\n", newNode->element, count);
}

void insertAfter(struct Node* head, int key, int ele){
    if (head == NULL){printf("Queue is Empty!\n"); exit(0);}
    int found = 0;
    struct Node* temp;
    temp = head;

    while(temp->next != NULL){
        temp = temp->next;
        if(temp->element == key){
            found = 1;
            break;
        }
    }
    if (found){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL){printf("Allocation Failed!\n");exit(0);}
        newNode->element = ele;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        printf("inserted %d after %d\n", newNode->element, temp->element);
    }else{
        printf("Element Not found!\n");
    }
}
void insertBefore(struct Node* head, int key, int ele){
    if (head == NULL){printf("Queue is Empty!\n"); exit(0);}
    int found = 0;
    struct Node* temp;
    temp = head;

    while(temp->next != NULL){
        temp = temp->next;
        if(temp->next->element == key){
            found = 1;
            break;
        }
    }
    if (found){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL){printf("Allocation Failed!\n");exit(0);}
        newNode->element = ele;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        printf("inserted %d before %d\n", newNode->element, key);
    }else{
        printf("Element Not found!\n");
    }
}
void displayFB(struct Node* head){
    if(head == NULL){printf("Queue is Empty!\n");exit(0);}
    struct Node* temp;
    temp = head;
    while(temp->next != NULL){
        printf("%d ", temp->element);
        temp = temp->next;
    }
    printf("%d ", temp->element);
}
void displayBF(struct Node* tail){
    if(tail == NULL){printf("Error!\n"); exit(0);}
    struct Node* temp;
    temp = tail;
    while(temp->prev != NULL){
        printf("%d ", temp->element);
        temp = temp->prev;
    }
    printf("%d ", temp->element);
}

int main()
{
    int choice = 0;
    int key, pos, element;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    do{
        printf("\n\nMenu\n");
        printf("1. insert rear\n");
        printf("2. Delete rear\n");
        printf("3. insert at position\n");
        printf("4. Delete at position\n");
        printf("5. insert after\n");
        printf("6. insert before\n");
        printf("7. Display F to B\n");
        printf("8. Display B to F\n");
        printf("0. Exit.\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("\nEnter Element: ");
            scanf("%d", &element);
            if (head == NULL){
                head = insertRear(head, element);
                tail = head;
            }else{
                tail = insertRear(head, element);
            }
            break;
        case 2:
            tail = deleteRear(head);
            break;
        case 3:
            printf("\nEnter Position to insert: ");
            scanf("%d", &pos);
            printf("Enter Element: ");
            scanf("%d", &element);
            insertPosition(head, pos, element);
            break;
        case 4:
            printf("\nEnter position to delete: ");
            scanf("%d", &pos);
            deletePosition(head, pos);
            break;
        case 5:
            printf("\nEnter Element to insert After: ");
            scanf("%d", &key);
            printf("Enter Element to insert: ");
            scanf("%d", &element);
            insertAfter(head, key, element);
            break;
        case 6:
            printf("\nEnter Element to insert before: ");
            scanf("%d", &key);
            printf("Enter Element to insert: ");
            scanf("%d", &element);
            insertBefore(head, key, element);
            break;
        case 7:
            displayFB(head);
            break;
        case 8:
            displayBF(tail);
            break;
        case 0:
            printf("\nSucessfully Exited.\n");
            break;
        }
    }while(choice != 0);
    return 0;
}
