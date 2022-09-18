#include<stdio.h>
#include<stdlib.h>
#define MAX 100

char stack[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1)
        return 1;
    return 0;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}

void push(char c)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top]=c;
}

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    top--;
}

int isSame(char expression[]){
    if(expression[0]=='\0')
    {
        printf("Expression is empty\n");
        exit(1);
    }
    for(int i=0;expression[i]!='\0';i++){
        if(expression[i]=='(')
            push('(');
        if(expression[i]==')')
            pop();
    }
    if(top==-1) return 1;
    else return 0;
}

int main(int argc, char const *argv[])
{
    char expression[MAX];
    printf("Enter expression: ");
    gets(expression);
    if(isSame(expression))
        printf("Parenthesis balanced\n");
    else
        printf("Parenthesis not balanced\n");
    return 0;
}
