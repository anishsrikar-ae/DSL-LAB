#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

void insertAfter(struct Node** q, int element, int target){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = NULL;

    struct Node* temp = *q;

    while(temp != NULL && temp->value != target){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Target not found");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Successfully inserted %d after: %d", newNode->value, temp->value);
}

void insertBefore(struct Node** q, int element, int target){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = NULL;

    if(*q == NULL){
        *q = newNode;
        return;
    }

    if((*q)->value == target){
        newNode->next = *q;
        *q = newNode;
        printf("Successfully inserted %d before: %d", newNode->value, target);
        return;
    }

    struct Node* temp = *q;

    while(temp->next != NULL && temp->next->value != target){
        temp = temp->next;
    }

    if(temp->next == NULL){
        printf("Target not found");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Successfully inserted %d before: %d", newNode->value, target);
}

void deleteElement(struct Node** q, int element){
    if(*q == NULL){
        printf("List is empty");
        return;
    }

    struct Node* temp = *q;

    if(temp->value == element){
        *q = temp->next;
        free(temp);
        printf("Successfully Deleted %d", element);
        return;
    }

    while(temp->next != NULL && temp->next->value != element){
        temp = temp->next;
    }

    if(temp->next == NULL){
        printf("Element not found");
        return;
    }

    struct Node* temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);

    printf("Successfully Deleted %d", element);
}

void displayElements(struct Node* q){
    struct Node* temp = q;

    if(temp == NULL){
        printf("List is empty");
        return;
    }

    printf("%d", temp->value);

    while(temp->next != NULL){
        temp = temp->next;
        printf(" -> %d", temp->value);
    }
}

void reverseList(struct Node** q){
    struct Node* prev = NULL;
    struct Node* temp = *q;
    struct Node* next;

    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    *q = prev;

    printf("\nReversed List: ");
    displayElements(*q);
}

void sortList(struct Node* q){
    struct Node* temp;
    struct Node* count = q;

    if(q == NULL || q->next == NULL){
        printf("\nSorted List: ");
        displayElements(q);
        return;
    }

    while(count != NULL){
        temp = q;

        while(temp->next != NULL){
            if(temp->value > temp->next->value){
                int temp2 = temp->value;
                temp->value = temp->next->value;
                temp->next->value = temp2;
            }

            temp = temp->next;
        }

        count = count->next;
    }

    printf("\nSorted List: ");
    displayElements(q);
}

void deleteAlternate(struct Node* q){
    struct Node* temp = q;

    if(temp == NULL){
        return;
    }

    while(temp != NULL && temp->next != NULL){
        struct Node* temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
        temp = temp->next;
    }

    printf("\nafter deleting alternate elements: ");
    displayElements(q);
}

void insertSorted(struct Node** q, int ele){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = ele;
    newNode->next = NULL;

    if(*q == NULL){
        *q = newNode;
        printf("\nSuccessfully entered into sorted list: ");
        displayElements(*q);
        return;
    }

    if(ele <= (*q)->value){
        newNode->next = *q;
        *q = newNode;

        printf("\nSuccessfully entered into sorted list: ");
        displayElements(*q);
        return;
    }

    struct Node* temp = *q;

    while(temp->next != NULL && temp->next->value <= ele){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("\nSuccessfully entered into sorted list: ");
    displayElements(*q);
}

int main()
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    q->next = NULL;

    printf("Enter Head value: ");
    scanf("%d", &q->value);

    int i = -1;

    do{
        printf("\n\nMenu: \n");
        printf("\n 1. Insert before");
        printf("\n 2. Insert after");
        printf("\n 3. delete");
        printf("\n 4. display List");
        printf("\n 5. Reverse List");
        printf("\n 6. Sort List");
        printf("\n 7. Delete Alternate Nodes");
        printf("\n 8. Insert Sorted");
        printf("\n 0. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &i);

        int ele, target;

        switch(i){

            case 1:
                printf("\nEnter Element: ");
                scanf("%d", &ele);

                printf("\nEnter target: ");
                scanf("%d", &target);

                insertBefore(&q, ele, target);
                break;

            case 2:
                printf("\nEnter Element: ");
                scanf("%d", &ele);

                printf("\nEnter target: ");
                scanf("%d", &target);

                insertAfter(&q, ele, target);
                break;

            case 3:
                printf("\nEnter Element: ");
                scanf("%d", &ele);

                deleteElement(&q, ele);
                break;

            case 4:
                printf("\nList: ");
                displayElements(q);
                break;

            case 5:
                reverseList(&q);
                break;

            case 6:
                sortList(q);
                break;

            case 7:
                deleteAlternate(q);
                break;

            case 8:
                printf("\nEnter Element: ");
                scanf("%d", &ele);

                insertSorted(&q, ele);
                break;

            case 0:
                break;

            default:
                printf("\nInvalid Choice");
        }

    }while(i != 0);

    return 0;
}
