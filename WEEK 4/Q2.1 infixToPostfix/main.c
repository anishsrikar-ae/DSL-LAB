#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct Node {
    char value;
    struct Node* next;
};
struct Node* top = NULL;
char pop(){
    if (top ==NULL){
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("%c popped \n", top->value);
    top = top->next;
    int value = temp->value;
    free(temp);
    return value;
}

void push(char data){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    if (!NewNode){
        printf("\n\nFailed!\n\n");
        return;
    }

    NewNode->value = data;
    NewNode->next = top;
    top = NewNode;
    printf("%c Pushed\n", data);
}

char peek(){
    if (top == NULL){
        printf("Stack is Empty!\n");
        return;
    }
    printf("Top element %c\n", top->value);
}
int precedence(char op){
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
int IsOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int IsOperand(char c){
    return ((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z') ||(c >= '0' && c <= '9'));
}
int hasHigherOrEqualPrecedence(char op1, char op2){
    int p1 = precedence(op1);
    int p2 = precedence(op2);
    if (p1 == p2) {
        if (op1 == '^'){
            return 0;
        return 1;
    }
    return (p1 > p2);
    }
}
void convert(char infix[], char postfix[]){
    char stack[MAX_SIZE];
    int top = -1, i = 0, j = 0;
    char ch;
    stack[++top] = '(';
    strcat(infix, ")");
    while ((ch = infix[i++]) != '\0') {
        if (ch == ' ')
            continue;
        else if (ch == '(')
            stack[++top] = ch;
        else if (IsOperand(ch))
            postfix[j++] = ch;
        else if (IsOperator(ch)) {
            while (top != -1 && hasHigherOrEqualPrecedence(stack[top], ch))
                postfix[j++] = stack[top--];
                stack[++top] = ch;
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
            postfix[j++] = stack[top--];
            top--;
            postfix[j] = '\0';
        }
}
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int ch;
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    convert(infix, postfix);
    printf("\nInfix : %s", infix);
    printf("\nPostfix : %s", postfix);
    return 0;

}
