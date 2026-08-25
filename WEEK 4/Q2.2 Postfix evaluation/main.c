#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int evaluate(char postfix[]){
        int i = 0;
        char ch;
        int op1, op2;

        while ((ch = postfix[i++])!= '\0'){
            if(isdigit(ch)){
                push(ch-'0');
            }else{
                op2 = pop();
                op1 = pop();
            }

            switch(ch){
            case '+':
                push(op1+op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1*op2);
                break;
            case '/':
                push(op1/op2);
                break;
            case '^':{
                int result = 1;
                for(int j = 0; j<op2; j++)
                    result*=op1;
                    push(result);
                    break;
            }
            }

        }
        return pop();
}


int main()
{

    char postfix[MAX_SIZE];
    printf("Enter a postfix Expression: ");
    scanf("%s", postfix);
    printf("Result: %d\n", evaluate(postfix));
    return 0;
}
