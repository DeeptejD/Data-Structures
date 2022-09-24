#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX], prefix[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = c;
}

char pop()
{
    if (top == -1)
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
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void toPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i++];
        else if (infix[i] == '(')
            push(infix[i++]);
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stack[top]))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

void toPrefix(char infix[], char prefix[])
{
    char reverse[strlen(infix)];
    int r = 0;
    // reverse infix
    for (int i = strlen(infix) - 1; i >= 0; i--)
    {
        reverse[r++] = infix[i];
    }
    // make ( as ) and vice versa
    for (int i = 0; i < strlen(reverse); i++)
    {
        if (reverse[i] == '(')
            reverse[i] = ')';
        else if (reverse[i] == ')')
            reverse[i] = '(';
    }
    // convert to postfix form
    toPostfix(reverse, postfix);
    int p = 0;
    for (int i = strlen(postfix) - 1; i >= 0; i--)
    {
        prefix[p++] = postfix[i];
    }
    prefix[p] = '\0';
}

void evalPostfix(char postfix[])
{
    int tmpstack[MAX], ttop = -1;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            tmpstack[++ttop] = postfix[i] - '0';
        }
        else
        {
            int a, b, temp;
            a = tmpstack[ttop--];
            b = tmpstack[ttop--];
            switch (postfix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = pow(b, a);
                break;
            }
            tmpstack[++ttop] = temp;
        }
    }
    printf("The value of the postfix expression is: %d\n", tmpstack[ttop]);
}

void evalPrefix(char prefix[])
{
    int tmpstack[MAX], ttop = -1;
    for (int i = strlen(prefix) - 1; i>=0; i--)
    {
        if (prefix[i] >= '0' && prefix[i] <= '9')
        {
            tmpstack[++ttop] = prefix[i] - '0';
        }
        else
        {
            int a, b, temp;
            a = tmpstack[ttop--];
            b = tmpstack[ttop--];
            switch (prefix[i])
            {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case '*':
                temp = a * b;
                break;
            case '/':
                temp = a / b;
                break;
            case '%':
                temp = a % b;
                break;
            case '^':
                temp = pow(a, b);
                break;
            }
            tmpstack[++ttop] = temp;
        }
    }
    printf("The value of the prefix expression is: %d\n", tmpstack[ttop]);
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    int choice;
    while (1)
    {
        printf("1.Infix to postfix\n2.Infix to prefix\n3.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            toPostfix(infix, postfix);
            printf("Postfix expression: %s\n", postfix);
            evalPostfix(postfix);
            break;
        case 2:
            toPrefix(infix, prefix);
            printf("Prefix expression: %s\n", prefix);
            evalPrefix(prefix);
            break;
        case 3:
            exit(1);
        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}
