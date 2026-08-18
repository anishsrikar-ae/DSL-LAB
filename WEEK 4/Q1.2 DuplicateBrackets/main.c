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

    stack->items[++stack->top] = item;
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
        return NULL;
    }
    return (stack->items[stack->top]);
}

int main()
{
    char str[100];
    struct Stack* stack = (struct stack*)malloc(sizeof(struct stack*));
    if(stack == NULL){
        printf("Stack failed!");
        return 0;
    }
    stack->top = -1;

    printf("Enter a String: ");
    gets(str);

    int length =0;
    while(*(str + length)!= '\0'){
        length++;
    }

    printf("\nPushing into Stack\n");
    int i = 0;
    while(*(str + i)!= '\0'){
        if (*(str+i) == '('){
            push(stack, *(str +i));
        }
        if (*(str+i)==')'){
            char temp = pop(stack);
        }
        i++;
    }
    char temp = peek(stack);
    if (temp == NULL){
        printf("All parenthesis are matched!\n");
    }else{
    printf("Unmatched parenthesis detected!");
    }

    return 0;
}
