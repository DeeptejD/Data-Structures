#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX], prefix[MAX]; // define the stack and the three types
int top = -1;

// stack operations
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
    // remaining elements from the stack
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

// this is the int stack
int intstack[MAX];
int inttop = -1;

void intpush(int u)
{
    if (inttop == MAX - 1)
    {
        printf("int: Stack Overflow\n");
        exit(1);
    }
    intstack[++inttop] = u;
}

int intpop()
{
    if (inttop == -1)
    {
        printf("int: Stack underflow\n");
        exit(1);
    }
    return intstack[inttop--];
}

void evalpost(char postfix[])
{
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            intpush(postfix[i] - '0');
        else
        {
            int a, b, temp;
            a = intpop();
            b = intpop();
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
            case '^':
                temp = pow(b, a);
                break;
            }
            intpush(temp);
        }
    }
    if (inttop != 0)
        printf("Invalid expression\n");
    else
        printf("The value of postfix is: %d\n", intpop());
}

void toPrefix(char infix[], char prefix[])
{
    char reverse[strlen(infix)];
    int j = 0;
    for (int i = strlen(infix) - 1; i >= 0; i--)
        reverse[j++] = infix[i];
    for (int i = 0; i < strlen(reverse); i++)
    {
        if (reverse[i] == ')')
            reverse[i] = '(';
        else if (reverse[i] == '(')
            reverse[i] = ')';
    }
    char temppost[MAX];
    toPostfix(reverse, temppost);
    int p = 0;
    for (int i = strlen(temppost) - 1; i >= 0; i--)
    {
        prefix[p++] = temppost[i];
    }
    prefix[p] = '\0';
}

void evalprefix(char prefix[])
{
    inttop = -1; // just making sure i dont fuck up
    for (int i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (prefix[i] >= '0' && prefix[i] <= '9')
        {
            intpush(prefix[i] - '0');
        }
        else
        {
            int a, b, temp;
            a = intpop();
            b = intpop();
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
            case '^':
                temp = pow(a, b);
                break;
            }
            intpush(temp);
        }
    }
    if (inttop != 0)
        printf("Invalid expression\n");
    else
        printf("Prefix value: %d\n", intpop());
}

int main(int argc, char const *argv[])
{
    char infix[MAX], postfix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    toPostfix(infix, postfix);
    printf("The postfix: %s\n", postfix);
    evalpost(postfix);
    toPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    evalprefix(prefix);
    return 0;
}
