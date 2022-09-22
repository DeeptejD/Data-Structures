#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX];
int top=-1;


void push(char c)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top]=c;
}

char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    char c = stack[top];
    top--;
    return c;
}

int isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

int precedence(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void toPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        if(isalnum(infix[i]))
            postfix[j++] = infix[i++];
        else if(infix[i] == '(')
            push(infix[i++]);
        else if(infix[i] == ')')
        {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop();
            i++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stack[top]))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while(top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    toPostfix(infix, postfix);
    printf("Postfix expression: %s", postfix);
    return 0;
}