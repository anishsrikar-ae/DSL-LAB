#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack{
    int items[MAX];
    int top;
};

void push(struct Stack* stack, char item){
    if (stack->top==MAX-1){
        printf("Stack Overflow!\n");
        return 1;
    }
    stack->top += 1;
    stack->items[stack->top] = item;
    printf("\nPushed %c onto Stack\n", item);
    return 0;
}
char pop(struct Stack* stack){
    if(stack->top == -1){
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped %c\n", stack->items[stack->top]);
    return stack->items[stack->top--];
}

char peek(struct Stack* stack){
    if (stack->top == -1){
        printf("Stack is Empty!\n");
    }
    return (stack->items[stack->top]);
}

int compareStacks(struct Stack* s1, struct Stack* s2){
    if (s1->top != s2->top){
        printf("Stacks are not Equal\n");
        return 0;
    }
    while(s1->top != -1 && s2->top != -1){
        if (peek(s1) != peek(s2)){
            printf("Stacks are not Equal!\n");
            return 0;
        }
        pop(s1);
        pop(s2);
    }
    printf("Both Stacks are Equal!\n");
    return 1;
}



int main()
{
    char str[100];
    char revstr[100];
    struct Stack* stack1 = (struct stack*)malloc(sizeof(struct stack*));
    struct Stack* stack2 = (struct stack*)malloc(sizeof(struct stack*));
    if(stack1 == NULL || stack2 == NULL){
        printf("Stack failed!");
        return 0;
    }

    stack1->top = -1;
    stack2->top = -1;

    printf("Enter a String: ");
    gets(str);

    int length =0;
    while(*(str + length)!= '\0'){
        length++;
    }

    printf("\nPushing into Stack1\n");
    int i = 0;
    while(*(str + i)!= '\0'){
        push(stack1, *(str +i));
        *(revstr+(length-i-1)) = *(str+i);
        i++;
    }
    *(revstr+i) = '\0';

    printf("\n\nPushing into Stack2\n\n");
    i =0;
    while(*(revstr + i)!= '\0'){
        push(stack2, *(revstr +i));
        i++;
    }

    printf("\n\nBoth Strings pushed onto Stack!\n");

    int res = compareStacks(stack1, stack2);

    return 0;
}
